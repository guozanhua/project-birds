#ifndef CONST_PROGRESSES_H
#define CONST_PROGRESSES_H

#include "Game.h"
#include "End.h"

#include "Pause.h"

#include "AppDelegate.h"

#include "Color.h"
#include "ColorParticle.h"
#include "GetShoots.h"

class TaskPanel;

class Progresses : public Game
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
    
        Entity* mPanelStars[3];
        Entity* mTaskTimeIcon;
        Entity* mTaskShootsIcon;
    
        Text* mPanelText0;
        Text* mPanelText1;
        Text* mPanelText2;
        Text* mTaskText[5];
        Text* mAwesomeText;
    
        Button* mShootsButton;
        Button* mKeysButton;
    
        EntityManager* mColorsSmall;
        EntityManager* mTasksBackground;
        EntityManager* mShootsDecorations;
    
        Popup* mGetShootsPopup;
    
        float mNewColorsTime;
        float mNewColorsTimeElapsed;
    
        float mAwesoneAnimationTimeElapsed;
        float mShootsCountAnimationTimeElapsed;
    
        bool mAwesoneAnimation;
        bool mMustShowTask;
    
        TaskPanel* mTaskPanel;
    
        // ===========================================================
        // Constructors
        // ===========================================================
    
        Progresses();

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
    
        int mShootCount;
        int mShootMakeCount;
    
        static Progresses* create();
    
        ~Progresses();
    
        EntityManager* mColorsParticles;
        EntityManager* mColorEffectClearHorizontal;
        EntityManager* mColorEffectClearVertical;

        // ===========================================================
        // Constructors
        // ===========================================================

        // ===========================================================
        // Methods
        // ===========================================================
    
        void onShow();
    
        void setGamePanelTopLevelIcons();
        void setGamePanelLeftLevelIcons();
    
        void checkStarsRuntime();
        void lookAtTheTasks();
        void standStartEggs();
    
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);
    
        void draw();

        void onEnter();
        void onExit();

        void onGameStarted();
        void onGameEnd();

        void onBirBlow(int pType, float pX, float pY, bool pBonus);
    
        void onTaskComplete();
    
        void onTouchButtonsCallback(const int pAction, const int pID);
    
        void removeLife();
    
        void onBonus(int pId, float pX, float pY);
    
        void onMatch(int count, float a, float b);
    
        void startGame();
    
        void keyBackClicked(bool pSound);
};

#endif