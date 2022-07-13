﻿// ---------------------------------------------------------------------
// THIS FILE IS AUTO-GENERATED BY BEHAVIAC DESIGNER, SO PLEASE DON'T MODIFY IT BY YOURSELF!
// ---------------------------------------------------------------------

#include "behaviac/common/meta.h"
#include "behaviac/common/member.h"
#include "behaviac_agent_meta.h"

namespace behaviac
{
	class CInstanceConst_behaviac_EnemyInfo : public CInstanceConstBase<behaviac::EnemyInfo>
	{
		IInstanceMember* _entityId;
		IInstanceMember* _dis;

	public: 
		CInstanceConst_behaviac_EnemyInfo(const char* valueStr) : CInstanceConstBase<behaviac::EnemyInfo>(valueStr)
		{
			behaviac::vector<behaviac::string> paramStrs = behaviac::StringUtils::SplitTokensForStruct(valueStr);
			BEHAVIAC_ASSERT(paramStrs.size() == 2);

			_entityId = AgentMeta::TParseProperty<int >(paramStrs[0].c_str());
			_dis = AgentMeta::TParseProperty<float >(paramStrs[1].c_str());
		}

		~CInstanceConst_behaviac_EnemyInfo()
		{
			BEHAVIAC_DELETE _entityId;
			BEHAVIAC_DELETE _dis;
		}

		virtual void run(Agent* self)
		{
			BEHAVIAC_ASSERT(_entityId != NULL);
			BEHAVIAC_ASSERT(_dis != NULL);

			_value.entityId = *(int*)_entityId->GetValue(self, behaviac::Meta::IsVector<int >::Result, behaviac::GetClassTypeNumberId<int >());
			_value.dis = *(float*)_dis->GetValue(self, behaviac::Meta::IsVector<float >::Result, behaviac::GetClassTypeNumberId<float >());
		}
	};

	class CInstanceConst_behaviac_Vector3 : public CInstanceConstBase<behaviac::Vector3>
	{
		IInstanceMember* _x;
		IInstanceMember* _y;
		IInstanceMember* _z;

	public: 
		CInstanceConst_behaviac_Vector3(const char* valueStr) : CInstanceConstBase<behaviac::Vector3>(valueStr)
		{
			behaviac::vector<behaviac::string> paramStrs = behaviac::StringUtils::SplitTokensForStruct(valueStr);
			BEHAVIAC_ASSERT(paramStrs.size() == 3);

			_x = AgentMeta::TParseProperty<float >(paramStrs[0].c_str());
			_y = AgentMeta::TParseProperty<float >(paramStrs[1].c_str());
			_z = AgentMeta::TParseProperty<float >(paramStrs[2].c_str());
		}

		~CInstanceConst_behaviac_Vector3()
		{
			BEHAVIAC_DELETE _x;
			BEHAVIAC_DELETE _y;
			BEHAVIAC_DELETE _z;
		}

		virtual void run(Agent* self)
		{
			BEHAVIAC_ASSERT(_x != NULL);
			BEHAVIAC_ASSERT(_y != NULL);
			BEHAVIAC_ASSERT(_z != NULL);

			_value.x = *(float*)_x->GetValue(self, behaviac::Meta::IsVector<float >::Result, behaviac::GetClassTypeNumberId<float >());
			_value.y = *(float*)_y->GetValue(self, behaviac::Meta::IsVector<float >::Result, behaviac::GetClassTypeNumberId<float >());
			_value.z = *(float*)_z->GetValue(self, behaviac::Meta::IsVector<float >::Result, behaviac::GetClassTypeNumberId<float >());
		}
	};

	class CMethod_behaviac_Agent_VectorAdd : public CAgentMethodVoidBase
	{
		IInstanceMember* _param0;
		IInstanceMember* _param1;

	public: 
		CMethod_behaviac_Agent_VectorAdd() : _param0(0) , _param1(0) 
		{
		}

		CMethod_behaviac_Agent_VectorAdd(CMethod_behaviac_Agent_VectorAdd &rhs) : CAgentMethodVoidBase(rhs) , _param0(0) , _param1(0) 
		{
		}

		~CMethod_behaviac_Agent_VectorAdd()
		{
			BEHAVIAC_DELETE _param0;
			BEHAVIAC_DELETE _param1;
		}

		virtual IInstanceMember* clone()
		{
			return BEHAVIAC_NEW CMethod_behaviac_Agent_VectorAdd(*this);
		}

		virtual void load(const char* instance, behaviac::vector<behaviac::string>& paramStrs)
		{
			BEHAVIAC_ASSERT(paramStrs.size() == 2);

			behaviac::StringUtils::StringCopySafe(kInstanceNameMax, _instance, instance);
			_param0 = AgentMeta::TParseProperty<IList >(paramStrs[0].c_str());
			_param1 = AgentMeta::TParseProperty<System::Object >(paramStrs[1].c_str());
		}

		virtual void run(Agent* self)
		{
			BEHAVIAC_ASSERT(_param0 != NULL);
			BEHAVIAC_ASSERT(_param1 != NULL);

			IList& pValue_param0 = *(IList*)_param0->GetValue(self, behaviac::Meta::IsVector<IList >::Result, behaviac::GetClassTypeNumberId<IList >());
			System::Object& pValue_param1 = *(System::Object*)_param1->GetValue(self, behaviac::Meta::IsVector<System::Object >::Result, behaviac::GetClassTypeNumberId<System::Object >());
			behaviac::Agent::VectorAdd(pValue_param0, pValue_param1);
		}
	};

	class CMethod_behaviac_Agent_VectorClear : public CAgentMethodVoidBase
	{
		IInstanceMember* _param0;

	public: 
		CMethod_behaviac_Agent_VectorClear() : _param0(0) 
		{
		}

		CMethod_behaviac_Agent_VectorClear(CMethod_behaviac_Agent_VectorClear &rhs) : CAgentMethodVoidBase(rhs) , _param0(0) 
		{
		}

		~CMethod_behaviac_Agent_VectorClear()
		{
			BEHAVIAC_DELETE _param0;
		}

		virtual IInstanceMember* clone()
		{
			return BEHAVIAC_NEW CMethod_behaviac_Agent_VectorClear(*this);
		}

		virtual void load(const char* instance, behaviac::vector<behaviac::string>& paramStrs)
		{
			BEHAVIAC_ASSERT(paramStrs.size() == 1);

			behaviac::StringUtils::StringCopySafe(kInstanceNameMax, _instance, instance);
			_param0 = AgentMeta::TParseProperty<IList >(paramStrs[0].c_str());
		}

		virtual void run(Agent* self)
		{
			BEHAVIAC_ASSERT(_param0 != NULL);

			IList& pValue_param0 = *(IList*)_param0->GetValue(self, behaviac::Meta::IsVector<IList >::Result, behaviac::GetClassTypeNumberId<IList >());
			behaviac::Agent::VectorClear(pValue_param0);
		}
	};

	class CMethod_behaviac_Agent_VectorContains : public CAgentMethodBase<bool>
	{
		IInstanceMember* _param0;
		IInstanceMember* _param1;

	public: 
		CMethod_behaviac_Agent_VectorContains() : _param0(0) , _param1(0) 
		{
		}

		CMethod_behaviac_Agent_VectorContains(CMethod_behaviac_Agent_VectorContains &rhs) : CAgentMethodBase<bool>(rhs) , _param0(0) , _param1(0) 
		{
		}

		~CMethod_behaviac_Agent_VectorContains()
		{
			BEHAVIAC_DELETE _param0;
			BEHAVIAC_DELETE _param1;
		}

		virtual IInstanceMember* clone()
		{
			return BEHAVIAC_NEW CMethod_behaviac_Agent_VectorContains(*this);
		}

		virtual void load(const char* instance, behaviac::vector<behaviac::string>& paramStrs)
		{
			BEHAVIAC_ASSERT(paramStrs.size() == 2);

			behaviac::StringUtils::StringCopySafe(kInstanceNameMax, _instance, instance);
			_param0 = AgentMeta::TParseProperty<IList >(paramStrs[0].c_str());
			_param1 = AgentMeta::TParseProperty<System::Object >(paramStrs[1].c_str());
		}

		virtual void run(Agent* self)
		{
			BEHAVIAC_ASSERT(_param0 != NULL);
			BEHAVIAC_ASSERT(_param1 != NULL);

			IList& pValue_param0 = *(IList*)_param0->GetValue(self, behaviac::Meta::IsVector<IList >::Result, behaviac::GetClassTypeNumberId<IList >());
			System::Object& pValue_param1 = *(System::Object*)_param1->GetValue(self, behaviac::Meta::IsVector<System::Object >::Result, behaviac::GetClassTypeNumberId<System::Object >());
			_returnValue->value = behaviac::Agent::VectorContains(pValue_param0, pValue_param1);
		}
	};

	class CMethod_behaviac_Agent_VectorLength : public CAgentMethodBase<int>
	{
		IInstanceMember* _param0;

	public: 
		CMethod_behaviac_Agent_VectorLength() : _param0(0) 
		{
		}

		CMethod_behaviac_Agent_VectorLength(CMethod_behaviac_Agent_VectorLength &rhs) : CAgentMethodBase<int>(rhs) , _param0(0) 
		{
		}

		~CMethod_behaviac_Agent_VectorLength()
		{
			BEHAVIAC_DELETE _param0;
		}

		virtual IInstanceMember* clone()
		{
			return BEHAVIAC_NEW CMethod_behaviac_Agent_VectorLength(*this);
		}

		virtual void load(const char* instance, behaviac::vector<behaviac::string>& paramStrs)
		{
			BEHAVIAC_ASSERT(paramStrs.size() == 1);

			behaviac::StringUtils::StringCopySafe(kInstanceNameMax, _instance, instance);
			_param0 = AgentMeta::TParseProperty<IList >(paramStrs[0].c_str());
		}

		virtual void run(Agent* self)
		{
			BEHAVIAC_ASSERT(_param0 != NULL);

			IList& pValue_param0 = *(IList*)_param0->GetValue(self, behaviac::Meta::IsVector<IList >::Result, behaviac::GetClassTypeNumberId<IList >());
			_returnValue->value = behaviac::Agent::VectorLength(pValue_param0);
		}
	};

	class CMethod_behaviac_Agent_VectorRemove : public CAgentMethodVoidBase
	{
		IInstanceMember* _param0;
		IInstanceMember* _param1;

	public: 
		CMethod_behaviac_Agent_VectorRemove() : _param0(0) , _param1(0) 
		{
		}

		CMethod_behaviac_Agent_VectorRemove(CMethod_behaviac_Agent_VectorRemove &rhs) : CAgentMethodVoidBase(rhs) , _param0(0) , _param1(0) 
		{
		}

		~CMethod_behaviac_Agent_VectorRemove()
		{
			BEHAVIAC_DELETE _param0;
			BEHAVIAC_DELETE _param1;
		}

		virtual IInstanceMember* clone()
		{
			return BEHAVIAC_NEW CMethod_behaviac_Agent_VectorRemove(*this);
		}

		virtual void load(const char* instance, behaviac::vector<behaviac::string>& paramStrs)
		{
			BEHAVIAC_ASSERT(paramStrs.size() == 2);

			behaviac::StringUtils::StringCopySafe(kInstanceNameMax, _instance, instance);
			_param0 = AgentMeta::TParseProperty<IList >(paramStrs[0].c_str());
			_param1 = AgentMeta::TParseProperty<System::Object >(paramStrs[1].c_str());
		}

		virtual void run(Agent* self)
		{
			BEHAVIAC_ASSERT(_param0 != NULL);
			BEHAVIAC_ASSERT(_param1 != NULL);

			IList& pValue_param0 = *(IList*)_param0->GetValue(self, behaviac::Meta::IsVector<IList >::Result, behaviac::GetClassTypeNumberId<IList >());
			System::Object& pValue_param1 = *(System::Object*)_param1->GetValue(self, behaviac::Meta::IsVector<System::Object >::Result, behaviac::GetClassTypeNumberId<System::Object >());
			behaviac::Agent::VectorRemove(pValue_param0, pValue_param1);
		}
	};

	class CMethod_behaviac_Monster_distanceTo : public CAgentMethodBase<double>
	{
		IInstanceMember* _position;

	public: 
		CMethod_behaviac_Monster_distanceTo() : _position(0) 
		{
		}

		CMethod_behaviac_Monster_distanceTo(CMethod_behaviac_Monster_distanceTo &rhs) : CAgentMethodBase<double>(rhs) , _position(0) 
		{
		}

		~CMethod_behaviac_Monster_distanceTo()
		{
			BEHAVIAC_DELETE _position;
		}

		virtual IInstanceMember* clone()
		{
			return BEHAVIAC_NEW CMethod_behaviac_Monster_distanceTo(*this);
		}

		virtual void load(const char* instance, behaviac::vector<behaviac::string>& paramStrs)
		{
			BEHAVIAC_ASSERT(paramStrs.size() == 1);

			behaviac::StringUtils::StringCopySafe(kInstanceNameMax, _instance, instance);
			if (behaviac::StringUtils::StartsWith(paramStrs[0].c_str(), "{"))
			{
				_position = BEHAVIAC_NEW CInstanceConst_behaviac_Vector3(paramStrs[0].c_str());
			}
			else
			{
				_position = AgentMeta::TParseProperty<behaviac::Vector3 >(paramStrs[0].c_str());
			}
		}

		virtual void run(Agent* self)
		{
			BEHAVIAC_ASSERT(_position != NULL);

			_position->run(self);
			behaviac::Vector3& pValue_position = *(behaviac::Vector3*)_position->GetValue(self, behaviac::Meta::IsVector<behaviac::Vector3 >::Result, behaviac::GetClassTypeNumberId<behaviac::Vector3 >());
			self = Agent::GetParentAgent(self, _instance);

			_returnValue->value = ((behaviac::Monster*)self)->distanceTo(pValue_position);
		}
	};

	class CMethod_behaviac_Monster_fightMove : public CAgentMethodVoidBase
	{
		IInstanceMember* _moveId;
		IInstanceMember* _movePostion;

	public: 
		CMethod_behaviac_Monster_fightMove() : _moveId(0) , _movePostion(0) 
		{
		}

		CMethod_behaviac_Monster_fightMove(CMethod_behaviac_Monster_fightMove &rhs) : CAgentMethodVoidBase(rhs) , _moveId(0) , _movePostion(0) 
		{
		}

		~CMethod_behaviac_Monster_fightMove()
		{
			BEHAVIAC_DELETE _moveId;
			BEHAVIAC_DELETE _movePostion;
		}

		virtual IInstanceMember* clone()
		{
			return BEHAVIAC_NEW CMethod_behaviac_Monster_fightMove(*this);
		}

		virtual void load(const char* instance, behaviac::vector<behaviac::string>& paramStrs)
		{
			BEHAVIAC_ASSERT(paramStrs.size() == 2);

			behaviac::StringUtils::StringCopySafe(kInstanceNameMax, _instance, instance);
			_moveId = AgentMeta::TParseProperty<int >(paramStrs[0].c_str());
			if (behaviac::StringUtils::StartsWith(paramStrs[1].c_str(), "{"))
			{
				_movePostion = BEHAVIAC_NEW CInstanceConst_behaviac_Vector3(paramStrs[1].c_str());
			}
			else
			{
				_movePostion = AgentMeta::TParseProperty<behaviac::Vector3 >(paramStrs[1].c_str());
			}
		}

		virtual void run(Agent* self)
		{
			BEHAVIAC_ASSERT(_moveId != NULL);
			BEHAVIAC_ASSERT(_movePostion != NULL);

			int& pValue_moveId = *(int*)_moveId->GetValue(self, behaviac::Meta::IsVector<int >::Result, behaviac::GetClassTypeNumberId<int >());
			_movePostion->run(self);
			behaviac::Vector3& pValue_movePostion = *(behaviac::Vector3*)_movePostion->GetValue(self, behaviac::Meta::IsVector<behaviac::Vector3 >::Result, behaviac::GetClassTypeNumberId<behaviac::Vector3 >());
			self = Agent::GetParentAgent(self, _instance);

			((behaviac::Monster*)self)->fightMove(pValue_moveId, pValue_movePostion);
		}
	};

	class BehaviorLoaderImplement : BehaviorLoader
	{
	public:
		BehaviorLoaderImplement()
		{
			AgentMeta::SetBehaviorLoader(this);
		}

		virtual ~BehaviorLoaderImplement()
		{
		}

		virtual bool load()
		{
			AgentMeta::SetTotalSignature(1977910395u);

			AgentMeta* meta = NULL;
			BEHAVIAC_UNUSED_VAR(meta);

			// behaviac::EnemyInfo
			meta = BEHAVIAC_NEW AgentMeta(2811434756u);
			AgentMeta::GetAgentMetas()[2086330426u] = meta;
			meta->RegisterMemberProperty(2547715678u, BEHAVIAC_NEW CMemberProperty< int >("entityId", Set_behaviac_EnemyInfo_entityId, Get_behaviac_EnemyInfo_entityId));
			meta->RegisterMemberProperty(2967653271u, BEHAVIAC_NEW CMemberProperty< float >("dis", Set_behaviac_EnemyInfo_dis, Get_behaviac_EnemyInfo_dis));

			// behaviac::Vector3
			meta = BEHAVIAC_NEW AgentMeta(3444481058u);
			AgentMeta::GetAgentMetas()[201177303u] = meta;
			meta->RegisterMemberProperty(784805480u, BEHAVIAC_NEW CMemberProperty< float >("x", Set_behaviac_Vector3_x, Get_behaviac_Vector3_x));
			meta->RegisterMemberProperty(937172777u, BEHAVIAC_NEW CMemberProperty< float >("y", Set_behaviac_Vector3_y, Get_behaviac_Vector3_y));
			meta->RegisterMemberProperty(485575914u, BEHAVIAC_NEW CMemberProperty< float >("z", Set_behaviac_Vector3_z, Get_behaviac_Vector3_z));

			// behaviac::Agent
			meta = BEHAVIAC_NEW AgentMeta(24743406u);
			AgentMeta::GetAgentMetas()[1770892321u] = meta;
			meta->RegisterMethod(1045109914u, BEHAVIAC_NEW CAgentStaticMethodVoid_1<char*>(FunctionPointer_behaviac_Agent_LogMessage));
			meta->RegisterMethod(2521019022u, BEHAVIAC_NEW CMethod_behaviac_Agent_VectorAdd());
			meta->RegisterMethod(2306090221u, BEHAVIAC_NEW CMethod_behaviac_Agent_VectorClear());
			meta->RegisterMethod(3483755530u, BEHAVIAC_NEW CMethod_behaviac_Agent_VectorContains());
			meta->RegisterMethod(505785840u, BEHAVIAC_NEW CMethod_behaviac_Agent_VectorLength());
			meta->RegisterMethod(502968959u, BEHAVIAC_NEW CMethod_behaviac_Agent_VectorRemove());

			// behaviac::KbeAgentBase
			meta = BEHAVIAC_NEW AgentMeta(2578230984u);
			AgentMeta::GetAgentMetas()[2432351009u] = meta;
			meta->RegisterMethod(916351369u, BEHAVIAC_NEW CAgentMethod_1< behaviac::EBTStatus, behaviac::string >(FunctionPointer_behaviac_KbeAgentBase_callPyFunc));
			meta->RegisterMethod(1925760633u, BEHAVIAC_NEW CAgentMethod< int >(FunctionPointer_behaviac_KbeAgentBase_getFightType));
			meta->RegisterMethod(1045109914u, BEHAVIAC_NEW CAgentStaticMethodVoid_1<char*>(FunctionPointer_behaviac_KbeAgentBase_LogMessage));
			meta->RegisterMethod(3216937541u, BEHAVIAC_NEW CAgentMethod< float >(FunctionPointer_behaviac_KbeAgentBase_now));
			meta->RegisterMethod(2521019022u, BEHAVIAC_NEW CMethod_behaviac_Agent_VectorAdd());
			meta->RegisterMethod(2306090221u, BEHAVIAC_NEW CMethod_behaviac_Agent_VectorClear());
			meta->RegisterMethod(3483755530u, BEHAVIAC_NEW CMethod_behaviac_Agent_VectorContains());
			meta->RegisterMethod(505785840u, BEHAVIAC_NEW CMethod_behaviac_Agent_VectorLength());
			meta->RegisterMethod(502968959u, BEHAVIAC_NEW CMethod_behaviac_Agent_VectorRemove());

			// behaviac::Monster
			meta = BEHAVIAC_NEW AgentMeta(740794124u);
			AgentMeta::GetAgentMetas()[4159774213u] = meta;
			meta->RegisterMemberProperty(3097763630u, BEHAVIAC_NEW CMemberProperty< behaviac::EnemyInfo >("enemyInfo", Set_behaviac_Monster_enemyInfo, Get_behaviac_Monster_enemyInfo));
			meta->RegisterMemberProperty(769320736u, BEHAVIAC_NEW CMemberProperty< behaviac::Vector3 >("moveTargetPosition", Set_behaviac_Monster_moveTargetPosition, Get_behaviac_Monster_moveTargetPosition));
			meta->RegisterMemberProperty(2418773765u, BEHAVIAC_NEW CMemberProperty< behaviac::Vector3 >("positon", Set_behaviac_Monster_positon, Get_behaviac_Monster_positon));
			meta->RegisterMemberProperty(2532596935u, BEHAVIAC_NEW CMemberProperty< int >("targetID", Set_behaviac_Monster_targetID, Get_behaviac_Monster_targetID));
			meta->RegisterMemberProperty(2068325471u, BEHAVIAC_NEW CMemberProperty< int >("useingSkillId", Set_behaviac_Monster_useingSkillId, Get_behaviac_Monster_useingSkillId));
			meta->RegisterMethod(916351369u, BEHAVIAC_NEW CAgentMethod_1< behaviac::EBTStatus, behaviac::string >(FunctionPointer_behaviac_Monster_callPyFunc));
			meta->RegisterMethod(1618876204u, BEHAVIAC_NEW CAgentMethod_1< behaviac::EBTStatus, int >(FunctionPointer_behaviac_Monster_canSkillAttack));
			meta->RegisterMethod(4257075051u, BEHAVIAC_NEW CAgentMethodVoid_1<int>(FunctionPointer_behaviac_Monster_chaseTarget));
			meta->RegisterMethod(484695972u, BEHAVIAC_NEW CMethod_behaviac_Monster_distanceTo());
			meta->RegisterMethod(813988031u, BEHAVIAC_NEW CMethod_behaviac_Monster_fightMove());
			meta->RegisterMethod(3261053510u, BEHAVIAC_NEW CAgentMethodVoid(FunctionPointer_behaviac_Monster_findEnemys));
			meta->RegisterMethod(111329797u, BEHAVIAC_NEW CAgentMethod_1< behaviac::EBTStatus, behaviac::EBTStatus >(FunctionPointer_behaviac_Monster_funcReturn));
			meta->RegisterMethod(2337514390u, BEHAVIAC_NEW CAgentMethod< double >(FunctionPointer_behaviac_Monster_getEnemyDistance));
			meta->RegisterMethod(3873906922u, BEHAVIAC_NEW CAgentMethod< behaviac::EnemyInfo >(FunctionPointer_behaviac_Monster_getEnemyInfo));
			meta->RegisterMethod(576883333u, BEHAVIAC_NEW CAgentMethodVoid_1<int>(FunctionPointer_behaviac_Monster_getFightMoveTarget));
			meta->RegisterMethod(1925760633u, BEHAVIAC_NEW CAgentMethod< int >(FunctionPointer_behaviac_Monster_getFightType));
			meta->RegisterMethod(1200690229u, BEHAVIAC_NEW CAgentMethodVoid(FunctionPointer_behaviac_Monster_idle));
			meta->RegisterMethod(1045109914u, BEHAVIAC_NEW CAgentStaticMethodVoid_1<char*>(FunctionPointer_behaviac_Monster_LogMessage));
			meta->RegisterMethod(3216937541u, BEHAVIAC_NEW CAgentMethod< float >(FunctionPointer_behaviac_Monster_now));
			meta->RegisterMethod(725611547u, BEHAVIAC_NEW CAgentMethod_1< behaviac::EBTStatus, float >(FunctionPointer_behaviac_Monster_randomWalk));
			meta->RegisterMethod(2284441500u, BEHAVIAC_NEW CAgentMethodVoid_1<bool>(FunctionPointer_behaviac_Monster_setInBattle));
			meta->RegisterMethod(4229661355u, BEHAVIAC_NEW CAgentMethodVoid_1<int>(FunctionPointer_behaviac_Monster_useSkill));
			meta->RegisterMethod(2521019022u, BEHAVIAC_NEW CMethod_behaviac_Agent_VectorAdd());
			meta->RegisterMethod(2306090221u, BEHAVIAC_NEW CMethod_behaviac_Agent_VectorClear());
			meta->RegisterMethod(3483755530u, BEHAVIAC_NEW CMethod_behaviac_Agent_VectorContains());
			meta->RegisterMethod(505785840u, BEHAVIAC_NEW CMethod_behaviac_Agent_VectorLength());
			meta->RegisterMethod(502968959u, BEHAVIAC_NEW CMethod_behaviac_Agent_VectorRemove());

			AgentMeta::Register<behaviac::Agent>("behaviac::Agent");
			AgentMeta::Register<behaviac::KbeAgentBase>("behaviac::KbeAgentBase");
			AgentMeta::Register<behaviac::Monster>("behaviac::Monster");
			AgentMeta::Register<behaviac::EnemyInfo>("behaviac::EnemyInfo");
			AgentMeta::Register<behaviac::Vector3>("behaviac::Vector3");

			return true;
		}

		virtual bool unLoad()
		{
			AgentMeta::UnRegister<behaviac::Agent>("behaviac::Agent");
			AgentMeta::UnRegister<behaviac::KbeAgentBase>("behaviac::KbeAgentBase");
			AgentMeta::UnRegister<behaviac::Monster>("behaviac::Monster");
			AgentMeta::UnRegister<behaviac::EnemyInfo>("behaviac::EnemyInfo");
			AgentMeta::UnRegister<behaviac::Vector3>("behaviac::Vector3");

			return true;
		}
	};

	static BehaviorLoaderImplement _behaviorLoaderImplement_;

	static BehaviorLoaderImplement* _pBehaviorLoader_ = NULL;

	void InitBehaviorLoader()
	{
		_pBehaviorLoader_ = BEHAVIAC_NEW BehaviorLoaderImplement();
	}

	void DestroyBehaviorLoader()
	{
		if (_pBehaviorLoader_)
		{
			BEHAVIAC_DELETE _pBehaviorLoader_;
			_pBehaviorLoader_ = NULL;
		}
	}
}
