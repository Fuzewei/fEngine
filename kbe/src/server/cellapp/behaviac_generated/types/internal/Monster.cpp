﻿// -------------------------------------------------------------------------------
// THIS FILE IS ORIGINALLY GENERATED BY THE DESIGNER.
// YOU ARE ONLY ALLOWED TO MODIFY CODE BETWEEN '///<<< BEGIN' AND '///<<< END'.
// PLEASE MODIFY AND REGENERETE IT IN THE DESIGNER FOR CLASS/MEMBERS/METHODS, ETC.
// -------------------------------------------------------------------------------

#include "Monster.h"

///<<< BEGIN WRITING YOUR CODE FILE_INIT
#include <cmath>
	///<<< END WRITING YOUR CODE

namespace behaviac
{
///<<< BEGIN WRITING YOUR CODE NAMESPACE_INIT

///<<< END WRITING YOUR CODE

	Monster::Monster()
	{
		targetID = 0;
		useingSkillId = 0;
///<<< BEGIN WRITING YOUR CODE CONSTRUCTOR
		
		///<<< END WRITING YOUR CODE
	}

	Monster::~Monster()
	{
///<<< BEGIN WRITING YOUR CODE DESTRUCTOR
		
		///<<< END WRITING YOUR CODE
	}

	behaviac::EBTStatus Monster::canSkillAttack(int skillId)
	{
///<<< BEGIN WRITING YOUR CODE canSkillAttack
		auto ans = behaviac::EBTStatus::BT_FAILURE;;
		auto ret = _callPyFunc(this, "canSkillAttack", PyLong_FromLong(skillId));
		if (ret)
		{
			ans = (behaviac::EBTStatus)PyLong_AsLong(ret);
			Py_DECREF(ret);
		}
		return ans;
///<<< END WRITING YOUR CODE
	}

	void Monster::chaseTarget(int entityId)
	{
///<<< BEGIN WRITING YOUR CODE chaseTarget
		auto ret = _callPyFunc(this, "chaseTarget", PyLong_FromLong(entityId));
		if (ret)
		{
			Py_DECREF(ret);
		}
///<<< END WRITING YOUR CODE
	}

	double Monster::distanceTo(behaviac::Vector3& position)
	{
///<<< BEGIN WRITING YOUR CODE distanceTo
		const float d_x = position.x - this->positon.x;
		const float d_y = position.y - this->positon.y;
		const float d_z = position.z - this->positon.z;
		return sqrtf(d_x * d_x + d_y * d_y + d_z * d_z);
///<<< END WRITING YOUR CODE
	}

	void Monster::fightMove(int moveId, behaviac::Vector3& movePostion)
	{
///<<< BEGIN WRITING YOUR CODE fightMove
		PyObject* pArgs = PyTuple_New(2);
		PyObject* pyPostion = PyTuple_New(3);
		PyTuple_SetItem(pyPostion, 0, PyLong_FromLong(movePostion.x));
		PyTuple_SetItem(pyPostion, 1, PyLong_FromLong(movePostion.y));
		PyTuple_SetItem(pyPostion, 2, PyLong_FromLong(movePostion.z));

		PyTuple_SetItem(pArgs, 0, PyLong_FromLong(moveId));
		PyTuple_SetItem(pArgs, 1, pyPostion);

		auto ret = _callPyFunc(this, "fightMove", pArgs);
		if (ret)
		{
			Py_DECREF(ret);
		}
///<<< END WRITING YOUR CODE
	}

	void Monster::findEnemys()
	{
///<<< BEGIN WRITING YOUR CODE findEnemys
		auto ret = _callPyFunc(this, "findEnemys", Py_None);
		if (ret)
		{
			Py_DECREF(ret);
		}

///<<< END WRITING YOUR CODE
	}

	behaviac::EBTStatus Monster::funcReturn(behaviac::EBTStatus re)
	{
///<<< BEGIN WRITING YOUR CODE funcReturn
		return BT_INVALID;
///<<< END WRITING YOUR CODE
	}

	double Monster::getEnemyDistance()
	{
///<<< BEGIN WRITING YOUR CODE getEnemyDistance
		return enemyInfo.dis;
///<<< END WRITING YOUR CODE
	}

	behaviac::EnemyInfo Monster::getEnemyInfo()
	{
///<<< BEGIN WRITING YOUR CODE getEnemyInfo
		
		auto ret = _callPyFunc(this, "getEnemyInfo", Py_None);
		int EntityId = 0;
		float dis = 0.0f;
		if (ret)
		{
			PyObject* pEntityId = PyTuple_GetItem(ret, 0);
			EntityId = PyLong_AsLong(pEntityId);
			PyObject* pyDis =  PyTuple_GetItem(ret, 1);
			dis = PyFloat_AsDouble(pyDis);
			Py_DECREF(ret);
		}
		else
		{
			assert(false);
		}
		behaviac::EnemyInfo tmp = { 0 ,0.0f };
		tmp.entityId = EntityId;
		tmp.dis = dis;
		targetID = EntityId;
		getProperties();
		return tmp;
///<<< END WRITING YOUR CODE
	}

	void Monster::getFightMoveTarget(int moveId)
	{
///<<< BEGIN WRITING YOUR CODE getFightMoveTarget
		auto pyPosition = _callPyFunc(this, "getFightMoveTarget", PyLong_FromLong(moveId));
		if (pyPosition)
		{
			auto x = PyObject_GetAttrString(pyPosition, "x");
			moveTargetPosition.x = PyFloat_AsDouble(x);
			auto y = PyObject_GetAttrString(pyPosition, "y");
			moveTargetPosition.y = PyFloat_AsDouble(y);
			auto z = PyObject_GetAttrString(pyPosition, "z");
			moveTargetPosition.z = PyFloat_AsDouble(z);
			Py_DECREF(pyPosition);
		}
///<<< END WRITING YOUR CODE
	}

	void Monster::idle()
	{
///<<< BEGIN WRITING YOUR CODE idle
 		_callPyFunc(this, "idle", Py_None);
///<<< END WRITING YOUR CODE
	}

	behaviac::EBTStatus Monster::randomWalk(float radius)
	{
///<<< BEGIN WRITING YOUR CODE randomWalk
		behaviac::EBTStatus ans = behaviac::EBTStatus::BT_FAILURE;
		auto ret = _callPyFunc(this, "randomWalk", PyFloat_FromDouble(radius));
		if (ret)
		{
			auto ans = (behaviac::EBTStatus)PyLong_AsLong(ret);
			Py_DECREF(ret);
		}
		return ans;
///<<< END WRITING YOUR CODE
	}

	void Monster::setInBattle(bool isInBattle)
	{
///<<< BEGIN WRITING YOUR CODE setInBattle
		auto ret = _callPyFunc(this, "aiSetInBattle", PyBool_FromLong(isInBattle));
		if (ret)
		{
			Py_DECREF(ret);
		}
///<<< END WRITING YOUR CODE
	}

	void Monster::useSkill(int skillId)
	{
///<<< BEGIN WRITING YOUR CODE useSkill
		PyObject* pArgs = PyTuple_New(2);
		
		PyTuple_SetItem(pArgs, 0, PyLong_FromLong(enemyInfo.entityId));
		PyTuple_SetItem(pArgs, 1, PyLong_FromLong(skillId));
		

		auto ret = _callPyFunc(this, "useSkill", pArgs);
		if (ret)
		{
			useingSkillId = skillId;
			auto ans = (behaviac::EBTStatus)PyLong_AsLong(ret);
			Py_DECREF(ret);
		}
///<<< END WRITING YOUR CODE
	}

///<<< BEGIN WRITING YOUR CODE NAMESPACE_UNINIT

///<<< END WRITING YOUR CODE
}

///<<< BEGIN WRITING YOUR CODE FILE_UNINIT
namespace behaviac
{
	//获取所属entity身上的属性
	void Monster::getProperties()
	{
		PyObject* pyPosition = PyObject_GetAttrString((PyObject*)pEntity_, "position");
		if (pyPosition)
		{
			auto x = PyObject_GetAttrString(pyPosition, "x");
			positon.x = PyFloat_AsDouble(x);
			auto y = PyObject_GetAttrString(pyPosition, "y");
			positon.y = PyFloat_AsDouble(y);
			auto z = PyObject_GetAttrString(pyPosition, "z");
			positon.z = PyFloat_AsDouble(z);
			Py_DECREF(x);
			Py_DECREF(y);
			Py_DECREF(z);
			Py_DECREF(pyPosition);
		}
	}
}
///<<< END WRITING YOUR CODE
