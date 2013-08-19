#ifndef CONST_BUTTON_H
#define CONST_BUTTON_H

#include "cocos2d.h"

#include "Entity.h"
#include "Text.h"

using namespace cocos2d;

class Button : public Entity
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

        int mID;

        Text* mText;

        void (*mOnTouchCallback)(int, int);
    
        bool mIsModal;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        Button(const char* pTextureFileName, int pHorizontalFramesCount, int mVerticalFramesCount, CCNode* pParent, const int pButtonID, void (*pOnTouchCallback)(int, int));
        Button(const char* pTextureFileName, int pHorizontalFramesCount, int mVerticalFramesCount, const int pButtonID, void (*pOnTouchCallback)(int, int));
        Button(const EntityStructure pEntityStructure, CCNode* pParent, const int pButtonID, void (*pOnTouchCallback)(int, int));

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

        void constructor(const int pButtonID, void (*pOnTouchCallback)(int, int));
        
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

        static Button* create(const char* pTextureFileName, int pHorizontalFramesCount, int mVerticalFramesCount, CCNode* pParent, const int pButtonID, void (*pOnTouchCallback)(int, int));
        static Button* create(const char* pTextureFileName, int pHorizontalFramesCount, int mVerticalFramesCount, const int pButtonID, void (*pOnTouchCallback)(int, int));
        static Button* create(const EntityStructure pEntityStructure, CCNode* pParent, const int pButtonID, void (*pOnTouchCallback)(int, int));
       
        // ===========================================================
        // Constructors
        // ===========================================================

        // ===========================================================
        // Methods
        // ===========================================================

        virtual void onTouch(CCTouch* touch, CCEvent* event);

        void setText(Textes pParams);
        void setString(const char* pString);
        void setModal(bool pIsModal);
        
        // ===========================================================
        // Override Methods
        // ===========================================================

        void update(float pDeltTime);
    
        void onEnter();
        void onExit();
    
        Button* deepCopy();
    
        Entity* create();
};

#endif