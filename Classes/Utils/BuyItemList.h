#ifndef CONST_BUYITEMLIST_H
#define CONST_BUYITEMLIST_H

#include "Entity.h"

#include "List.h"

#include "Popup.h"

class BuyItemList : public List
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

        Entity* mIcon;
        Entity* mCoinsIcon;
        Entity* mPropertiesIcon;
        Entity* mStars[2];

        Text* mNameText;
        Text* mDescriptionText;
        Text* mPriceText;
        Text* mPowerText;
        Text* mBoughtText;

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

        // ===========================================================
        // Constructors
        // ===========================================================
    
        BuyItemList(CCNode* pParent);
        ~BuyItemList();

        // ===========================================================
        // Methods
        // ===========================================================
        
        // ===========================================================
        // Override Methods
        // ===========================================================

        void onEnter();
};

#endif