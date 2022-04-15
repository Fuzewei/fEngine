#include "Ai_Controller.h"

namespace KBEngine {


	//-------------------------------------------------------------------------------------
	AiController::AiController(Entity* pEntity, KBEShared_ptr<behaviac::Agent> pAiAgentHandler = NULL, uint32 id = 0) :
		Controller(Controller::CONTROLLER_TYPE_AI, pEntity, 0, id),
		pAiAgentHandler_(pAiAgentHandler)
	{
	}

	//-------------------------------------------------------------------------------------
	AiController::~AiController()
	{
		// DEBUG_MSG(fmt::format("MoveController::~MoveController(): {:p}\n", (void*)this);
		
	}

	//-------------------------------------------------------------------------------------
	void AiController::addToStream(KBEngine::MemoryStream& s)
	{
		Controller::addToStream(s);

		
	}

	//-------------------------------------------------------------------------------------
	void AiController::createFromStream(KBEngine::MemoryStream& s)
	{
		
	}

	//-------------------------------------------------------------------------------------
	void AiController::destroy()
	{


		// 既然自己要销毁了，那么与自己相联的updatable也应该停止了
		
	}

	//-------------------------------------------------------------------------------------
}