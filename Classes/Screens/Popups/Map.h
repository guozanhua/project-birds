#ifndef CONST_MAP_H
#define CONST_MAP_H

#include "cocos2d.h"

#include "Screen.h"

#include "Entity.h"
#include "Button.h"
#include "Ripple.h"
#include "Confetti.h"
#include "AnimatedCoin.h"
#include "StarParticle2.h"

#include "Utils.h"
#include "Options.h"

#include "BatchEntityManager.h"

using namespace cocos2d;

class BackgroundEntity;

class Map : public CCLayer, public Touchable, public ButtonReceiver
{
        protected:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================

        // ===========================================================
        // Fields
        // ===========================================================
    
        CCNode* mParent;
        Entity* mDarkness;
        BackgroundEntity* mBackground;
		Entity* mScroll;
		CCNodeRGBA* mSquare;
    
		Entity* mName;
        Entity* mDay[5];
		EntityManager* mRipples;
		EntityManager* mWays;
		EntityManager* mCoins;
		EntityManager* mSilverCoins;
        EntityManager* mConfetti;
		EntityManager* mStars;
		EntityManager* mAnimatedCoins;
		EntityManager* mSilverAnimatedCoins;
    
        Button* mCloseButton;
    
        int mShowAnimationCount;
        int mHideAnimationCount;
    
        float mShowAnimationTime;
        float mShowAnimationTimeElapsed;
        
        float mHideAnimationTime;
        float mHideAnimationTimeElapsed;
    
        bool mShowAnimationRunning;
        bool mHideAnimationRunning;
    
        bool mAnimatedCoinsAnimation;
    
        float mAnimatedCoinsAnimationTime;
        float mAnimatedCoinsAnimationTimeElpased;
    
        bool mShowed;
    
		bool mAnimation;
    
		float mAnimationTime;
		float mAnimationTimeElapsed;
    
		int mAnimationCount;
		int mAnimationCount2;
    
		Text* mBonusTextes[5];
		Text* mBonusTextes2[5];

        // ===========================================================
        // Constructors
        // ===========================================================
    
        Map(CCNode* pParent);

        // ===========================================================
        // Methods
        // ===========================================================
    
		void throwAnimation(float x, float y);

        // ===========================================================
        // Override Methods
        // ===========================================================

        private:
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

        // ===========================================================
        // Methods
        // ===========================================================
        
        // ===========================================================
        // Override Methods
        // ===========================================================

        public:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================

        // ===========================================================
        // Fields
		// ===========================================================
    
		int day;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        static Map* create(CCNode* pParent);
    
        ~Map();

        // ===========================================================
        // Methods
        // ===========================================================
    
        virtual void show();
        virtual void hide();
    
        bool isShowed();
    
        virtual void onShow();
        virtual void onHide();
    
        void onAnimationEnd();
    
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);
    
        void draw();
    
        void onEnter();
        void onExit();
    
		bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    
		void onTouchButtonsCallback(const int pAction, const int pID);
};

#endif