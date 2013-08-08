#ifndef CONST_GAME_H
#define CONST_GAME_H

#include "Screen.h"

#include "End.h"

#include "Bird.h"
#include "Mark.h"
#include "Feather.h"
#include "Explosion.h"
#include "ExplosionBasic.h"
#include "Dust.h"
#include "EventPanel.h"

#include "Pause.h"

#include "TouchTrailLayer.h"

#include "AppDelegate.h"

class Game : public Screen
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
    
        int mBirdsRemaning;
        int mStartGameAnimationIndex;

        float mBirdsTime;
        float mBirdsTimeElapsed;

        float mStartGameAnimation;
        float mStartGameAnimationElapsed;

        bool mGameRunning;
        bool mGamePaused;

        Entity* mBackground;
        Entity* mCountIcon;

        EventPanel* mEventPanel;

        Button* mPauseButton;

        Text* mGameStartText;

        Popup* mPausePopup;

        End* mEndScreen;

        CCLayer* mEventLayer;
    
        // ===========================================================
        // Constructors
        // ===========================================================

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

        static int CURRENT_COUNT;
        static int BEST_COUNT;
        static int LIFES;
        static int HEALTH;

        // ===========================================================
        // Fields
        // ===========================================================

        bool mChalange;

        BatchEntityManager* mBirds;
        BatchEntityManager* mMarks;
        BatchEntityManager* mFeathers;
        BatchEntityManager* mExplosionsBasic;
        BatchEntityManager* mExplosions;
        BatchEntityManager* mDust;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        Game();

        // ===========================================================
        // Methods
        // ===========================================================

        virtual void startGame();
        virtual void onGameStarted();
        virtual void onGameEnd();
        virtual void removeLife();
        
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);
        
        void onEnter();
        void onExit();
};

#endif