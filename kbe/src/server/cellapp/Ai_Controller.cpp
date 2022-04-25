#include "Ai_Controller.h"
#include "resmgr/resmgr.h"
#include "server/serverconfig.h"

namespace KBEngine {


	//-------------------------------------------------------------------------------------
	AiController::AiController(Entity* pEntity,std::string path, behaviac::KbeAgentBase* pAiAgentHandler, uint32 id) :
		Controller(Controller::CONTROLLER_TYPE_AI, pEntity, 0, id),
		pAiAgentHandler_(pAiAgentHandler), filePath(path)
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
	bool AiController::Init()
	{
		InitBehavic();
		InitPlayer();
		status = behaviac::EBTStatus::BT_RUNNING;
		return true;
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
		pAiAgentHandler_ = behaviac::Agent::Create<behaviac::Monster>();
		pAiAgentHandler_->pEntity_ = pEntity();
		bool bRet = pAiAgentHandler_->btload(filePath.c_str());

		pAiAgentHandler_->btsetcurrent(filePath.c_str());
		return true;
	}

	//-------------------------------------------------------------------------------------
	void AiController::CleanupPlayer()
	{
		behaviac::Agent::Destroy(pAiAgentHandler_);
		pAiAgentHandler_ = nullptr;
	}

	//-------------------------------------------------------------------------------------
	behaviac::EBTStatus AiController::updateLoop()
	{
		
		status = pAiAgentHandler_->btexec();
		
		return status;
	}

	//-------------------------------------------------------------------------------------
	void AiController::destroy()
	{
		CleanupPlayer();
	}

	//-------------------------------------------------------------------------------------
}