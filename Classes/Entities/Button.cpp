#ifndef CONST_BUTTON
#define CONST_BUTTON

#include "Button.h"

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

Button::Button(const char* pTextureFileName, int pHorizontalFramesCount, int mVerticalFramesCount, CCNode* pParent, const int pButtonID, void (*pOnTouchCallback)(int, int)) :
	Entity(pTextureFileName, pHorizontalFramesCount, mVerticalFramesCount, pParent)
	{
		this->mOnTouchCallback = pOnTouchCallback;

		this->mID = pButtonID;

    	this->setRegisterAsTouchable(true);
	}

Button::Button(const char* pTextureFileName, int pHorizontalFramesCount, int mVerticalFramesCount, const int pButtonID, void (*pOnTouchCallback)(int, int)) :
Entity(pTextureFileName, pHorizontalFramesCount, mVerticalFramesCount)
{
    this->mOnTouchCallback = pOnTouchCallback;
    
    this->mID = pButtonID;
    
    this->setRegisterAsTouchable(true);
}

// ===========================================================
// Methods
// ===========================================================
    
void Button::onTouch(CCTouch* touch, CCEvent* event)
{
	if(this->mOnTouchCallback != 0)
    {
        this->mOnTouchCallback(Options::BUTTONS_ACTION_ONTOUCH, this->mID);
    }
}

void Button::setText(Textes pParams)
{
	this->mText = new Text(pParams, this);
	this->mText->setPosition(ccp(this->getWidth() / 2, this->getHeight() / 2));
}

void Button::setString(const char* pString)
{
	this->mText->setString(pString);
}

// ===========================================================
// Virtual Methods
// ===========================================================
    
void Button::onEnter()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
    Entity::onEnter();
}
    
void Button::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
        
    Entity::onExit();
}

Button* Button::deepCopy()
{
    return new Button(this->mTextureFileName, this->mHorizontalFramesCount, this->mVerticalFramesCount, this->mID, this->mOnTouchCallback);
}

#endif