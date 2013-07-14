#ifndef CONST_CONFETTIMANAGER_H
#define CONST_CONFETTIMANAGER_H

#include "cocos2d.h"

#include "Confetti.h"
#include "BatchEntityManager.h"

using namespace cocos2d;

class ConfettiManager : public BatchEntityManager
{
	protected:
		// ===========================================================
		// Inner Classes
		// ===========================================================

		// ===========================================================
		// Constants
		// ===========================================================

		// ===========================================================
		// Fields
		// ===========================================================

		// ===========================================================
		// Constructors
		// ===========================================================

		// ===========================================================
		// Methods
		// ===========================================================

		// ===========================================================
		// Override Methods
		// ===========================================================

	private:
		// ===========================================================
		// Inner Classes
		// ===========================================================

		// ===========================================================
		// Constants
		// ===========================================================

		// ===========================================================
		// Fields
		// ===========================================================

		// ===========================================================
		// Constructors
		// ===========================================================

		// ===========================================================
		// Methods
		// ===========================================================
		
		// ===========================================================
		// Override Methods
		// ===========================================================

	public:
		// ===========================================================
		// Inner Classes
		// ===========================================================

		// ===========================================================
		// Constants
		// ===========================================================

		// ===========================================================
		// Fields
		// ===========================================================

		// ===========================================================
		// Constructors
		// ===========================================================
    
        ConfettiManager(int pCreateCount, Entity* pEntity, CCNode* pScreen);

		// ===========================================================
		// Methods
		// ===========================================================
    
        void init(float pX, float pY);
		
		// ===========================================================
		// Override Methods
		// ===========================================================
};

#endif