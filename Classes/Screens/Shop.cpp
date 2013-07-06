#ifndef CONST_SHOP
#define CONST_SHOP

#include "Shop.h"

// ===========================================================
// Inner Classes
// ===========================================================

class ShopBackButton : public Entity
{
    public:
    ShopBackButton(CCNode* pParent) :
    Entity("btn_sprite@2x.png", 2, 3, pParent)
    {
        this->create()->setCurrentFrameIndex(1);
        this->setCenterPosition(Utils::coord(100), Utils::coord(100));
        this->setRegisterAsTouchable(true);
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
        AppDelegate::screens->set(0.5, Screen::SCREEN_MENU);
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
        Entity::onEnter();
    }
};

class TouchLayer : public CCLayer
{
    protected:
    int mId;
    
    float sX;
    float ssX;
    
    public:
    TouchLayer(const int pId)
    {
        this->mId = pId;
    }
    
    bool ccTouchBegan(CCTouch* touch, CCEvent* event)
    {
        float x = touch->getLocation().x;
        
        this->sX = x;
        this->ssX = this->getPosition().x;
        
        return this->containsTouchLocation(touch);
    }
    
    void ccTouchMoved(CCTouch* touch, CCEvent* event)
    {
        if(this->containsTouchLocation(touch))
        {
            float x = this->ssX + touch->getLocation().x - this->sX;
            
            if(x >= 0) x = 0;
            if(x <= -700) x = -700;
            
            this->setPosition(ccp(x, this->getPosition().y));
            
            for(int i = this->mId * 3; i < this->mId * 3 + 3; i++)
            {
                Entity* wheel = (Entity*) ((Shop*) this->getParent())->mWheels->objectAtIndex(i);
                
                wheel->setRotation(this->getPosition().x);
            }
        }
    }
    
    void ccTouchEnded(CCTouch* touch, CCEvent* event)
    {
        
    }
    
    bool containsTouchLocation(CCTouch* touch)
    {
        float y = touch->getLocation().y;
        
        switch(this->mId)
        {
            case 0:
                if(
                   y < Options::CAMERA_CENTER_Y + Utils::coord(300) + Utils::coord(150) &&
                   y > Options::CAMERA_CENTER_Y + Utils::coord(300) - Utils::coord(100))
                    {
                        return true;
                    }
                break;
            case 1:
                if(
                   y < Options::CAMERA_CENTER_Y + Utils::coord(150) &&
                   y > Options::CAMERA_CENTER_Y - Utils::coord(100))
                    {
                        return true;
                    }
                break;
            case 2:
                if(
                   y < Options::CAMERA_CENTER_Y - Utils::coord(300) + Utils::coord(150) &&
                   y > Options::CAMERA_CENTER_Y - Utils::coord(300) - Utils::coord(100))
                    {
                        return true;
                    }
                break;
        }
        
        return false;
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
        CCLayer::onEnter();
    }
    
    void onExit()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->removeDelegate(this);
        
        CCLayer::onExit();
    }
};

// ===========================================================
// Constants
// ===========================================================

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Shop::Shop()
{
    this->mBackground = new Entity("settings_bg@2x.png", this);
    this->mTablet = new Entity("shop_money_bg@2x.png", this);
    this->mBackButton = new ShopBackButton(this);
    
    this->mWheels = new BatchEntityManager(9, new Entity("shop_wheel@2x.png"), this);
    
    float x = Options::CAMERA_CENTER_X;
    float y = Options::CAMERA_CENTER_Y - Utils::coord(100) + Utils::coord(330);
    
    const char* textes[3] = { "weapons", "characters", "bonuses" };
    
    for(int i = 0; i < 3; i++)
    {
        this->mLayers[i] = new TouchLayer(i);
        
        this->addChild(this->mLayers[i], 2);
        
        this->mShelfs[i] = new EntityManager(2, new Entity("shop_shelf_sprite@2x.png", 1, 2), this->mLayers[i]);
        this->mItems[i] = new BatchEntityManager(10, new Entity("shop_item_icon_test@2x.png"), this->mLayers[i]);
        
        for(int j = 0; j < 3; j++)
        {
            Entity* shelf = (Entity*) this->mShelfs[i]->create();
            
            shelf->setCenterPosition(x + shelf->getWidth() * j - Utils::coord(42) * j, y);
            
            if(j == 0)
            {
                CCLabelTTF* text = CCLabelTTF::create(textes[i], "Apple Casual", Utils::coord(36));
                text->setPosition(ccp(Utils::coord(160), shelf->getHeight() / 2));
                shelf->addChild(text);
                
                shelf->setCurrentFrameIndex(0);
            }
            else
            {
                shelf->setCurrentFrameIndex(1);
            }
        }
        
        for(int j = 0; j < 10; j++)
        {
            Entity* item = (Entity*) this->mItems[i]->create();
            
            item->setCenterPosition(Utils::coord(130) + Utils::coord(230) * j, y + Utils::coord(115));
        }
        
        y -= Utils::coord(300);
    }
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mTablet->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(170), Options::CAMERA_HEIGHT - Utils::coord(110));
    
    x = Options::CAMERA_CENTER_X - Utils::coord(500);
    y = Options::CAMERA_CENTER_Y - Utils::coord(100) + Utils::coord(300);
    
    for(int i = 0; i < 9; i++)
    {
        if(i % 3 == 0 && i != 0)
        {
            x = Options::CAMERA_CENTER_X - Utils::coord(250);
            y -= Utils::coord(300);
        }
        else
        {
            x += Utils::coord(250);
        }
        
        this->mWheels->create()->setCenterPosition(x, y);
    }
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

void Shop::onEnter()
{
    Screen::onEnter();
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < this->mItems[i]->getCount(); j++)
        {
            Entity* item = (Entity*) this->mItems[i]->objectAtIndex(j);
            
            item->runAction(CCMoveTo::create(0.0, ccp(item->getPosition().x + Utils::coord(1000), item->getPosition().y)));
            item->runAction(CCMoveTo::create(0.8 - 0.1 * i, ccp(item->getPosition().x - Utils::coord(1000), item->getPosition().y)));
        }
    }
}

void Shop::onExit()
{
    Screen::onExit();
    
    for(int i = 0; i < 3; i++)
    {
        this->mLayers[i]->setPosition(ccp(0, this->mLayers[i]->getPosition().y));
    }
}

#endif