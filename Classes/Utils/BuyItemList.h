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

        Text* mNameText;
        Text* mDescriptionText;
        Text* mPriceText;
        Text* mPowerText;
        Text* mBoughtText;

        BatchEntityManager* mStars;

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

        // ===========================================================
        // Methods
        // ===========================================================
        
        // ===========================================================
        // Override Methods
        // ===========================================================

        void onEnter();
};

#endif