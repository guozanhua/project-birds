#ifndef CONST_SETTINGS_H
#define CONST_SETTINGS_H

#include "Screen.h"

#include "AppDelegate.h"

class Settings : public Screen
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
    
        Entity* mBackground;
        Entity* mLanguage;
        Entity* mBackgroundDecorations[2];
    
        Button* mBackButton;
        Button* mCreditsButton;
        Button* mProgressButton;
        Button* mMoreButton;
        Button* mLanguageButton;
        Button* mSoundButton;
        Button* mMusicButton;
    
        // ===========================================================
        // Constructors
        // ===========================================================
    
        Settings();
        ~Settings();

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

        // ===========================================================
        // Constructors
        // ===========================================================

        static Settings* create();

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

        void keyBackClicked(bool pSound);
};

#endif