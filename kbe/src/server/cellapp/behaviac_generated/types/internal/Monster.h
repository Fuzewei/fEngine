﻿// -------------------------------------------------------------------------------
// THIS FILE IS ORIGINALLY GENERATED BY THE DESIGNER.
// YOU ARE ONLY ALLOWED TO MODIFY CODE BETWEEN '///<<< BEGIN' AND '///<<< END'.
// PLEASE MODIFY AND REGENERETE IT IN THE DESIGNER FOR CLASS/MEMBERS/METHODS, ETC.
// -------------------------------------------------------------------------------

#ifndef _BEHAVIAC_BEHAVIAC_MONSTER_H_
#define _BEHAVIAC_BEHAVIAC_MONSTER_H_

#include "behaviac_headers.h"

#include "KbeAgentBase.h"

///<<< BEGIN WRITING YOUR CODE FILE_INIT


	///<<< END WRITING YOUR CODE

namespace behaviac
{
///<<< BEGIN WRITING YOUR CODE NAMESPACE_INIT

///<<< END WRITING YOUR CODE

	class Monster : public behaviac::KbeAgentBase
///<<< BEGIN WRITING YOUR CODE Monster
		///<<< END WRITING YOUR CODE
	{
	public:
		Monster();
		virtual ~Monster();

		BEHAVIAC_DECLARE_AGENTTYPE(behaviac::Monster, behaviac::KbeAgentBase)

		public: behaviac::EnemyInfo enemyInfo;

		public: behaviac::Vector3 moveTargetPosition;

		public: behaviac::Vector3 positon;

		public: int targetID;

		public: int useingSkillId;

		public: behaviac::EBTStatus canSkillAttack(int skillId);

		public: void chaseTarget(int entityId);

		public: double distanceTo(behaviac::Vector3& position);

		public: void fightMove(int moveId, behaviac::Vector3& movePostion);

		public: void findEnemys();

		public: behaviac::EBTStatus funcReturn(behaviac::EBTStatus re);

		public: double getEnemyDistance();

		public: behaviac::EnemyInfo getEnemyInfo();

		public: void getFightMoveTarget(int moveId);

		public: void idle();

		public: behaviac::EBTStatus randomWalk(float radius);

		public: void setInBattle(bool isInBattle);

		public: void useSkill(int skillId);

///<<< BEGIN WRITING YOUR CODE CLASS_PART
		public: void getProperties();


				  ///<<< END WRITING YOUR CODE
	};

///<<< BEGIN WRITING YOUR CODE NAMESPACE_UNINIT

///<<< END WRITING YOUR CODE
}

///<<< BEGIN WRITING YOUR CODE FILE_UNINIT

namespace behaviac
{

}

///<<< END WRITING YOUR CODE

#endif
