#ifndef CONST_PROGRESS
#define CONST_PROGRESS

#include "Progress.h"

#include "Settings.h"

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

Progress::~Progress()
{
    CC_SAFE_RELEASE(this->mResetPopup);
}

Progress::Progress() :
	mBackground(0),
	mBackButton(0),
	mResetButton(0),
	mResetPopup(0)
	{
		SpriteBatch* spriteBatch1 = SpriteBatch::create("TextureAtlas2");
		SpriteBatch* spriteBatch2 = SpriteBatch::create("TextureAtlas2");
    
		ccBlendFunc function1 = {GL_ONE, GL_ZERO};
		ccBlendFunc function2 = {GL_ONE, GL_ONE_MINUS_SRC_ALPHA};

		spriteBatch1->setBlendFunc(function1);
		spriteBatch2->setBlendFunc(function2);
    
		this->addChild(spriteBatch1);
		this->addChild(spriteBatch2);

		EntityStructure structure1 = {"btn_sprite@2x.png", 1, 1, 162, 0, 162, 162};

		this->mBackground = Entity::create("settings_bg@2x.png", spriteBatch1);
		this->mBackButton = Button::create(structure1, spriteBatch2, Options::BUTTONS_ID_PROGRESS_BACK, this);
    
		this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);

		this->mBackButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(100));
    
		this->mResetButton = Button::create("settings_btn_big@2x.png", 1, 1, spriteBatch2, Options::BUTTONS_ID_PROGRESS_RESET, this);

		this->mResetButton->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(200));
		this->mResetButton->setText(Options::TEXT_PROGRESS_RESET);

		Text* text1 = Text::create(Options::TEXT_PROGRESS_STRING_1, CCSize(Utils::coord(700), 0), this);

		text1->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(300));

		this->mResetPopup = ResetProgress::create(this);
        
        if(Options::DEVICE_TYPE == Options::DEVICE_TYPE_IPAD_RETINA)
        {
            this->mBackground->setScale(1.185);
        }
        
        AppDelegate::clearCache();
	}

Progress* Progress::create()
{
    Progress* screen = new Progress();
    screen->autorelease();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Progress::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_PROGRESS_BACK:
                
                this->keyBackClicked(false);
                
            break;
            case Options::BUTTONS_ID_PROGRESS_RESET:
                
                this->mResetPopup->show();
                
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

void Progress::keyBackClicked(bool pSound)
{
    Screen::keyBackClicked(pSound);
    
    if(this->mResetPopup->getParent())
    {
        this->mResetPopup->hide();
    }
    else
    {
        AppDelegate::screens->set(Settings::create());
    }
}

#endif