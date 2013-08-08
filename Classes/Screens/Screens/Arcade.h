#ifndef CONST_ARCADE_H
#define CONST_ARCADE_H

#include "Game.h"
#include "ArcadePause.h"
#include "ArcadeEnd.h"

#include "AppDelegate.h"

#include "Clock.h"

class Arcade : public Game
{
    protected:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================

        static Arcade* m_Instance;

        // ===========================================================
        // Fields
        // ===========================================================
        
        Clock* mTimeIcon;

        Text* mCountText;
        Text* mBestCountText;
        Text* mTimeText[3];
    
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

        static void onTouchButtonsCallback(const int pAction, const int pID);
        
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
    
        Arcade();

        // ===========================================================
        // Constructors
        // ===========================================================

        // ===========================================================
        // Methods
        // ===========================================================

        void startGame();
        
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);

        void onEnter();
        void onExit();

        void onGameStarted();
        void onGameEnd();
};

#endif