#ifndef CONST_BOUGHTITEM
#define CONST_BOUGHTITEM

#include "BoughtItem.h"
#include "EziSocialObject.h"

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

BoughtItem::~BoughtItem()
{
    CC_SAFE_RELEASE(this->mLights);
    CC_SAFE_RELEASE(this->mConfetti);
    
    this->removeAllChildrenWithCleanup(true);
}

BoughtItem::BoughtItem(CCNode* pParent) :
	mParent(0),
	mIcon(0),
	mTwitterButton(0),
	mFacebookButton(0),
	mVkButton(0),
	mShareButton(0),
	mLights(0),
	mConfetti(0),
	mTextes(),
	mShowAnimationTimeElapsed(0),
	mHideAnimationTimeElapsed(0),
	mShowAnimation(0),
	mHideAnimation(0),
	mTapToContinueAnimationReverse(0),
	mShare(0)
	{
		this->initWithColor(ccc4(0.0, 0.0, 0.0, 200.0));

		this->mParent = pParent;

		this->setCascadeOpacityEnabled(true);
    
		SpriteBatch* spriteBatch = SpriteBatch::create("TextureAtlas4");
		SpriteBatch* spriteBatch2 = SpriteBatch::create("TextureAtlas9");
		SpriteBatch* spriteBatch3 = SpriteBatch::create("TextureAtlas4");
    
		this->mLights = EntityManager::create(2, Entity::create("get_coins_light@2x.png"), spriteBatch2);
		this->mIcon = Entity::create("shop_item_icon@2x.png", 10, 6, this);
		this->mIcon->setZOrder(2);
    
		this->mConfetti = EntityManager::create(600, Confetti::create(), spriteBatch3);
    
		this->mShareButton = Button::create("share@2x.png", 1, 1, spriteBatch, Options::BUTTONS_ID_SHARE, this);
		this->mTwitterButton = Button::create("twitter_icon@2x.png", 1, 1, spriteBatch, Options::BUTTONS_ID_SHARE_TWITTER, this);
		this->mFacebookButton = Button::create("facebook_icon@2x.png", 1, 1, spriteBatch, Options::BUTTONS_ID_SHARE_FACEBOOK, this);
		this->mVkButton = Button::create("vk_icon@2x.png", 1, 1, spriteBatch, Options::BUTTONS_ID_SHARE_VK, this);
    
		this->mTextes[0] = Text::create(Options::TEXT_SHOP_BOUGHT, this);
		this->mTextes[1] = Text::create(Options::TEXT_SHOP_BOUGHT, this);
		this->mTextes[2] = Text::create(Options::TEXT_TAP_TO_CONTINUE, this);

		this->mIcon->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        
		for(int i = 0; i < 2; i++)
		{
			this->mLights->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
			static_cast<Entity*>(this->mLights->objectAtIndex(i))->setScale(3.0);
		}
    
		this->mShareButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(100), Utils::coord(100));
		this->mTwitterButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(100), Utils::coord(250));
		this->mFacebookButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(100), Utils::coord(350));
		this->mVkButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(100), Utils::coord(450));
        
        this->mTwitterButton->setScaleX(0);
        this->mFacebookButton->setScaleX(0);
        this->mVkButton->setScaleX(0);
        
        this->mTwitterButton->setScaleY(0);
        this->mFacebookButton->setScaleY(0);
        this->mVkButton->setScaleY(0);

		this->mTwitterButton->setModal(true);
		this->mFacebookButton->setModal(true);
		this->mVkButton->setModal(true);
		this->mShareButton->setModal(true);

		this->mTextes[0]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(300));
		this->mTextes[1]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(380));
		this->mTextes[2]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(450));
    
		this->addChild(spriteBatch2);
		this->addChild(spriteBatch);
		this->addChild(spriteBatch3);
    
		spriteBatch3->setZOrder(3);
    
		this->mTapToContinueAnimationReverse = false;
		this->mShowAnimation = false;
		this->mHideAnimation = false;
		this->mShare = false;
    
		this->setRegisterAsTouchable(true);
    
		this->mLights->setOpacity(0);
	}

BoughtItem* BoughtItem::create(CCNode* pParent)
{
    BoughtItem* popup = new BoughtItem(pParent);
    popup->autorelease();
    popup->retain();
    
    return popup;
}

// ===========================================================
// Methods
// ===========================================================

void BoughtItem::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_SHARE:
                
                this->mTwitterButton->runAction(CCScaleTo::create(0.1, this->mShare ? 0.0 : 1.0));
                this->mFacebookButton->runAction(CCScaleTo::create(0.2, this->mShare ? 0.0 : 1.0));
                this->mVkButton->runAction(CCScaleTo::create(0.3, this->mShare ? 0.0 : 1.0));
                
                this->mShare = !this->mShare;
                
            break;
            case Options::BUTTONS_ID_SHARE_TWITTER:
                
                EziSocialObject::sharedObject()->tweet("123", "");
                
            break;
            case Options::BUTTONS_ID_SHARE_FACEBOOK:
                
                EziSocialObject::sharedObject()->postMessageOnWall("EziSocial Plugin by EziByte",
                                                                   "Have you tried it?",
                                                                   "Try EziSocial Plugin developed by EziByte team to harness the power of Facebook APIs in your games",
                                                                   "Try EziSocial Plugin developed by EziByte team to harness the power of Facebook APIs in your games",
                                                                   "https://1.gravatar.com/avatar/5c85a0424f7948506baed85755bc0f8d",
                                                                   "http://ezibyte.com");
                
            break;
            case Options::BUTTONS_ID_SHARE_VK:
                
                //
                
            break;
        }
        break;
            
        case Options::BUTTONS_ACTION_ONBEGIN:
        break;
            
        case Options::BUTTONS_ACTION_ONEND:
        break;
    }
}

void BoughtItem::show(int pItemId)
{
    this->mParent->addChild(this, 100);

    this->mTextes[0]->setString(Options::TEXT_SHOP_ITEMS[pItemId].string);

    this->mTextes[0]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(300));
    this->mTextes[1]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(380));

    this->mIcon->setCurrentFrameIndex(pItemId);

    this->setOpacity(0.0);
    this->runAction(CCFadeTo::create(0.5, 230.0));
    
    this->mShowAnimation = true;
    this->mShowAnimationTimeElapsed = 0;
}

void BoughtItem::hide()
{
    this->runAction(CCFadeTo::create(0.5, 0.0));
    
    for(int i = 0; i < this->mConfetti->getCount(); i++)
    {
        static_cast<Entity*>(this->mConfetti->objectAtIndex(i))->runAction(CCFadeTo::create(0.5, 0));
    }

    this->mHideAnimation = true;
    this->mHideAnimationTimeElapsed = 0;
}

void BoughtItem::onShow()
{
    this->mShowAnimation = false;
    
    this->throwConfetti();
}

void BoughtItem::onHide()
{
    this->mHideAnimation = false;

    this->removeFromParentAndCleanup(false);
}

void BoughtItem::throwConfetti()
{
    this->mConfetti->clear();
    
    float x = 0;
    float y = Utils::coord(200);
    
    for(int i = 0; i < 10; i++)
    {
        for(int j = -(Options::CAMERA_CENTER_X / Utils::coord(40)); j <= (Options::CAMERA_CENTER_X / Utils::coord(40)); j++)
        {
            x = Utils::coord(Utils::randomf(40.0, 40.0)) * j;
            
            this->mConfetti->create()->setCenterPosition(Options::CAMERA_CENTER_X + x, Options::CAMERA_HEIGHT + y);
        }
        
        y -= Utils::coord(Utils::randomf(5.0, 10.0));
    }
}

// ===========================================================
// Override Methods
// ===========================================================

void BoughtItem::update(float pDeltaTime)
{
    CCLayerColor::update(pDeltaTime);
    
    for(int i = 0; i < 2; i++)
    {
        Entity* light = static_cast<Entity*>(this->mLights->objectAtIndex(i));
            
        light->setRotation(light->getRotation() + ((i == 0) ? Utils::randomf(0.0, 0.1) : Utils::randomf(-0.1, 0.0)));
    }

    if(this->mHideAnimation)
    {
        this->mHideAnimationTimeElapsed += pDeltaTime;

        if(this->mHideAnimationTimeElapsed >= 0.5)
        {
            this->mHideAnimationTimeElapsed = 0;

            this->onHide();
        }
    }
    
    if(this->mShowAnimation)
    {
        this->mShowAnimationTimeElapsed += pDeltaTime;
        
        if(this->mShowAnimationTimeElapsed >= 0.5)
        {
            this->mShowAnimationTimeElapsed = 0;
            
            this->onShow();
        }
    }
    
    if(!this->mShowAnimation && !this->mHideAnimation)
    {
        if(this->mTapToContinueAnimationReverse)
        {
            this->mTextes[2]->setOpacity(this->mTextes[2]->getOpacity() - 5.0);
            
            if(this->mTextes[2]->getOpacity() <= 20.0)
            {
                this->mTapToContinueAnimationReverse = !this->mTapToContinueAnimationReverse;
            }
        }
        else
        {
            this->mTextes[2]->setOpacity(this->mTextes[2]->getOpacity() + 5.0);
            
            if(this->mTextes[2]->getOpacity() >= 245.0)
            {
                this->mTapToContinueAnimationReverse = !this->mTapToContinueAnimationReverse;
            }
        }
    }
    
    this->mLights->setOpacity(this->getOpacity());
    this->mShareButton->setOpacity(this->getOpacity());
    this->mVkButton->setOpacity(this->getOpacity());
    this->mFacebookButton->setOpacity(this->getOpacity());
    this->mTwitterButton->setOpacity(this->getOpacity());
}

void BoughtItem::onTouch(CCTouch* touch, CCEvent* event)
{
    this->hide();
    
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate((Touchable*) this);
    
    this->setRegisterAsTouchable(false);
}

void BoughtItem::onEnter()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate((Touchable*) this, 0, true);
       
    CCLayer::onEnter();
    
    this->scheduleUpdate();
    
    this->mShare = false;
    
    this->mTwitterButton->setScaleX(0);
    this->mFacebookButton->setScaleX(0);
    this->mVkButton->setScaleX(0);
    
    this->mTwitterButton->setScaleY(0);
    this->mFacebookButton->setScaleY(0);
    this->mVkButton->setScaleY(0);
    
    this->setRegisterAsTouchable(true);
}
    
void BoughtItem::onExit()
{
    CCLayer::onExit();

    this->stopAllActions();
    this->unscheduleAllSelectors();
    
    this->mConfetti->clear();
}

#endif