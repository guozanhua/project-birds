#ifndef CONST_LIST
#define CONST_LIST

#include "List.h"

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

List::List(float pWidth, float pHeight, float pMaxWidth, float pMaxHeight, float pListInitialCenterX, float pListInitialCenterY, const char* pListTextureFileName, CCNode* pParent)
{
    pParent->addChild(this);
    
    this->mListSroll = new Entity(pListTextureFileName, this);
    this->mListSroll->create()->setRepeatTexture(true);

    this->mWidth = pWidth;
    this->mHeight = pHeight;

    this->mMaxWidth = pMaxWidth;
    this->mMaxHeight = pMaxHeight;

    this->mListInitialCenterX = pListInitialCenterX;
    this->mListInitialCenterY = pListInitialCenterY;
    
    this->mType = TYPE_BOTH;
    this->mParentType = PARENT_TYPE_SIMPLE;

    this->mPostUpdate = false;

    this->scheduleUpdate();
}

// ===========================================================
// Methods
// ===========================================================

void List::setListType(int pType)
{
    this->mType = pType;
}

void List::setParentType(int pType)
{
    this->mParentType = pType;
}

// ===========================================================
// Virtual Methods
// ===========================================================

void List::update(float pDeltaTime)
{
    CCLayer::update(pDeltaTime);

    if(this->mPostUpdate)
    {
        float x = this->getPosition().x;
        float y = this->getPosition().y;

        this->setPosition(ccp(x, y - this->mSpeedY));

        this->mSpeedY -= this->mLastDistanceY > 0 ? 0.5 : -0.5;

        if(y < 0)
        {
            this->runAction(CCMoveTo::create(0.3, ccp(x, 0)));

            this->mPostUpdate = false;
        }
        else if(y > this->mMaxHeight)
        {
            this->runAction(CCMoveTo::create(0.3, ccp(x, this->mMaxHeight)));
            
            this->mPostUpdate = false;
        }

        if(x > 0)
        {
            this->runAction(CCMoveTo::create(0.3, ccp(0, y)));
            
            this->mPostUpdate = false;
        }
        else if(x < -this->mMaxWidth)
        {
            this->runAction(CCMoveTo::create(0.3, ccp(this->mMaxWidth, y)));
            
            this->mPostUpdate = false;
        }

        if(this->mLastDistanceY > 0 ? this->mSpeedY <= 0.0 : this->mSpeedY >= 0.0)
        {
            this->mPostUpdate = false;
        }
    }

    this->mListSroll->setTextureRect(CCRectMake(0, this->getPosition().y, this->mListSroll->getTextureRect().size.width, this->mHeight));
    this->mListSroll->setCenterPosition(this->mListInitialCenterX + this->getPosition().x, this->mListInitialCenterY - this->getPosition().y);
}

bool List::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    this->stopAllActions();

    this->mPostUpdate = false;
    
    this->mStartCoordinateX = touch->getLocation().x;
    this->mStartCoordinateY = touch->getLocation().y;

    this->mStartPositionCoordinateX = this->getPosition().x;
    this->mStartPositionCoordinateY = this->getPosition().y;
    
    return this->containsTouchLocation(touch);
}

void List::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
    if(this->containsTouchLocation(touch))
    {
        float x, y;

        if(this->mType == TYPE_BOTH)
        {
            x = this->mStartPositionCoordinateX + touch->getLocation().x - this->mStartCoordinateX;
            y = this->mStartPositionCoordinateY + touch->getLocation().y - this->mStartCoordinateY;
        }
        else if(this->mType == TYPE_HORIZONTAL)
        {
            x = this->mStartPositionCoordinateX + touch->getLocation().x - this->mStartCoordinateX;
            y = this->getPosition().y;
        }
        else if(this->mType == TYPE_VERTICAL)
        {
            x = this->getPosition().x;
            y = this->mStartPositionCoordinateY + touch->getLocation().y - this->mStartCoordinateY;
        }
        
        this->setPosition(ccp(x, y));
    }
}

void List::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
    float x = this->getPosition().x;
    float y = this->getPosition().y;

    bool kWillPostUpdate = true;

    if(y < 0)
    {
        this->runAction(CCMoveTo::create(0.3, ccp(x, 0)));

        kWillPostUpdate = false;
    }
    else if(y > this->mMaxHeight)
    {
        this->runAction(CCMoveTo::create(0.3, ccp(x, this->mMaxHeight)));

        kWillPostUpdate = false;
    }

    if(x > 0)
    {
        this->runAction(CCMoveTo::create(0.3, ccp(0, y)));

        kWillPostUpdate = false;
    }
    else if(x < -this->mMaxWidth)
    {
        this->runAction(CCMoveTo::create(0.3, ccp(this->mMaxWidth, y)));

        kWillPostUpdate = false;
    }

    this->mLastDistanceX = this->mStartPositionCoordinateX - x; // TODO: Check it!
    this->mLastDistanceY = this->mStartPositionCoordinateY - y;

    this->mPostUpdate = kWillPostUpdate;

    this->mSpeedY = this->mLastDistanceY / 10.0;
}

bool List::containsTouchLocation(CCTouch* touch)
{
    float x = touch->getLocation().x;
    float y = touch->getLocation().y;

    if(this->mParentType == PARENT_TYPE_SIMPLE)
    {
        return x > this->mListInitialCenterX - this->mWidth / 2 && x < this->mListInitialCenterX + this->mWidth / 2 && y < this->mListInitialCenterY + this->mHeight / 2 && y > this->mListInitialCenterY - this->mHeight / 2;
    }
    else if(this->mParentType == PARENT_TYPE_POPUP)
    {
        return x > Options::CAMERA_CENTER_X - this->mWidth / 2 && x < Options::CAMERA_CENTER_X + this->mWidth / 2 && y < Options::CAMERA_CENTER_Y + this->mHeight / 2 && y > Options::CAMERA_CENTER_Y - this->mHeight / 2&& ((Popup*) this->getParent()->getParent())->mShowed;
    }
    
    return false;
}

void List::onEnter()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    
    CCLayer::onEnter();
}

void List::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
    
    CCLayer::onExit();
}

void List::visit()
{
    kmGLPushMatrix();
    glEnable(GL_SCISSOR_TEST);

    if(this->mParentType == PARENT_TYPE_SIMPLE)
    {
        CCEGLView::sharedOpenGLView()->setScissorInPoints(this->mListInitialCenterX - this->mWidth / 2, this->mListInitialCenterY - this->mHeight / 2, this->mWidth, this->mHeight);
    }
    else if(this->mParentType == PARENT_TYPE_POPUP)
    {
        CCEGLView::sharedOpenGLView()->setScissorInPoints(Options::CAMERA_CENTER_X - this->mWidth / 2, Options::CAMERA_CENTER_Y - this->mHeight / 2, this->mWidth, this->mHeight);
    }

    CCNode::visit();
    glDisable(GL_SCISSOR_TEST);
    kmGLPopMatrix();
}

void List::draw()
{
    CCLayer::draw();
}

#endif