#ifndef CONST_TEMPPUBLISHERINAPPEXPLAIN
#define CONST_TEMPPUBLISHERINAPPEXPLAIN

#include "TempPublisherInAppExplain.h"

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

TempPublisherInAppExplain::~TempPublisherInAppExplain()
{
}

TempPublisherInAppExplain::TempPublisherInAppExplain(CCNode* pParent) :
    Popup(pParent),
	mOkButton(0)
    {
        this->mCloseButton = Button::create("btn_sprite_close@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_POPUP_CLOSE, this);
        this->mOkButton = Button::create("popup_btn@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_BUYITEM_BUY, this);
        
        this->mCloseButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(290), Options::CAMERA_CENTER_Y + Utils::coord(450));
        
        this->mOkButton->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(460));
        this->mOkButton->setText(Options::TEXT_MODEHELP_OK);

        Text* text1 = Text::create(Options::TEXT_PUBLISHER_STRING_1, ccp(Utils::coord(500), 0), this);
        Text* text2 = Text::create(Options::TEXT_PUBLISHER_STRING_4, ccp(Utils::coord(500), 0), this);

        text1->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(250));
        text2->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(100));
    }

TempPublisherInAppExplain* TempPublisherInAppExplain::create(CCNode* pParent)
{
    TempPublisherInAppExplain* popup = new TempPublisherInAppExplain(pParent);
    popup->autorelease();
    popup->retain();
    
    return popup;
}

// ===========================================================
// Methods
// ===========================================================

void TempPublisherInAppExplain::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            default:
                
                this->hide();
                
            break;
        }
        break;
            
        case Options::BUTTONS_ACTION_ONBEGIN:
        break;
            
        case Options::BUTTONS_ACTION_ONEND:
        break;
    }
}

// ===========================================================
// Override Methods
// ===========================================================

#endif