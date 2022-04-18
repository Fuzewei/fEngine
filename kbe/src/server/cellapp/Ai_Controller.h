#pragma once
#include "controller.h"
#include "behaviac_generated/types/behaviac_types.h"

namespace KBEngine {

	class AiController : public Controller
	{
	public:
		AiController(Entity* pEntity, std::string path,behaviac::KbeAgentBase* pAiAgentHandler = NULL, uint32 id = 0);
		virtual ~AiController();

		void pAiAgentHandler(behaviac::KbeAgentBase* pAiAgentHandler)
		{
			pAiAgentHandler_ = pAiAgentHandler;
		}
		bool Init();
		bool InitBehavic();
		bool InitPlayer();
		void CleanupPlayer();
		behaviac::EBTStatus updateLoop();
		virtual void destroy();
		virtual void addToStream(KBEngine::MemoryStream& s);
		virtual void createFromStream(KBEngine::MemoryStream& s);

	protected:
		behaviac::EBTStatus status = behaviac::BT_INVALID;
		behaviac::KbeAgentBase* pAiAgentHandler_;
		std::string filePath;
	};

}