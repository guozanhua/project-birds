#ifndef CONST_TEXT_H
#define CONST_TEXT_H

#include "cocos2d.h"

#include "Utils.h"

using namespace cocos2d;

class Text : public CCLabelTTF
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
    
        int mId;

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
    
        static int ID;
    
        static Text* TEXTES[128];

        // ===========================================================
        // Fields
        // ===========================================================
    
        float mInitCenterX;
        float mInitCenterY;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        Text(Textes pParams, const CCSize pDimensions, CCNode* pParent);
        Text(const char* pString, float pSize, CCNode* pParent);
        Text(Textes pParams, CCNode* pParent);

        // ===========================================================
        // Methods
        // ===========================================================
    
        void setCenterPosition(float pCenterX, float pCenterY);
    
        void changeLanguage();

        float getWidth();
        float getHeight();
        
        // ===========================================================
        // Override Methods
        // ===========================================================
};

#endif