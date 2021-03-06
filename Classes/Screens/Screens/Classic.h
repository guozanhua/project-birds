#ifndef CONST_CLASSIC_H
#define CONST_CLASSIC_H

#include "Game.h"
#include "End.h"

#include "Confetti.h"
#include "StarParticle.h"

#include "AppDelegate.h"

class Classic : public Game
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

        float mLevelUpTime;
        float mLevelUpTimeElapsed;

        float mLevelUpAnimationTime;
        float mLevelUpAnimationTimeElapsed;

        float mChalangeTime;
        float mChalangeTimeElapsed;
        float mSoundChalangeTimeElapsed;

        bool mIsLevelUpAnimation;
        bool mBonus1Used;

        EntityManager* mConfetti;

        Text* mCountText;
        Text* mBestCountText;
        Text* mGoldLifesCount;
        Text* mLevelUpText;
        Text* mBonusTimeText;
    
        Entity* mBonus1;
    
        // ===========================================================
        // Constructors
        // ===========================================================
    
        Classic();

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

        void levelUp();

        void throwConfetti();
        
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

        // ===========================================================
        // Constructors
        // ===========================================================
    
        static Classic* create();
    
        ~Classic();

        // ===========================================================
        // Methods
        // ===========================================================

        void startGame();
        void runChalange();
        void stopChalange();
        
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);

        void onEnter();
        void onExit();
    
        void onEnterTransitionDidFinish();

        void onGameStarted();
        void onGameEnd();

        void removeLife();
    
        void onTouchButtonsCallback(const int pAction, const int pID);
    
        void keyBackClicked(bool pSound);
};

#endif