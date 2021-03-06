// Copyright 2008-2018 Yolo Technologies, Inc. All Rights Reserved. https://www.comblockengine.com

#include <iterator>
#include "entity_coordinate_node.h"
#include "entity.h"
#include "coordinate_system.h"
#include "range_trigger_node.h"

namespace KBEngine{	


//-------------------------------------------------------------------------------------
class CoordinateNodeWrapX
{
public:
	CoordinateNodeWrapX(CoordinateNode* node, const Position3D& originPos) :
		pNode_(node),
		pCurrentNode_(node),
		originPos_(originPos) {}

	INLINE void reset() { pCurrentNode_ = pNode_; }
	INLINE bool isEntityNode() const { return pCurrentNode_->hasFlags(COORDINATE_NODE_FLAG_ENTITY); }
	INLINE bool valid() const { return !pCurrentNode_->hasFlags(COORDINATE_NODE_FLAG_HIDE_OR_REMOVED); }
	INLINE CoordinateNode* currentNode() const { return pCurrentNode_; }
	INLINE Entity* currentNodeEntity() const { return static_cast<EntityCoordinateNode*>(pCurrentNode_)->pEntity(); }
	
	INLINE CoordinateNode* prev() {
		pCurrentNode_ = pCurrentNode_->pPrevX();
		return pCurrentNode_;
	}

	INLINE CoordinateNode* next() {
		pCurrentNode_ = pCurrentNode_->pNextX();
		return pCurrentNode_;
	}

	INLINE int compare() {
		float v = currentNodeEntity()->position().x;
		if (v == originPos_.x)
			return 0;
		else if (v > originPos_.x)
			return 1;
		else
			return -1;
	}

	INLINE float length() {
		return fabs(currentNodeEntity()->position().x - originPos_.x);
	}

protected:
	CoordinateNode* pNode_;
	CoordinateNode* pCurrentNode_;
	const Position3D& originPos_;
};

class CoordinateNodeWrapZ : public CoordinateNodeWrapX
{
public:
	CoordinateNodeWrapZ(CoordinateNode* node, const Position3D& originPos) :
		CoordinateNodeWrapX(node, originPos) {}

	INLINE CoordinateNode* prev() {
		pCurrentNode_ = pCurrentNode_->pPrevZ();
		return pCurrentNode_;
	}

	INLINE CoordinateNode* next() {
		pCurrentNode_ = pCurrentNode_->pNextZ();
		return pCurrentNode_;
	}

	INLINE int compare() {
		float v = currentNodeEntity()->position().z;
		if (v == originPos_.z)
			return 0;
		else if (v > originPos_.z)
			return 1;
		else
			return -1;
	}

	INLINE float length() {
		return fabs(currentNodeEntity()->position().z - originPos_.z);
	}
};

class CoordinateNodeWrapY : public CoordinateNodeWrapX
{
public:
	CoordinateNodeWrapY(CoordinateNode* node, const Position3D& originPos) :
		CoordinateNodeWrapX(node, originPos) {}

	INLINE CoordinateNode* prev() {
		pCurrentNode_ = pCurrentNode_->pPrevY();
		return pCurrentNode_;
	}

	INLINE CoordinateNode* next() {
		pCurrentNode_ = pCurrentNode_->pNextY();
		return pCurrentNode_;
	}

	INLINE int compare() {
		float v = currentNodeEntity()->position().y;
		if (v == originPos_.y)
			return 0;
		else if (v > originPos_.y)
			return 1;
		else
			return -1;
	}

	INLINE float length() {
		return fabs(currentNodeEntity()->position().y - originPos_.y);
	}
};

//-------------------------------------------------------------------------------------
/**
 ??????????????????????
 ???????? NODEWRAP ????????????????????
   - CoordinateNodeWrapX
   - CoordinateNodeWrapZ
   - CoordinateNodeWrapY
*/
template <class NODEWRAP>
CoordinateNode* findNearestNode(CoordinateNode* rootNode, const Position3D& originPos)
{
	CoordinateNode* pRN = NULL;
	CoordinateNode* pCoordinateNode = rootNode;

	// ??????????EntityNode??????
	{
		// ????????????????????????????????????
		NODEWRAP wrap(rootNode, originPos);
		do
		{
			if (wrap.isEntityNode() && wrap.valid())
			{
				pRN = wrap.currentNode();
				break;
			}
		} while (wrap.prev());

		// ????????????????????????????
		if (!pRN)
		{
			wrap.reset();
			while (wrap.next())
			{
				if (wrap.isEntityNode() && wrap.valid())
				{
					pRN = wrap.currentNode();
					break;
				}
			}

			// ??????????????????
			if (!pRN)
				return NULL;
		}
	}

	// ????????????????????????????????????????????????????Node
	NODEWRAP wrap(pRN, originPos);
	int v = wrap.compare();
	
	if (v == 0)  // ????
	{
		return wrap.currentNode();
	}
	else if (v > 0)  // Entity Node??????????????
	{
		pCoordinateNode = wrap.currentNode();
		while (wrap.prev())
		{
			if (wrap.isEntityNode() && wrap.valid())
			{
				// ????????????????????????????????
				// ??????????position????????????entity??????????????????????
				if (wrap.compare() <= 0)
				{
					return wrap.currentNode();
				}
			}

			pCoordinateNode = wrap.currentNode();
		}
		return pCoordinateNode;
	}
	else   // Entity Node??????????????
	{
		pCoordinateNode = wrap.currentNode();
		while (wrap.next())
		{
			if (wrap.isEntityNode() && wrap.valid())
			{
				// ????????????????????????????????
				// ??????????position????????????entity??????????????????????
				if (wrap.compare() >= 0)
				{
					return wrap.currentNode();
				}
			}

			pCoordinateNode = wrap.currentNode();
		}

		return pCoordinateNode;
	}
}

//-------------------------------------------------------------------------------------
/**
 ??????????????????????entity
 ???????? NODEWRAP ????????????????????
   - CoordinateNodeWrapX
   - CoordinateNodeWrapZ
   - CoordinateNodeWrapY
*/
template <class NODEWRAP>
void entitiesInAxisRange(std::set<Entity*>& foundEntities, CoordinateNode* rootNode,
	const Position3D& originPos, float radius, int entityUType)
{
	CoordinateNode* pCoordinateNode = findNearestNode<NODEWRAP>(rootNode, originPos);
	if (!pCoordinateNode)
		return;

	NODEWRAP wrap(pCoordinateNode, originPos);

	// ??????????????????????????????????????
	if (wrap.isEntityNode() && wrap.valid())
	{
		Entity* pEntity = wrap.currentNodeEntity();

		if (entityUType == -1 || pEntity->pScriptModule()->getUType() == (ENTITY_SCRIPT_UID)entityUType)
		{
			if (wrap.length() <= radius)
			{
				foundEntities.insert(pEntity);
			}
		}
	}

	while (wrap.prev())
	{
		if (wrap.isEntityNode() && wrap.valid())
		{
			Entity* pEntity = wrap.currentNodeEntity();

			if (entityUType == -1 || pEntity->pScriptModule()->getUType() == (ENTITY_SCRIPT_UID)entityUType)
			{
				if (wrap.length() <= radius)
				{
					foundEntities.insert(pEntity);
				}
				else
				{
					break;
				}
			}
		}
	};

	wrap.reset();

	while (wrap.next())
	{
		if (wrap.isEntityNode() && wrap.valid())
		{
			Entity* pEntity = wrap.currentNodeEntity();

			if (entityUType == -1 || pEntity->pScriptModule()->getUType() == (ENTITY_SCRIPT_UID)entityUType)
			{
				if (wrap.length() <= radius)
				{
					foundEntities.insert(pEntity);
				}
				else
				{
					break;
				}
			}
		}
	};
}

//-------------------------------------------------------------------------------------
EntityCoordinateNode::EntityCoordinateNode(Entity* pEntity):
CoordinateNode(NULL),
pEntity_(pEntity),
watcherNodes_(),
delWatcherNodeNum_(0),
entityNodeUpdating_(0)
{
	flags(COORDINATE_NODE_FLAG_ENTITY);

#ifdef _DEBUG
	descr_ = (fmt::format("EntityCoordinateNode({}_{})", pEntity->scriptName(), pEntity->id()));
#endif

	weight_ = 1;

	Py_INCREF(pEntity_);
}

//-------------------------------------------------------------------------------------
EntityCoordinateNode::~EntityCoordinateNode()
{
	watcherNodes_.clear();

	pEntity_->onCoordinateNodesDestroy(this);
	Py_DECREF(pEntity_);
}

//-------------------------------------------------------------------------------------
float EntityCoordinateNode::xx() const
{
	if (pEntity_ == NULL || hasFlags((COORDINATE_NODE_FLAG_REMOVED | COORDINATE_NODE_FLAG_REMOVING)))
		return -FLT_MAX;

	return pEntity_->position().x;
}

//-------------------------------------------------------------------------------------
float EntityCoordinateNode::yy() const
{
	if(pEntity_ == NULL /*|| hasFlags((COORDINATE_NODE_FLAG_REMOVED | COORDINATE_NODE_FLAG_REMOVING))*/)
		return -FLT_MAX;

	return pEntity_->position().y;
}

//-------------------------------------------------------------------------------------
float EntityCoordinateNode::zz() const
{
	if(pEntity_ == NULL /*|| hasFlags((COORDINATE_NODE_FLAG_REMOVED | COORDINATE_NODE_FLAG_REMOVING))*/)
		return -FLT_MAX;

	return pEntity_->position().z;
}

//-------------------------------------------------------------------------------------
void EntityCoordinateNode::update()
{
	// ??????????????????????????????????CoordinateNode::update()??????????????????????????
	// ??????????update??????????????????????????????
	// ??????// A->B, B-A??????old_*??B??, A->B??????old_*??B????xx????????????B??,????update????????????????????
	// https://github.com/kbengine/kbengine/issues/407
	old_xx(x());
	old_yy(y());
	old_zz(z());

	CoordinateNode::update();

	addFlags(COORDINATE_NODE_FLAG_ENTITY_NODE_UPDATING);
	++entityNodeUpdating_;

	// ????????????watcherNodes_.size()????????????????????????????update????????????watcherNodes_????????????????
	for (WATCHER_NODES::size_type i = 0; i < watcherNodes_.size(); ++i)
	{
		CoordinateNode* pCoordinateNode = watcherNodes_[i];
		if (!pCoordinateNode)
			continue;

		pCoordinateNode->update();
	}

	--entityNodeUpdating_;
	if (entityNodeUpdating_ == 0)
		removeFlags(COORDINATE_NODE_FLAG_ENTITY_NODE_UPDATING);

	clearDelWatcherNodes();
}

//-------------------------------------------------------------------------------------
void EntityCoordinateNode::clearDelWatcherNodes()
{
	if (hasFlags((COORDINATE_NODE_FLAG_ENTITY_NODE_UPDATING | COORDINATE_NODE_FLAG_REMOVED | COORDINATE_NODE_FLAG_REMOVING)))
		return;

	if (delWatcherNodeNum_ > 0)
	{
		WATCHER_NODES::iterator iter = watcherNodes_.begin();
		for (; iter != watcherNodes_.end();)
		{
			if (!(*iter))
			{
				iter = watcherNodes_.erase(iter);
				--delWatcherNodeNum_;

				if (delWatcherNodeNum_ <= 0)
					return;
			}
			else
			{
				++iter;
			}
		}
	}
}

//-------------------------------------------------------------------------------------
void EntityCoordinateNode::onRemove()
{
	for (WATCHER_NODES::size_type i = 0; i < watcherNodes_.size(); ++i)
	{
		CoordinateNode* pCoordinateNode = watcherNodes_[i];

		if (!pCoordinateNode)
			continue;

		// ????????NULL?? ??????update??????????
		// ??????????watcherNodes_????????????????????????EntityCoordinateNode::update()??????????????
		// ????????????EntityCoordinateNode::update()??????watcherNodes_????????????????
		watcherNodes_[i] = NULL;
		++delWatcherNodeNum_;

		pCoordinateNode->onParentRemove(this);
	}

	CoordinateNode::onRemove();
}

//-------------------------------------------------------------------------------------
bool EntityCoordinateNode::addWatcherNode(CoordinateNode* pNode)
{
	clearDelWatcherNodes();

	WATCHER_NODES::iterator iter = std::find(watcherNodes_.begin(), watcherNodes_.end(), pNode);
	if(iter != watcherNodes_.end())
		return false;

	watcherNodes_.push_back(pNode);
	
	onAddWatcherNode(pNode);
	return true;
}

//-------------------------------------------------------------------------------------
void EntityCoordinateNode::onAddWatcherNode(CoordinateNode* pNode)
{
}

//-------------------------------------------------------------------------------------
bool EntityCoordinateNode::delWatcherNode(CoordinateNode* pNode)
{
	WATCHER_NODES::iterator iter = std::find(watcherNodes_.begin(), watcherNodes_.end(), pNode);
	if(iter == watcherNodes_.end())
		return false;

	if (hasFlags((COORDINATE_NODE_FLAG_ENTITY_NODE_UPDATING | COORDINATE_NODE_FLAG_REMOVED | COORDINATE_NODE_FLAG_REMOVING)))
	{
		(*iter) = NULL;
		++delWatcherNodeNum_;
	}
	else
	{
		watcherNodes_.erase(iter);
	}

	return true;
}

//-------------------------------------------------------------------------------------
void EntityCoordinateNode::entitiesInRange(std::vector<Entity*>& foundEntities, CoordinateNode* rootNode,
									  const Position3D& originPos, float radius, int entityUType)
{
	std::set<Entity*> entities_X;
	std::set<Entity*> entities_Z;

	entitiesInAxisRange<CoordinateNodeWrapX>(entities_X, rootNode, originPos, radius, entityUType);
	entitiesInAxisRange<CoordinateNodeWrapZ>(entities_Z, rootNode, originPos, radius, entityUType);

	// ????Y
	if (CoordinateSystem::hasY)
	{
		std::set<Entity*> entities_Y;
		entitiesInAxisRange<CoordinateNodeWrapY>(entities_Y, rootNode, originPos, radius, entityUType);


		std::set<Entity*> res_set;
		set_intersection(entities_X.begin(), entities_X.end(), entities_Z.begin(), entities_Z.end(), std::inserter(res_set, res_set.end()));
		set_intersection(res_set.begin(), res_set.end(), entities_Y.begin(), entities_Y.end(), std::back_inserter(foundEntities));
	}
	else
	{
		set_intersection(entities_X.begin(), entities_X.end(), entities_Z.begin(), entities_Z.end(), std::back_inserter(foundEntities));
	}
}

//-------------------------------------------------------------------------------------
}
