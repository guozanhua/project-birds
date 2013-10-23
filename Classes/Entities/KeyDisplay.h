#ifndef CONST_KEYDISPLAY_H
#define CONST_KEYDISPLAY_H

#include "Entity.h"

class KeyDisplay : public Entity
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
    
        int mActionCount;
    
        float mTime;
        float mTimeElapsed;
    
        Entity* mLights[2];

        // ===========================================================
        // Constructors
        // ===========================================================
    
        KeyDisplay();

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
    
        static KeyDisplay* create();

        // ===========================================================
        // Methods
        // ===========================================================
    
        void update(float pDeltaTime);
        
        // ===========================================================
        // Virtual Methods
        // ===========================================================
    
        void setCenterPosition(float pCenterX, float pCenterY);
    
        void onCreate();
        void onDestroy();
    
        KeyDisplay* deepCopy();
};

#endif