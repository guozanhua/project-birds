#ifndef CONST_EXPLOSIONBASIC
#define CONST_EXPLOSIONBASIC

#include "ExplosionBasic.h"

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

ExplosionBasic::ExplosionBasic() :
    Entity("explosion_basic@2x.png", 3, 4)
    {
        
    }

ExplosionBasic* ExplosionBasic::create()
{
    ExplosionBasic* entity = new ExplosionBasic();
    entity->autorelease();
    
    return entity;
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

void ExplosionBasic::onAnimationEnd()
{
    this->destroy();
}

void ExplosionBasic::onCreate()
{
    Entity::onCreate();
    
    this->setCurrentFrameIndex(0);
    
    this->animate(0.05, 1);
}
    
ExplosionBasic* ExplosionBasic::deepCopy()
{
    return ExplosionBasic::create();
}
    
void ExplosionBasic::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
}

#endif