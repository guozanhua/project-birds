#ifndef CONST_SPLASH_H
#define CONST_SPLASH_H

#include "cocos2d.h"

#include "Entity.h"
#include "Splash.h"

#include "BatchEntityManager.h"

using namespace cocos2d;

class Splash : public CCLayer
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
    
        bool mShowBackground;
    
        float mBackgroundTime;
        float mBackgroundTimeElapsed;
    
        Entity* mBackground;
    
        BatchEntityManager* mParts;

		// ===========================================================
		// Constructors
		// ===========================================================

		// ===========================================================
		// Methods
		// ===========================================================

		// ===========================================================
		// Virtual Methods
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
		// Virtual Methods
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
    
        Splash(CCNode* pParent);

		// ===========================================================
		// Methods
		// ===========================================================
    
        void show();
        void hide();
		
		// ===========================================================
		// Virtual Methods
		// ===========================================================
    
        void update(float pDeltaTime);
};

#endif