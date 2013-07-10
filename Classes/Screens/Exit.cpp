#ifndef CONST_EXIT
#define CONST_EXIT

#include "Exit.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

Exit* Exit::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Exit::Exit(Screen* pScreen) :
    Popup(pScreen)
    {
        this->mCloseButton = new Button("btn_sprite@2x.png", 2, 3, this->mBackground, Options::BUTTONS_ID_POPUP_CLOSE, onTouchButtonsCallback);
        this->mIllustration = new Entity("popup_quit_picture@2x.png", this->mBackground);
    
        this->mYesButton = new Button("popup_btn@2x.png", 1, 1, this->mBackground, Options::BUTTONS_ID_EXIT_YES, onTouchButtonsCallback);
        
        this->mYesButton->create()->setCenterPosition(this->mBackground->getWidth() / 2, Utils::coord(40));
        this->mYesButton->setText(Options::TEXT_EXIT_YES);
        
        this->mCloseButton->create();
        this->mCloseButton->setCenterPosition(this->mBackground->getWidth() - Utils::coord(40), this->mBackground->getHeight() - Utils::coord(40));
        this->mCloseButton->setCurrentFrameIndex(3);
        
        Text* text1 = new Text(Options::TEXT_EXIT_STRING_1, this->mBackground);
        Text* text2 = new Text(Options::TEXT_EXIT_STRING_2, this->mBackground);
        
        text1->setPosition(ccp(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 - Utils::coord(50)));
        text2->setPosition(ccp(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 - Utils::coord(150)));
        
        this->mIllustration->create()->setCenterPosition(this->mBackground->getWidth() / 2, this->mBackground->getHeight() - Utils::coord(140));
        
        m_Instance = this;
    }

// ===========================================================
// Methods
// ===========================================================

void Exit::onTouchButtonsCallback(const int pAction, const int pID)
{
    Exit* pSender = (Exit*) Exit::m_Instance;
    
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
                pSender->hide();
                
                break;
            case Options::BUTTONS_ID_EXIT_YES:
                
                pSender->hide();
                
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
// Virtual Methods
// ===========================================================

#endif