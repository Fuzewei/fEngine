#include "Ai_Controller.h"
#include "resmgr/resmgr.h"

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
		std::string exportPath = Resmgr::getSingleton().getPyUserResPath() + g_kbeSrvConfig.behaviacExportPath_;
		behaviac::Workspace::GetInstance()->SetFilePath(exportPath.c_str());
		behaviac::Workspace::GetInstance()->SetFileFormat(behaviac::Workspace::EFF_xml);
		return true;
	}

	//-------------------------------------------------------------------------------------
	bool AiController::InitPlayer()
	{
		return true;
	}

	//-------------------------------------------------------------------------------------
	void AiController::destroy()
	{


		// 既然自己要销毁了，那么与自己相联的updatable也应该停止了
		
	}

	//-------------------------------------------------------------------------------------
}