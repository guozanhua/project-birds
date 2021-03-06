#ifndef CONST_BIRD
#define CONST_BIRD

#include "Bird.h"

#include "Feather.h"

#include "Game.h"
#include "Loader.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

ccColor3B Bird::COLORS[9] =
 {
    ccc3(246.0, 143.0, 41.0),
    ccc3(224.0, 0.0, 55.0),
    ccc3(204.0, 51.0, 204.0),
    ccc3(51.0, 102.0, 255.0),
    ccc3(0.0, 255.0, 255.0),
    ccc3(255.0, 255.0, 51.0),
    ccc3(0.0, 236.0, 47.0),
    ccc3(209.0, 169.0, 0.0),
    ccc3(64.0, 70.0, 98.0)
};

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Bird::~Bird()
{
    CC_SAFE_RELEASE(this->mLife);
}

Bird::Bird(bool pBonus) :
    ImpulseEntity(pBonus ? "special_birds_sprite@2x.png" : "birds_sprite@2x.png", 14, pBonus ? 8 : 9),
    mChalangeType(0),
    mType(0),
    mShield(0),
    mSoundEffect(0),
    mDestroyAnimationFrames(0),
    mMarkTime(0),
    mMarkTimeElapsed(0),
    mDestroyAnimationTime(0),
    mDestroyAnimationTimeElapsed(0),
    mIsGoingToDestroy(0),
    mSpecialAnimation(0),
    mChalange(0),
    mSpecial(0),
    mBonus(0),
    mLife(0),
	count(0),
    mPT(0),
    mPTE(0),
    mPTEL(0),
    e1(0),
    e2(0),
    mLifeCount(0),
    mInitLifeCount(0)
    {
        this->mBonus = pBonus;
        
        if(this->mBonus)
        {
            this->count = SPECIAL_COUNT;
        }
        else
        {
            this->mMarkTime = 0.02;
            this->mMarkTimeElapsed = 0;
        
            this->mLife = CCProgressTimer::create(Entity::create("birds_life@2x.png"));
            this->mLife->retain();
            this->mLife->setType(kCCProgressTimerTypeRadial);
            this->mLife->setReverseProgress(true);

            this->mSoundEffect = 0;
        
            this->count = COUNT;

            this->mChalange = false;
        }
    }

Bird* Bird::create(bool pBonus)
{
    Bird* entity = new Bird(pBonus);
    entity->autorelease();
    
    return entity;
}

// ===========================================================
// Methods
// ===========================================================

void Bird::init(int pChalangeType, int pSomeData[3])
{
    if(this->mType == TYPE_DANGER) return;

    this->mChalangeType = pChalangeType;
    
    switch(this->mChalangeType)
    {
        case 2:
            
        this->mType = Utils::random(0, Game::GAME_TYPE == Game::GAME_TYPE_PROGRESS ? (Game::LEVEL_COLORS[Game::LEVEL] - 1) : (this->count - 3));
        
        this->setCenterPosition(Utils::probably(50) ? 0 : Options::CAMERA_WIDTH, Options::CAMERA_CENTER_Y + Utils::coord(Utils::randomf(0.0f, 300.0f)));
            
        this->mWeight = Utils::coord(1000.0);
        this->mImpulsePower = Utils::coord(Utils::randomf(200.0, 700.0));
        this->mSideImpulse = Options::CAMERA_CENTER_X / 2;
        this->mSideImpulse = this->getCenterX() < Options::CAMERA_CENTER_X ? -this->mSideImpulse : this->mSideImpulse;

        break;
            
        case 3:
            
        this->mType = TYPE_FLAYER;
            
        this->setCenterPosition(pSomeData[1] == 1 ? (0 - Utils::coord(150) * pSomeData[0]) : Options::CAMERA_WIDTH + Utils::coord(100) * pSomeData[0], pSomeData[2] + Utils::coord(Utils::randomf(-50.0, 50.0) * pSomeData[0]));
            
        this->mWeight = Utils::coord(Utils::randomf(0.0, 100.0));
        this->mImpulsePower = Utils::coord(Utils::randomf(0.0, 300.0));
        this->mSideImpulse = Utils::coord(1250.0);
        this->mSideImpulse = this->getCenterX() < Options::CAMERA_CENTER_X ? -this->mSideImpulse : this->mSideImpulse;
            
        break;
    }
    
    this->setCurrentFrameIndex(this->mType * this->mHorizontalFramesCount);
    
    this->animate(0.05, this->getCurrentFrameIndex() + 5, this->getCurrentFrameIndex() + 5 + 7, 1);
    
    this->setScale(1.0);
    this->setScaleX(this->getCenterX() < Options::CAMERA_CENTER_X ? 1 : -1);
}

int Bird::getType()
{
    return this->mType;
}

// ===========================================================
// Override Methods
// ===========================================================

void Bird::onCreate()
{
    ImpulseEntity::onCreate();
    
    this->mChalangeType = 0;
    this->mShieldShows = false;
    
    Game* game = static_cast<Game*>(this->getParent()->getParent()->getParent());

    if(this->mBonus)
    {
        this->mType = AppDelegate::getRandomBonusBird();
        
        this->setCurrentFrameIndex(this->mType * this->mHorizontalFramesCount);
        
        this->setCenterPosition(Utils::randomf(0.0, Options::CAMERA_WIDTH), 0.0);
        
        this->mWeight = Utils::coord(1500.0);
        this->mImpulsePower = Utils::coord(Utils::randomf(1200.0, 1900.0));
        this->mSideImpulse = Utils::coord(Utils::randomf(100.0, 300.0));
        this->mSideImpulse = this->getCenterX() < Options::CAMERA_CENTER_X ? -this->mSideImpulse : this->mSideImpulse;
    }
    else
    {
        if(game->mChalange)
        {
            this->mType = Utils::random(0, this->count - 3);
        
            this->setCurrentFrameIndex(this->mType * this->mHorizontalFramesCount);

            this->setCenterPosition(Utils::probably(50) ? 0 : Options::CAMERA_WIDTH, Options::CAMERA_CENTER_Y + Utils::coord(Utils::randomf(0.0f, 300.0f)));

            this->mWeight = Utils::coord(1000.0);
            this->mImpulsePower = Utils::coord(Utils::randomf(200.0, 700.0));
            this->mSideImpulse = Utils::coord(250.0);
            this->mSideImpulse = this->getCenterX() < Options::CAMERA_CENTER_X ? -this->mSideImpulse : this->mSideImpulse;
        }
        else
        {
            if(Loader::TYPE == 3)
            {
                this->mType = Utils::random(0, Game::GAME_TYPE == Game::GAME_TYPE_PROGRESS ? (Game::LEVEL_COLORS[Game::LEVEL] - 1) : (this->count - 3));
            }
            else
            {
                this->mType = Utils::probably(Game::PREDICTION ? 30 : 15) ? TYPE_DANGER : Utils::random(0, Game::GAME_TYPE == Game::GAME_TYPE_PROGRESS ? (Game::LEVEL_COLORS[Game::LEVEL] - 1) : (this->count - 3));
            }
        
            this->setCurrentFrameIndex(this->mType * this->mHorizontalFramesCount);

            this->setCenterPosition(Utils::randomf(0.0, Options::CAMERA_WIDTH), 0.0);

            this->mWeight = Utils::coord(1500.0);
            this->mImpulsePower = Utils::coord(Utils::randomf(1200.0, 1900.0));
            this->mSideImpulse = Utils::coord(Utils::randomf(100.0, 300.0));
            this->mSideImpulse = this->getCenterX() < Options::CAMERA_CENTER_X ? -this->mSideImpulse : this->mSideImpulse;
        }
    }

    this->mChalange = game->mChalange;

    this->animate(0.05, this->getCurrentFrameIndex() + 5, this->getCurrentFrameIndex() + 5 + 7, 1);

    this->setScale(1.0);
    this->setScaleX(this->getCenterX() < Options::CAMERA_CENTER_X ? 1 : -1);

    this->mIsGoingToDestroy = false;
    this->mSpecialAnimation = false;

    this->mDestroyAnimationFrames = 0;

    this->mDestroyAnimationTime = 0.1;
    this->mDestroyAnimationTimeElapsed = 0;
    
    if(!this->mLife->getParent())
    {
        this->getParent()->getParent()->addChild(this->mLife);
    }
    
    this->mLife->setVisible(true);
    this->mLife->setPercentage(0);

    this->mInitLifeCount = Game::HEALTH;
    this->mLifeCount = this->mInitLifeCount;
    
    if(this->mType == TYPE_DANGER)
    {
        if(Options::SOUND_ENABLE)
        {
            this->mSoundEffect = SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_BOMB_FUSE);
        }
    
        this->mPT = Game::PREDICTION ? 2.5 : 0.0;
        this->mPTE = 0;
        this->mPTEL = Game::PREDICTION ? 0.2 : 1.0;
        
        if(Game::PREDICTION)
        {
            this->setVisible(false);
            
            this->e1 = static_cast<Entity*>(game->mArrows->create());
            this->e2 = static_cast<Entity*>(game->mPredictionIcons->create());
            
            this->e1->setCenterPosition(this->getCenterX(), Utils::coord(100));
            this->e2->setCenterPosition(this->getCenterX(), Utils::coord(100) + Utils::coord(60));
        }
    }
    else
    {
        this->mPT = 0;
        this->mPTE = 0;
        this->mPTEL = 1;
    }
}

void Bird::onAnimationEnd()
{
    Entity::onAnimationEnd();
    
    if(this->mSpecialAnimation)
    {
        this->mSpecialAnimation = false;
        
        this->animate(0.05, this->mType * this->mHorizontalFramesCount + 5, this->mType * this->mHorizontalFramesCount + 5 + 7, 1);
    }
    else
    {
        if(Utils::probably(50))
        {
            this->mSpecialAnimation = true;
            
            this->animate(0.05, this->mType * this->mHorizontalFramesCount, this->mType * this->mHorizontalFramesCount + 5 + 7, 1);
        }
        else
        {
            this->animate(0.05, this->mType * this->mHorizontalFramesCount + 5, this->mType * this->mHorizontalFramesCount + 5 + 7, 1);
        }
    }
}

void Bird::onDestroy()
{
    ImpulseEntity::onDestroy();
    
    Game* game = static_cast<Game*>(this->getParent()->getParent()->getParent());

    this->mLife->setVisible(false);

    if(game)
    {
        if(game->mGameRunning)
        {
            if(this->mLifeCount <= 0 && this->mType != TYPE_DANGER && !this->mBonus && !Game::LASERGUN)
            {
                AppDelegate::addTotalBirdsKilled(1, this->mType);
                
                for(int i = 0; i < 3; i++)
                {
                    Game::mAchievementsBirdsBlowCount[i] += 1;
                }
            }
            
            if(this->mLifeCount > 0 && this->mType != TYPE_DANGER && !this->mChalange && !this->mBonus && this->mChalangeType != 3 && !Game::LASERGUN)
            {
                game->removeLife();
            }
            else
            {
                if(this->mChalange || this->mChalangeType == 3 || this->mBonus)
                {
                    if(this->mLifeCount <= 0)
                    {
                        game->onBirBlow(this->mType, this->getCenterX(), this->getCenterY(), this->mBonus);
                    }
                }
                else
                {
                    if(Game::GAME_TYPE == Game::GAME_TYPE_ARCADE)
                    {
                        if(this->mLifeCount <= 0) game->onBirBlow(this->mType, this->getCenterX(), this->getCenterY(), this->mBonus);
                    }
                    else
                    {
                        game->onBirBlow(this->mType, this->getCenterX(), this->getCenterY(), this->mBonus);
                    }
                }

                if(this->mType == TYPE_DANGER)
                {
                    if(this->mSoundEffect != 0)
                    {
                        SimpleAudioEngine::sharedEngine()->stopEffect(this->mSoundEffect);
                    }
                }
            }
        }
        
        if(this->mLifeCount <= 0 && this->mType == TYPE_FLAYER)
        {
            Game::FLAYER_COUNT++;
            
            if(this->mLifeCount <= 0)
            {
                if(Utils::probably(40))
                {
                    game->mKeys->create()->setCenterPosition(this->getCenterX(), this->getCenterY());
                    
                    AppDelegate::addCoins(1, Options::SAVE_DATA_COINS_TYPE_KEYS);
                }
            }
        }
    }
    
    if(this->mBonus && this->mLifeCount <= 0)
    {
        game->onBonus(this->mType, this->getCenterX(), this->getCenterY());
    }
}

void Bird::update(float pDeltaTime)
{
    this->mPTE += pDeltaTime;
    
    pDeltaTime *= this->mPTEL;
    
    if(this->mPTEL < 1 && this->isVisible())
    {
        this->mPTEL += 0.005;
    }
    
    if(this->mPTE >= this->mPT)
    {
        if(Game::ZOMBIE_AREA)
        {
            this->mLifeCount -= 0.01;
        }
        
        if(this->mType == TYPE_DANGER && static_cast<Game*>(this->getParent()->getParent()->getParent())->mArrows->getCount() > 0 && !this->isVisible())
        {
            this->e1->destroy();
            this->e2->destroy();
        }
        
        if(this->mType == TYPE_DANGER && !this->isVisible())
        {
            this->setVisible(true);
        }
        
    ImpulseEntity::update(pDeltaTime);
    
    Game* game = static_cast<Game*>(this->getParent()->getParent()->getParent());

    this->mMarkTimeElapsed += pDeltaTime;
    
    if(this->mMarkTimeElapsed >= this->mMarkTime)
    {
        this->mMarkTimeElapsed = 0;
        
        if(this->mChalangeType == 3 || this->mBonus)
        {
            for(int i = 0; i < 5; i++)
            {
                StarParticle* entity = static_cast<StarParticle*>(game->mStars->create());
            
                entity->initAsParticle();
                entity->setCenterPosition(this->getCenterX(), this->getCenterY() + Utils::randomf(-this->getHeight() / 2, this->getHeight() / 2));
                
                if(this->mBonus)
                {
                    switch(this->mType)
                    {
                        case 0:
                            entity->setColor(ccc3(0, 200, 255));
                        break;
                        case 1:
                            entity->setColor(ccc3(255, 120, 30));
                        break;
                        case 2:
                            entity->setColor(ccc3(0, 100, 255));
                        break;
                        case 3:
                            entity->setColor(ccc3(36, 178, 27));
                        break;
                        case 4:
                            entity->setColor(ccc3(224, 117, 118));
                        break;
                        case 5:
                            entity->setColor(ccc3(205, 0, 15));
                        break;
                        case 6:
                            entity->setColor(ccc3(123, 171, 55));
                        break;
                        case 7:
                            entity->setColor(ccc3(62, 49, 176));
                        break;
                    }
                }
            }
        }
        else
        {
            Entity* entity = game->mMarks->create();
            
            entity->setCenterPosition(this->getCenterX(), this->getCenterY());
            
            if(this->mType == TYPE_DANGER)
            {
                entity->setColor(ccc3(255.0, 0, 0));
            }
            else
            {
                entity->setColor(ccc3(255, 255, 255));
            }
        }
    }
        
        if(true)
        {
            if(this->mLifeCount < this->mInitLifeCount)
            this->mLife->setPercentage((this->mLifeCount / this->mInitLifeCount * 100.0));
            
            if(this->mLifeCount <= 0)
            {
                Entity* explosionBasic = static_cast<Entity*>(game->mExplosionsBasic->create());
                Entity* explosion = static_cast<Entity*>(game->mExplosions->create());
                
                explosionBasic->setCenterPosition(this->getCenterX(), this->getCenterY() - Utils::coord(15));
                
                explosion->setCenterPosition(this->getCenterX(), this->getCenterY());
                explosion->setColor(COLORS[this->mType]);
                
                if(this->mType != TYPE_DANGER && !this->mBonus)
                {
                    for(int i = 0; i < 15; i++)
                    {
                        Feather* feather = (Feather*) game->mFeathers->create();
                        
                        feather->setCenterPosition(this->getCenterX(), this->getCenterY());
                        feather->setCurrentFrameIndex(Utils::random(2 * this->mType, 2 * this->mType + 1));
                        feather->init(i, 15.0);
                    }
                }
                
                if(this->mChalangeType == 3)
                {
                    for(int i = 0; i < 10; i++)
                    {
                        if(Utils::probably(25))
                        {
                            game->mCoins->create()->setCenterPosition(this->getCenterX(), this->getCenterY());
                        }
                        else
                        {
                            game->mSilverCoins->create()->setCenterPosition(this->getCenterX(), this->getCenterY());
                        }
                    }
                }
                
                if(Options::SOUND_ENABLE)
                {
                    if(this->mType == TYPE_DANGER)
                    {
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_DANGER_EXPLOSION);
                    }
                    else
                    {
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_BIRD_BLOW);
                    }
                }
                
                this->destroy();
            
                return;
            }
        }

    /** Collisions and destroy animation **/

        if(!this->mIsGoingToDestroy && !Game::mShouldShowEndScreen)
    {
        for(int i = 0; i < 10; i++)
        {
            if(this->isCollideWithPoint(Options::TOUCH_INFORMATION[i]) && Options::TOUCH_INFORMATION[i].slice)
            {
                this->mIsGoingToDestroy = true;
            }
        }
    }
    
    if(this->mIsGoingToDestroy)
    {
        this->mDestroyAnimationTimeElapsed += pDeltaTime;

        if(this->mDestroyAnimationTimeElapsed >= this->mDestroyAnimationTime)
        {
            this->mDestroyAnimationTimeElapsed = 0;

            if(this->mDestroyAnimationFrames == 0 && false)
            {
                this->runAction(CCScaleTo::create(this->mDestroyAnimationTime, 1.3 * this->getScaleX(), 1.3));

                this->mDestroyAnimationFrames++;
            }
            else
            {
                if(this->mLifeCount > 0 && !this->mBonus)
                {
                    this->setScaleX(1.3 * (this->getScaleX() > 0 ? 1.0 : -1.0));
                    this->setScaleY(1.3);

                    this->runAction(CCScaleTo::create(this->mDestroyAnimationTime, this->getScaleX() > 0 ? 1.0 : -1.0, 1.0));

                    this->mIsGoingToDestroy = false;
                    this->mDestroyAnimationFrames = 0;

                    this->mLifeCount -= atoi(Options::SHOP_ITEMS_PROPERTIES[Options::SELECTED_WEAPON_ID]);

                    this->mLife->setPercentage((this->mLifeCount / this->mInitLifeCount * 100.0));
                }

                if(this->mLifeCount <= 0 || this->mType == TYPE_DANGER || this->mBonus || this->mChalangeType == 3)
                {
                    this->mLifeCount = 0;
                    
                    {
                        Entity* explosionBasic = static_cast<Entity*>(game->mExplosionsBasic->create());
                        Entity* explosion = static_cast<Entity*>(game->mExplosions->create());

                        explosionBasic->setCenterPosition(this->getCenterX(), this->getCenterY() - Utils::coord(15));

                        explosion->setCenterPosition(this->getCenterX(), this->getCenterY());
                        explosion->setColor(this->mBonus ? SpecialBird::COLORS[this->mType] : COLORS[this->mType]);
                    }
                    

                    if(this->mType != TYPE_DANGER && !this->mBonus)
                    {
                        for(int i = 0; i < 15; i++)
                        {
                            Feather* feather = (Feather*) game->mFeathers->create();

                            feather->setCenterPosition(this->getCenterX(), this->getCenterY());
                            feather->setCurrentFrameIndex(Utils::random(2 * this->mType, 2 * this->mType + 1));
                            feather->init(i, 15.0);
                        }
                    }
                    
                    if(this->mChalangeType == 3)
                    {
                        for(int i = 0; i < 10; i++)
                        {
                            if(Utils::probably(25))
                            {
                                game->mCoins->create()->setCenterPosition(this->getCenterX(), this->getCenterY());
                            }
                            else
                            {
                                game->mSilverCoins->create()->setCenterPosition(this->getCenterX(), this->getCenterY());
                            }
                        }
                    }
                    
                    if(Options::SOUND_ENABLE)
                    {
                        if(this->mType == TYPE_DANGER)
                        {
                            SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_DANGER_EXPLOSION);
                        }
                        else
                        {
                            SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_BIRD_BLOW);
                        }
                    }

                    this->destroy();

                    if(this->mType == TYPE_DANGER)
                    {
                        game->removeLife();
                    }
                }
                else
                {
                    if(Options::SOUND_ENABLE)
                    {
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_HIT);
                    }
                }
            }
        }
    }
    
        this->mLife->setPosition(ccp(this->getCenterX() + Utils::coord(5) * (this->getScaleX() > 0.0 ? 1.0 : - 1.0), this->getCenterY()));
    }
    else
    {
        Entity::update(pDeltaTime);
    }
    
    Game* game = static_cast<Game*>(this->getParent()->getParent()->getParent());
    
    if(this->mImpulsePower <= 0 && !game->mChalange && !this->mShieldShows && AppDelegate::isItemBought(40) && this->mType != TYPE_DANGER && this->mType != TYPE_FLAYER && !this->mBonus)
    {
        this->mShieldShows = true;
        
        this->mShield = game->mShield->create();
        this->mShield->setCenterPosition(this->getCenterX(), this->getCenterY());
        
        this->mLifeCount /= 2;
    }
    
    if(this->mShield != 0)
    {
        if(this->mShield->isVisible())
        {
            this->mShield->setCenterPosition(this->getCenterX(), this->getCenterY());
        }
        else
        {
            this->mShield = 0;
        }
    }
}

Bird* Bird::deepCopy()
{
    return Bird::create(this->mBonus);
}

#endif