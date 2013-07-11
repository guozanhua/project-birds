#ifndef CONST_CREDITS_H
#define CONST_CREDITS_H

#include "cocos2d.h"

#include "Screen.h"
#include "BatchEntityManager.h"
#include "CreditsList.h"

#include "AppDelegate.h"

using namespace cocos2d;

class Credits : public Screen
{
	protected:
		// ===========================================================
		// Inner Classes
		// ===========================================================

		// ===========================================================
		// Constants
		// ===========================================================

        static Credits* m_Instance;

		// ===========================================================
		// Fields
        // ===========================================================
    
        Entity* mBackground;
        Entity* mBackButton;
    
        BatchEntityManager* mListBorders;
    
        CreditsList* mList;

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

		static void onTouchButtonsCallback(const int pAction, const int pID);
		
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
    
        Credits();

		// ===========================================================
		// Methods
		// ===========================================================
		
		// ===========================================================
		// Virtual Methods
		// ===========================================================
    
        void onEnter();
        void onExit();
};

#endif