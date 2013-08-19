#ifndef CONST_RESETPROGRESS_H
#define CONST_RESETPROGRESS_H

#include "cocos2d.h"

#include "Popup.h"
#include "Text.h"
#include "BatchEntityManager.h"

#include "AppDelegate.h"

using namespace cocos2d;

class ResetProgress : public Popup
{
    protected:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================
    
        static ResetProgress* m_Instance;

        // ===========================================================
        // Fields
        // ===========================================================
    
        Button* mResetButton;
    
        bool mAction;
    
        EntityManager* mLights;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        ResetProgress(CCNode* pParent);
    
        ~ResetProgress();

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
    
        static ResetProgress* create(CCNode* pParent);

        // ===========================================================
        // Methods
        // ===========================================================
    
        void hide();
    
        void onShow();
        void onHide();
        
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);
};

#endif