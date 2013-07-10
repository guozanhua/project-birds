#ifndef CONST_TEXT
#define CONST_TEXT

#include "Text.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

int Text::ID = 0;

Text* Text::TEXTES[32] =
{
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Text::Text(const char* pString, float pSize, CCNode* pParent)
{
    this->initWithString(pString, "Apple casual", Utils::coord(pSize), CCSize(0, 0), kCCTextAlignmentCenter);
	//this->enableShadow(CCSize(Utils::coord(5), -Utils::coord(5)), 255.0, 0.0, true);
    
    this->mId = 0;
    
    pParent->addChild(this);
    
    TEXTES[ID] = this;
    
    ID++;
}

Text::Text(Textes pParams, CCNode* pParent)
{
    this->initWithString(pParams.string, pParams.font, pParams.size, CCSize(0, 0), kCCTextAlignmentCenter);
	//this->enableShadow(CCSize(Utils::coord(5), -Utils::coord(5)), 255.0, 0.0, true);
    
    this->mId = pParams.identifier;
    
    pParent->addChild(this);
    
    TEXTES[ID] = this;
    
    ID++;
}

// ===========================================================
// Methods
// ===========================================================

void Text::setCenterPosition(float pCenterX, float pCenterY)
{
    this->mInitCenterX = pCenterX;
    this->mInitCenterY = pCenterY;
    
    this->setPosition(ccp(pCenterX, pCenterY));
}

void Text::changeLanguage()
{
    if(Options::TEXTES_HOLDER[this->mId].size != 0)
    {
        this->setString(Options::TEXTES_HOLDER[this->mId].string);
        this->setFontSize(Options::TEXTES_HOLDER[this->mId].size);
        this->setFontName(Options::TEXTES_HOLDER[this->mId].font);
    }
}

// ===========================================================
// Virtual Methods
// ===========================================================

#endif