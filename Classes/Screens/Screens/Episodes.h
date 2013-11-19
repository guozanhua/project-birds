#ifndef CONST_EPISODES_H
#define CONST_EPISODES_H

#include "Screen.h"

#include "AppDelegate.h"
#include "CCScrollView.h"

using namespace cocos2d::extension;

class Episodes : public Screen
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
    
        Entity* mEpisodes[10];
        Entity* mPersonage;
        Entity* mShareIcon;
    
        EntityManager* mPoints;
        EntityManager* mStars;
        EntityManager* mDots;
    
        CCLayerColor* mDarkLayers[5];
        CCLayerColor* mComingSoon;
    
        Text* mEpisodeText[6];
        Text* mEpisodeNameText[6];
        Text* mStarsText[6];
        Text* mUnlockText[6];
        Text* mFacebookText[2];
    
        CCScrollView* mScroll;
    
        float mScale;
        float mPointsAnimationTimeElapsed;
    
        bool mPointsAnimationRunning;
    
        int mPointsAnimationCounter;
    
        // ===========================================================
        // Constructors
        // ===========================================================
    
        Episodes();

        // ===========================================================
        // Methods
        // ===========================================================

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
    
        static Episodes* create();
    
        ~Episodes();

        // ===========================================================
        // Methods
        // ===========================================================
        
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);
    
        void onEnter();
        void onExit();
    
        void onTouchButtonsCallback(const int pAction, const int pID);
    
        void keyBackClicked();
};

#endif