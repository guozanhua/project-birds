#ifndef CONST_SPRITEBATCH_H
#define CONST_SPRITEBATCH_H

#include "cocos2d.h"

#include "Options.h"

using namespace cocos2d;

class SpriteBatch : public CCSpriteBatchNode
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

		SpriteBatch();

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
    
        static SpriteBatch* create(const char* pTextureAtlas);

		// ===========================================================
		// Methods
        // ===========================================================
		
		// ===========================================================
		// Override Methods
        // ===========================================================
    
        void draw();
    
        void visit();
};

#endif