#ifndef CONST_SHOP_H
#define CONST_SHOP_H

#include "Screen.h"

#include "BuyItem.h"
#include "GetCoins.h"

#include "Item.h"

#include "AppDelegate.h"

class TouchLayer;

class Shop : public Screen
{
    protected:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================

        static Shop* m_Instance;

        // ===========================================================
        // Fields
        // ===========================================================

        int mCoins;
    
        Entity* mBackground;
        Entity* mCoin;
        
        Button* mBackButton;
        Button* mTablet;

        Entity* mDarkness;

        Text* mCoinsCountText;
        Text* mBoughtText[2];

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

        static int ITEMS_COUNT[3];

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

        static int CLICKED_ITEM_ID;

        // ===========================================================
        // Fields
        // ===========================================================
    
        BatchEntityManager* mWheels;
        BatchEntityManager* mItems[3];
        EntityManager* mShelfs[3];
        
        TouchLayer* mLayers[3];
    
        Popup* mBuyItemPopup;
        Popup* mGetCoinsPopup;

        EntityManager* mLights;

        Entity* mBoughtItemIcon;

        float mAnimationOnItemBoughtTime;
        float mAnimationOnItemBoughtTimeElapsed;

        bool mIsAnimationOnItemBoughtRunning;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        Shop();

        // ===========================================================
        // Methods
        // ===========================================================

        void onItemBought(int pItemId);
        
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);

        void onEnter();
        void onExit();
};

#endif