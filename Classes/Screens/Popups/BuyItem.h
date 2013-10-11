#ifndef CONST_BUYITEM_H
#define CONST_BUYITEM_H

#include "Popup.h"

#include "Shop.h"

#include "BuyItemList.h"

class BuyItem : public Popup
{
    protected:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================
    
        static BuyItem* m_Instance;

        // ===========================================================
        // Fields
        // ===========================================================
    
        Button* mBuyButton;
    
        bool mYesPressed;
    
        Entity* mListBorders[2];
    
        BuyItemList* mList;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        BuyItem(Screen* pScreen);

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
    
        static BuyItem* create(Screen* pScreen);
    
        ~BuyItem();

        // ===========================================================
        // Methods
        // ===========================================================
        
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void show();
        
        void onShow();
        void onHide();
    
        void onTouchButtonsCallback(const int pAction, const int pID);
};

#endif