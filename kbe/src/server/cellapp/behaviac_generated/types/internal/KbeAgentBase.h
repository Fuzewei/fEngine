﻿// -------------------------------------------------------------------------------
// THIS FILE IS ORIGINALLY GENERATED BY THE DESIGNER.
// YOU ARE ONLY ALLOWED TO MODIFY CODE BETWEEN '///<<< BEGIN' AND '///<<< END'.
// PLEASE MODIFY AND REGENERETE IT IN THE DESIGNER FOR CLASS/MEMBERS/METHODS, ETC.
// -------------------------------------------------------------------------------

#ifndef _BEHAVIAC_BEHAVIAC_KBEAGENTBASE_H_
#define _BEHAVIAC_BEHAVIAC_KBEAGENTBASE_H_

#include "behaviac_headers.h"

///<<< BEGIN WRITING YOUR CODE FILE_INIT
#include "pyscript/scriptobject.h"
///<<< END WRITING YOUR CODE

namespace behaviac
{
///<<< BEGIN WRITING YOUR CODE NAMESPACE_INIT

///<<< END WRITING YOUR CODE

	class KbeAgentBase : public behaviac::Agent
///<<< BEGIN WRITING YOUR CODE KbeAgentBase
///<<< END WRITING YOUR CODE
	{
	public:
		KbeAgentBase();
		virtual ~KbeAgentBase();

		BEHAVIAC_DECLARE_AGENTTYPE(behaviac::KbeAgentBase, behaviac::Agent)

		private: void callPyFunc(behaviac::string funcName);

///<<< BEGIN WRITING YOUR CODE CLASS_PART
	
	public:
		void* pEntity_;
///<<< END WRITING YOUR CODE
	};

///<<< BEGIN WRITING YOUR CODE NAMESPACE_UNINIT

///<<< END WRITING YOUR CODE
}

///<<< BEGIN WRITING YOUR CODE FILE_UNINIT

///<<< END WRITING YOUR CODE

#endif
