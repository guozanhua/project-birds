#ifndef CONST_MAPDESCRIPTION_H
#define CONST_MAPDESCRIPTION_H

#include "Popup.h"

#include "Shop.h"

#include "MapDescriptionList.h"

class MapDescription : public Popup
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
    
        Button* mCloseButton;
    
        Entity* mListBorders[2];
    
        MapDescriptionList* mList;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        MapDescription(Screen* pScreen);

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
    
        static MapDescription* create(Screen* pScreen);
    
        ~MapDescription();

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