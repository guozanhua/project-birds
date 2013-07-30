#ifndef CONST_MENU_H
#define CONST_MENU_H

#include "Screen.h"

#include "Exit.h"
#include "PleaseRate.h"

#include "PlayButton.h"

#include "AppDelegate.h"

class Menu : public Screen
{
    protected:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================

        static Menu* m_Instance;

        // ===========================================================
        // Fields
        // ===========================================================
    
        Entity* mBackground;
        Entity* mPlayDecoration;
        Entity* mPlayButton;
        Entity* mShopButton;
        Entity* mTwitterButton;
        Entity* mFacebookButton;
        Entity* mSettingsButton;
    
        Popup* mExitPopup;
        Popup* mRatePopup;

        float mPlayDecorationColorUpdateTimeElapsed;

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

        // ===========================================================
        // Constructors
        // ===========================================================
    
        Menu();

        // ===========================================================
        // Methods
        // ===========================================================
        
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);

        void onEnter();
        void onExit();
};

#endif