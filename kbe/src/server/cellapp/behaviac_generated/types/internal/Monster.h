﻿// -------------------------------------------------------------------------------
// THIS FILE IS ORIGINALLY GENERATED BY THE DESIGNER.
// YOU ARE ONLY ALLOWED TO MODIFY CODE BETWEEN '///<<< BEGIN' AND '///<<< END'.
// PLEASE MODIFY AND REGENERETE IT IN THE DESIGNER FOR CLASS/MEMBERS/METHODS, ETC.
// -------------------------------------------------------------------------------

#ifndef _BEHAVIAC_MONSTER_H_
#define _BEHAVIAC_MONSTER_H_

#include "behaviac_headers.h"

///<<< BEGIN WRITING YOUR CODE FILE_INIT
#include "../../../entity.h"
namespace behaviac {
///<<< END WRITING YOUR CODE

class Monster : public Agent
///<<< BEGIN WRITING YOUR CODE Monster
///<<< END WRITING YOUR CODE
{
public:
	Monster();
	virtual ~Monster();

	BEHAVIAC_DECLARE_AGENTTYPE(Monster, behaviac::Agent)

	public: void hello();

	public: void pyMethod(behaviac::string funcName);

///<<< BEGIN WRITING YOUR CODE CLASS_PART

		  KBEngine::Entity* pEntity_;

		  ///<<< END WRITING YOUR CODE
};

///<<< BEGIN WRITING YOUR CODE FILE_UNINIT
}
///<<< END WRITING YOUR CODE

#endif
