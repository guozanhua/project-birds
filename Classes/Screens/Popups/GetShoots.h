#ifndef CONST_GETSHOOTS_H
#define CONST_GETSHOOTS_H

#include "Popup.h"

class GetShoots : public Popup
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
    
        Text* mExpireTimeText;
    
        int mPurchaseId;

        Button* mGetCoinsButtons[2];
    
        EntityManager* mLights;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        GetShoots(CCNode* pParent, bool pFirst);

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
    
        static GetShoots* create(CCNode* pParent, bool pFirst);
    
        ~GetShoots();

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
};

#endif