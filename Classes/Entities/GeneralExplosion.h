#ifndef CONST_GENERALEXPLOSION_H
#define CONST_GENERALEXPLOSION_H

#include "Entity.h"

class GeneralExplosion : public Entity
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
    
        GeneralExplosion();

        // ===========================================================
        // Methods
        // ===========================================================

        // ===========================================================
        // Virtual Methods
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
        // Virtual Methods
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
    
        static GeneralExplosion* create();

        // ===========================================================
        // Methods
        // ===========================================================
        
        // ===========================================================
        // Virtual Methods
        // ===========================================================
    
        void update(float pDeltaTime);
    
        void onAnimationEnd();
        void onCreate();
    
        GeneralExplosion* deepCopy();
};

#endif