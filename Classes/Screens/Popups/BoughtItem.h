#ifndef CONST_BOUGHTITEM_H
#define CONST_BOUGHTITEM_H

#include "Entity.h"
#include "Button.h"
#include "EntityManager.h"
#include "Text.h"
#include "Touchable.h"
#include "Confetti.h"

#include "SpriteBatch.h"

class BoughtItem : public CCLayerColor, public Touchable, public ButtonReceiver
{
    protected:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================
    
        static BoughtItem* m_Instance;

        // ===========================================================
        // Fields
        // ===========================================================

        CCNode* mParent;

        Entity* mIcon;

        Button* mTwitterButton;
        Button* mFacebookButton;
        Button* mVkButton;
        Button* mShareButton;
    
        EntityManager* mLights;
        EntityManager* mConfetti;

        Text* mTextes[3];

        float mShowAnimationTimeElapsed;
        float mHideAnimationTimeElapsed;
    
        bool mShowAnimation;
        bool mHideAnimation;
        bool mTapToContinueAnimationReverse;
        
        bool mShare;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        BoughtItem(CCNode* pParent);

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
    
        static BoughtItem* create(CCNode* pParent);
    
        ~BoughtItem();

        // ===========================================================
        // Methods
        // ===========================================================

        void show(int pItemId);
        void hide();

        void onShow();
        void onHide();
    
        void throwConfetti();
        
        // ===========================================================
        // Override Methods
        // ===========================================================

        void update(float pDeltaTime);

        void onEnter();
        void onExit();
    
        void onTouch(CCTouch* touch, CCEvent* event);
    
        void onTouchButtonsCallback(const int pAction, const int pID);
};

#endif