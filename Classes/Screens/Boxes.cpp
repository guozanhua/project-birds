#ifndef CONST_BOXES
#define CONST_BOXES

#include "Boxes.h"

// ===========================================================
// Inner Classes
// ===========================================================

class BoxesBackButton : public Entity
{
    public:
    BoxesBackButton(CCNode* pParent) :
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
    
    void onExit()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->removeDelegate(this);
        
        Entity::onExit();
    }
};

class BoxesTouchLayer : public CCLayer
{
    protected:
    CCPoint mBeganPoint;
    
    public:
    BoxesTouchLayer()
    {
        
    }
    
    bool ccTouchBegan(CCTouch* touch, CCEvent* event)
    {
        this->mBeganPoint = touch->getLocation();
        
        return this->containsTouchLocation(touch);
    }
    
    void ccTouchMoved(CCTouch* touch, CCEvent* event)
    {
        if(this->containsTouchLocation(touch))
        {
        }
    }
    
    void ccTouchEnded(CCTouch* touch, CCEvent* event)
    {
        float distance = touch->getLocation().x - this->mBeganPoint.x;
        
        if(abs(distance) < Utils::coord(10.0))
        {
            AppDelegate::screens->set(0.5, Screen::SCREEN_LEVELS);
        }
        else
        {
           if(distance < 0)
           {
               this->runAction(CCMoveTo::create(0.3, ccp(this->getPosition().x - Options::CAMERA_WIDTH, this->getPosition().y)));
           }
           else
           {
               this->runAction(CCMoveTo::create(0.3, ccp(this->getPosition().x + Options::CAMERA_WIDTH, this->getPosition().y)));
           }
        }
    }
    
    bool containsTouchLocation(CCTouch* touch)
    {
        float y = touch->getLocation().y;
        
        if(y > Utils::coord(300))
        {
            return true;
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

Boxes::Boxes()
{
    this->mBackground = new Entity("settings_bg@2x.png", this);
    this->mBackButton = new BoxesBackButton(this);
    this->mTablet = new Entity("choose_box_name@2x.png");
    
    this->addChild(this->mTablet, 5);
    
    this->mNavigations = new BatchEntityManager(3, new Entity("choose_box_navi_sprite@2x.png", 1, 2), this);
    
    this->mTouchLayer = new BoxesTouchLayer();
    
    this->addChild(this->mTouchLayer);
    
    const char* boxes[3] = { "choose_box_summer@2x.png", "choose_box_winter@2x.png", "choose_box_space@2x.png" };
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mTablet->create()->setCenterPosition(Utils::coord(280), Options::CAMERA_HEIGHT - Utils::coord(170));
    this->mTablet->setRotation(-15);
    
    float x = Options::CAMERA_CENTER_X - Utils::coord(150);
    float y = Options::CAMERA_CENTER_Y - Utils::coord(350);
    
    for(int i = 0; i < 3; i++)
    {
        Entity* entity = (Entity*) this->mNavigations->create();
        
        entity->create()->setCenterPosition(x, y);
        
        if(i == 0)
        {
            entity->setCurrentFrameIndex(1);
        }
        else
        {
            entity->setCurrentFrameIndex(0);
        }
        
        x += Utils::coord(150);
    }
    
    for(int i = 0; i < 3; i++)
    {
        this->mBoxes[i] = new Entity(boxes[i], this->mTouchLayer);
        
        this->mBoxes[i]->create()->setCenterPosition(Options::CAMERA_CENTER_X + Options::CAMERA_WIDTH * i, Options::CAMERA_CENTER_Y + Utils::coord(100));
    }
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

#endif