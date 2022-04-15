#pragma once
#include "controller.h"
#include "src/behaviac_generated/types/behaviac_types.h"

namespace KBEngine {

	class AiController : public Controller
	{
	public:
		AiController(Entity* pEntity, KBEShared_ptr<behaviac::Agent> pAiAgentHandler = NULL, uint32 id = 0);
		virtual ~AiController();

		void pMoveToPointHandler(KBEShared_ptr<behaviac::Agent> pAiAgentHandler)
		{
			pAiAgentHandler_ = pAiAgentHandler;
		}

		virtual void destroy();
		virtual void addToStream(KBEngine::MemoryStream& s);
		virtual void createFromStream(KBEngine::MemoryStream& s);

	protected:
		KBEShared_ptr<behaviac::Agent> pAiAgentHandler_;
	};

}