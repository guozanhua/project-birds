#ifndef CONST_ARCADE_H
#define CONST_ARCADE_H

#include "Game.h"
#include "End.h"

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

        // ===========================================================
        // Fields
        // ===========================================================
        
        Clock* mTimeIcon;

        Text* mCountText;
        Text* mBestCountText;
        Text* mTimeText;
    
        // ===========================================================
        // Constructors
        // ===========================================================
    
        Arcade();

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

        // ===========================================================
        // Fields
        // ===========================================================
    
        static Arcade* create();
    
        ~Arcade();

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
    
        void pause();
    
        void onTouchButtonsCallback(const int pAction, const int pID);
};

#endif