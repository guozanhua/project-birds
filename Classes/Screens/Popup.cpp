#ifndef CONST_POPUP
#define CONST_POPUP

#include "Popup.h"

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

Popup::Popup(Screen* pScreen)
{
    this->mScreen = pScreen;
    
    this->mDarkness = new Entity("popup_darkness@2x.png", this);
    this->mBackground = new Entity("popup_bg@2x.png", this);
    
    this->mDarkness->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    
    this->mShowed = false;
    
    this->scheduleUpdate();
    
    this->mBackground->setScale(0.0);
    this->mDarkness->setOpacity(0.0);
    
    this->mScreen->addChild(this, 1000);
}

// ===========================================================
// Methods
// ===========================================================

void Popup::onShow()
{
}

void Popup::onHide()
{
}

void Popup::show()
{
    if(this->mShowed) return;
    
    this->mShowed = true;
    this->mShowAnimationRunning = true;
    
    this->mShowAnimationCount = 0;
    this->mShowAnimationTimeElapsed = 0;
    
    this->mShowAnimationTime = 0.3;
    this->mBackground->runAction(CCScaleTo::create(this->mShowAnimationTime, 1.2));
    this->mDarkness->runAction(CCFadeTo::create(0.5, 130.0));
}

void Popup::hide()
{
    if(!this->mShowed) return;
    
    this->mShowed = false;
    this->mHideAnimationRunning = true;
    
    this->mHideAnimationCount = 0;
    this->mHideAnimationTimeElapsed = 0;
    
    this->mHideAnimationTime = 0.1;
    this->mBackground->runAction(CCScaleTo::create(this->mHideAnimationTime, 1.2));
    this->mDarkness->runAction(CCFadeTo::create(0.3, 0.0));
}

// ===========================================================
// Virtual Methods
// ===========================================================

void Popup::update(float pDeltaTime)
{
    CCLayer::update(pDeltaTime);
    
    if(this->mShowAnimationRunning)
    {
        this->mShowAnimationTimeElapsed += pDeltaTime;
        
        if(this->mShowAnimationTimeElapsed >= this->mShowAnimationTime)
        {
            this->mShowAnimationTimeElapsed = 0;
            
            switch(this->mShowAnimationCount)
            {
                case 0:
                    this->mShowAnimationTime = 0.2;
                    this->mBackground->runAction(CCScaleTo::create(this->mShowAnimationTime, 0.8));
                break;
                case 1:
                    this->mShowAnimationTime = 0.2;
                    this->mBackground->runAction(CCScaleTo::create(this->mShowAnimationTime, 1.0));
                break;
                case 2:
                    this->mShowAnimationRunning = false;
                    
                    this->onShow();
                break;
            }
            
            this->mShowAnimationCount++;
        }
    }
    
    if(this->mHideAnimationRunning)
    {
        this->mHideAnimationTimeElapsed += pDeltaTime;
        
        if(this->mHideAnimationTimeElapsed >= this->mHideAnimationTime)
        {
            this->mHideAnimationTimeElapsed = 0;
            
            switch(this->mHideAnimationCount)
            {
                case 0:
                    this->mHideAnimationTime = 0.2;
                    this->mBackground->runAction(CCScaleTo::create(this->mHideAnimationTime, 0.0));
                break;
                case 1:
                    this->mHideAnimationRunning = false;
                    
                    this->onHide();
                break;
            }
            
            this->mHideAnimationCount++;
        }
    }
}

#endif