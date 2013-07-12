#ifndef CONST_MODE
#define CONST_MODE

#include "Mode.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

Mode* Mode::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Mode::Mode()
{
    this->mBackground = new Entity("settings_bg@2x.png", this);
    this->mBackButton = new Button("btn_sprite@2x.png", 2, 3, this, Options::BUTTONS_ID_MODE_BACK, onTouchButtonsCallback);

    this->mClassicMode = new Button("settings_btn_big@2x.png", 1, 1, this, Options::BUTTONS_ID_MODE_CLASSIC, onTouchButtonsCallback);
    this->mArcadeMode = new Button("settings_btn_big@2x.png", 1, 1, this, Options::BUTTONS_ID_MODE_ARCADE, onTouchButtonsCallback);
    this->mProgressMode = new Button("settings_btn_big@2x.png", 1, 1, this, Options::BUTTONS_ID_MODE_PROGRESS, onTouchButtonsCallback);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    
    this->mBackButton->create()->setCurrentFrameIndex(1);
    this->mBackButton->setCenterPosition(Utils::coord(100), Utils::coord(100));

    this->mClassicMode->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(250));
    this->mArcadeMode->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mProgressMode->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(250));

    this->mClassicMode->setText(Options::TEXT_MODE_CLASSIC);
    this->mArcadeMode->setText(Options::TEXT_MODE_ARCADE);
    this->mProgressMode->setText(Options::TEXT_MODE_PROGRESS);
}

// ===========================================================
// Methods
// ===========================================================

void Mode::onTouchButtonsCallback(const int pAction, const int pID)
{
    Mode* pSender = (Mode*) Mode::m_Instance;

    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_MODE_BACK:

                    AppDelegate::screens->set(0.5, Screen::SCREEN_MENU);

                break;
                case Options::BUTTONS_ID_MODE_CLASSIC:

                    //

                break;
                case Options::BUTTONS_ID_MODE_ARCADE:

                    //

                break;
                case Options::BUTTONS_ID_MODE_PROGRESS:

                    AppDelegate::screens->set(0.5, Screen::SCREEN_LEVELS);

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