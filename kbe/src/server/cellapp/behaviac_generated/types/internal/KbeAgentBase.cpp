﻿// -------------------------------------------------------------------------------
// THIS FILE IS ORIGINALLY GENERATED BY THE DESIGNER.
// YOU ARE ONLY ALLOWED TO MODIFY CODE BETWEEN '///<<< BEGIN' AND '///<<< END'.
// PLEASE MODIFY AND REGENERETE IT IN THE DESIGNER FOR CLASS/MEMBERS/METHODS, ETC.
// -------------------------------------------------------------------------------

#include "KbeAgentBase.h"

///<<< BEGIN WRITING YOUR CODE FILE_INIT

///<<< END WRITING YOUR CODE

namespace behaviac
{
///<<< BEGIN WRITING YOUR CODE NAMESPACE_INIT
	PyObject* _callPyFunc(KbeAgentBase* agent, behaviac::string funcName, PyObject* pArgs)
	{
		behaviac::EBTStatus ans = behaviac::EBTStatus::BT_FAILURE;
		Py_INCREF(agent->pEntity_);
		PyObject* pyCallable = PyObject_GetAttrString((PyObject*)agent->pEntity_, "onBhCallFunc");
		Py_DECREF(agent->pEntity_);
		if (!pyCallable)
		{
			return NULL;
		}
		/*va_list arg_ptr;
		va_start(arg_ptr, funcName.length());
		PyObject* pArgs = PyTuple_New(funcName.length());
		for (size_t i = 0; i < funcName.length(); i++)
		{
			PyTuple_SetItem(pArgs, i, Py_BuildValue(funcName[i], ));
		}
		PyObject* funcArgs = Py_BuildValue(format.c_str(), 0);*/



		PyObject* pyResult = PyObject_CallFunction(pyCallable, const_cast<char*>("sO"), funcName.c_str(), pArgs);
		Py_DECREF(pyCallable);
		Py_DECREF(pArgs);

		if (pyResult)
		{
			return pyResult;
		}

		return NULL;
	}

///<<< END WRITING YOUR CODE

	KbeAgentBase::KbeAgentBase()
	{
///<<< BEGIN WRITING YOUR CODE CONSTRUCTOR

///<<< END WRITING YOUR CODE
	}

	KbeAgentBase::~KbeAgentBase()
	{
///<<< BEGIN WRITING YOUR CODE DESTRUCTOR

///<<< END WRITING YOUR CODE
	}

	behaviac::EBTStatus KbeAgentBase::callPyFunc(behaviac::string funcName)
	{
///<<< BEGIN WRITING YOUR CODE callPyFunc
		behaviac::EBTStatus ans = behaviac::EBTStatus::BT_FAILURE;
		auto res = _callPyFunc(this, funcName, Py_None);
		if (res)
		{
			auto ans = (behaviac::EBTStatus)PyLong_AsLong(res);
		}
		return ans;
		///<<< END WRITING YOUR CODE
	}

	int KbeAgentBase::getFightType()
	{
///<<< BEGIN WRITING YOUR CODE getFightType
		int ans = -1;
		Py_INCREF(pEntity_);
		PyObject* state = PyObject_GetAttrString((PyObject*)pEntity_, "state");
		Py_DECREF(pEntity_);
		if (state)
		{
			Py_DECREF(state);
			ans = PyLong_AsLong(state);
		}
		return ans;
///<<< END WRITING YOUR CODE
	}

	float KbeAgentBase::now()
	{
///<<< BEGIN WRITING YOUR CODE now
		return 0.0f;
///<<< END WRITING YOUR CODE
	}

///<<< BEGIN WRITING YOUR CODE NAMESPACE_UNINIT

///<<< END WRITING YOUR CODE
}

///<<< BEGIN WRITING YOUR CODE FILE_UNINIT

///<<< END WRITING YOUR CODE
