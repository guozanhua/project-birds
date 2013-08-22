#ifndef CONST_LOADER_H
#define CONST_LOADER_H

#include "Screen.h"

class Loader : public Screen
{
    protected:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================
    
        static TextureStructure TEXTURE_LIBRARY[5];

        // ===========================================================
        // Fields
        // ===========================================================
    
        int mNumberOfSprites;
        int mNumberOfLoadedSprites;
    
        float mCircleAnimationTime;
        float mCircleAnimationTimeElapsed;

        float mLoadingTime;
        float mLoadingTimeElapsed;
    
        bool mTapToContinueAnimation;
        bool mTapToContinueAnimationReverse;
    
        bool mIsWorkDone;
        bool mLoading;
    
        Entity* mBackground;
        Entity* mBird;
    
        Text* mLoadingText;
        Text* mTipText;
    
        EntityManager* mCircles;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        Loader();

        // ===========================================================
        // Methods
        // ===========================================================
    
        void loadingCallBack(CCObject *obj);

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

        static int ACTION;

        // ===========================================================
        // Fields
        // ===========================================================

        // ===========================================================
        // Constructors
        // ===========================================================
    
        static Loader* create();
    
        ~Loader();

        // ===========================================================
        // Methods
        // ===========================================================

        void startLoading();
        
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);
    
        void onEnterTransitionDidFinish();
        void onExitTransitionDidStart();

        void onEnter();
        void onExit();
    
        void onTouch(CCTouch* touch, CCEvent* event);
};

#endif