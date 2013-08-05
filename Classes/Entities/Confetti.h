#ifndef CONST_CONFETTI_H
#define CONST_CONFETTI_H

#include "cocos2d.h"

#include "Entity.h"

using namespace cocos2d;

class Confetti : public Entity
{
    protected:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================

        static ccColor3B COLORS[3];

        // ===========================================================
        // Fields
        // ===========================================================
    
        float mSpeedX;
        float mSpeedY;
    
        float mWeight;
    
        float mRotationSpeed;
        float mAlphaSpeed;
    
        bool mMoveUp;
        bool mAppear;

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
    
        Confetti();

        // ===========================================================
        // Methods
        // ===========================================================
    
        void onCreate();
        
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);
    
        Confetti* deepCopy();
};

#endif