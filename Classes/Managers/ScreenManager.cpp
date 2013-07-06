#ifndef CONST_SCREENMANAGER
#define CONST_SCREENMANAGER

#include "ScreenManager.h"

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

ScreenManager::ScreenManager()
{
	this->generate();
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

// ===========================================================
// Getters
// ===========================================================

// ===========================================================
// Setters
// ===========================================================

// ===========================================================
// Methods
// ===========================================================

void ScreenManager::generate()
{
    this->mScreens[Screen::SCREEN_MENU] = new Menu();
    this->mScreens[Screen::SCREEN_SETTINGS] = new Settings();
    this->mScreens[Screen::SCREEN_SHOP] = new Shop();
    this->mScreens[Screen::SCREEN_BOXES] = new Boxes();
    this->mScreens[Screen::SCREEN_LEVELS] = new Levels();
}

void ScreenManager::set(float pAnimationTime, int pIndex)
{
	this->mCurrentScreenIndex = pIndex;
	
	CCTransitionScene* transition = CCTransitionFade::create(pAnimationTime, this->mScreens[pIndex]);

	CCDirector::sharedDirector()->pushScene(transition);
}

// ===========================================================
// Virtual methods
// ===========================================================

#endif