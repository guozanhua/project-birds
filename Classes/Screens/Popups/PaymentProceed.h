#ifndef CONST_PAYMENTPROCEED_H
#define CONST_PAYMENTPROCEED_H

#include "Popup.h"

class PaymentProceed : public Popup
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

        int mUpdateTimes;

        float mUpdateTime;
        float mUpdateTimeElapsed;

        float mUpdateTimeTotal;

        bool mWaitingPurchase;

        Button* mCancelButton;

        Text* mTextes[3];

        // ===========================================================
        // Constructors
        // ===========================================================
    
        PaymentProceed(CCNode* pParent);

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
    
        static PaymentProceed* create(CCNode* pParent);
    
        ~PaymentProceed();

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