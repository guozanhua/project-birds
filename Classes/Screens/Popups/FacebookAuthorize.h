#ifndef CONST_FACEBOOKAUTHORIZE_H
#define CONST_FACEBOOKAUTHORIZE_H

#include "EziSocialDelegate.h"

#include "Popup.h"

class FacebookAuthorize : public Popup, public EziFacebookDelegate
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

        Button* mCancelButton;

        Text* mTextes[2];
    
        Button* mResetButton;
    
        EntityManager* mLights;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        FacebookAuthorize(CCNode* pParent);

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
    
        bool mAction;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        static FacebookAuthorize* create(CCNode* pParent);
    
        ~FacebookAuthorize();

        // ===========================================================
        // Methods
        // ===========================================================
    
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        virtual void update(float pDeltaTime);
    
        virtual void hide();
        virtual void show();
    
        virtual void onShow();
        virtual void onHide();
    
        void onTouchButtonsCallback(const int pAction, const int pID);
    
        virtual void fbSessionCallback(int responseCode, const char* responseMessage);
        virtual void fbUserDetailCallback(int responseCode, const char* responseMessage, EziFacebookUser* fbUser);
};

#endif