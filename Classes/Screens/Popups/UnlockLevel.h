#ifndef CONST_UNLOCKLEVEL_H
#define CONST_UNLOCKLEVEL_H

#include "Popup.h"

class UnlockLevel : public Popup
{
    protected:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================
    
        static UnlockLevel* m_Instance;

        // ===========================================================
        // Fields
        // ===========================================================
    
        Entity* mKey;
    
        Button* mUnlockButton;
    
        Text* mPriceText;
    
        EntityManager* mLights;
    
        bool action;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        UnlockLevel(CCNode* pParent);

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
    
        static UnlockLevel* create(CCNode* pParent);

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
};

#endif