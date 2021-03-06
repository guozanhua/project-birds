#ifndef CONST_MENU_H
#define CONST_MENU_H

#include "Screen.h"

#include "Exit.h"
#include "Map.h"
#include "PleaseRate.h"
#include "MapDescription.h"
#include "TempPublisherInAppExplain.h"
#include "GooglePlayAuthorize.h"
#include "FacebookAuthorize.h"

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

        // ===========================================================
        // Fields
        // ===========================================================
    
        Entity* mTutorial;
    
        Entity* mBackground;
        Entity* mPlayDecoration[2];
        Entity* mPlayButton;
        Entity* mShopButton;
        Entity* mTwitterButton;
        Entity* mFacebookButton;
        Entity* mVkButton;
        Entity* mSettingsButton;

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
    
        Popup* mExitPopup;
        Popup* mRatePopup;
        Popup* mMapDescription;
        Popup* mTempPublisherInAppExplainPopup;
        GooglePlayAuthorize* mGooglePlayAuthorizePopup;
        FacebookAuthorize* mFacebookAuthorizePopup;
    
        Map* mMapPopup;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        Menu();
        ~Menu();

        static Menu* create();

        // ===========================================================
        // Methods
        // ===========================================================
    
        void onShow();
        
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);

        void onEnter();
        void onExit();

        void onExitTransitionDidStart();
        void onEnterTransitionDidFinish();
    
        void onTouchButtonsCallback(const int pAction, const int pID);
    
        #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        void keyBackClicked(bool pSound);
        #endif
    
        void onGooglePlusSignInSucceeded();
};

#endif