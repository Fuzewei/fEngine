#include "Ai_Controller.h"

namespace KBEngine {


	//-------------------------------------------------------------------------------------
	AiController::AiController(Entity* pEntity, KBEShared_ptr<behaviac::Agent> pAiAgentHandler, uint32 id) :
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
	void updateLoop() {

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
	bool AiController::InitBehavic()
	{
		behaviac::Workspace::GetInstance()->SetFilePath("../tutorials/tutorial_1_1/cpp/exported");

		behaviac::Workspace::GetInstance()->SetFileFormat(behaviac::Workspace::EFF_xml);
		return true;
	}

	//-------------------------------------------------------------------------------------
	void AiController::destroy()
	{


		// 既然自己要销毁了，那么与自己相联的updatable也应该停止了
		
	}

	//-------------------------------------------------------------------------------------
}