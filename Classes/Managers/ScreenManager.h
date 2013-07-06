#ifndef CONST_SCREENMANAGER_H
#define CONST_SCREENMANAGER_H

#include "cocos2d.h"

#include "Screen.h"

#include "Menu.h"
#include "Settings.h"
#include "Shop.h"
#include "Boxes.h"
#include "Levels.h"
#include "Credits.h"

using namespace cocos2d;

class ScreenManager
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

		Screen* mScreens[6];

		int mCurrentScreenIndex;

		// ===========================================================
		// Constructors
		// ===========================================================

		ScreenManager();

		// ===========================================================
		// Methods
		// ===========================================================

		void generate();
		
		void set(float pAnimationTime, int pIndex);
		
		// ===========================================================
		// Virtual Methods
		// ===========================================================
};

#endif