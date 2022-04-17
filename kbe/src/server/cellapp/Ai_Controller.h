#pragma once
#include "controller.h"
#include "behaviac_generated/types/behaviac_types.h"

namespace KBEngine {

	class AiController : public Controller
	{
	public:
		AiController(Entity* pEntity, KBEShared_ptr<behaviac::Agent> pAiAgentHandler = NULL, uint32 id = 0);
		virtual ~AiController();

		void pAiAgentHandler(KBEShared_ptr<behaviac::Agent> pAiAgentHandler)
		{
			pAiAgentHandler_ = pAiAgentHandler;
		}

		bool InitBehavic();
		bool InitPlayer();
		void updateLoop();

		virtual void destroy();
		virtual void addToStream(KBEngine::MemoryStream& s);
		virtual void createFromStream(KBEngine::MemoryStream& s);

	protected:
		KBEShared_ptr<behaviac::Agent> pAiAgentHandler_;
	};

}