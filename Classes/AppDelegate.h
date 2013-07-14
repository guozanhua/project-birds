#ifndef CONST_APPDELEGATE_H
#define CONST_APPDELEGATE_H

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

#include <vector>

#include "Options.h"
#include "ScreenManager.h"

using namespace std;
using namespace cocos2d;
using namespace CocosDenshion;

class ScreenManager;

typedef struct tagResource {
    CCSize size;
    char directory[100];
} Resource;

static Options options;

static Resource resources480x320 = { CCSizeMake(320, 480),  "Graphics/480x320" };
static Resource resources1280x720 = { CCSizeMake(720, 1280),  "Graphics/1280x720" };
static CCSize   designResolutionSize = CCSizeMake(720, 1280);

class AppDelegate : private CCApplication
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

        static ScreenManager* screens;

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

        bool applicationDidFinishLaunching();

        void applicationDidEnterBackground();
        void applicationWillEnterForeground();
};

#endif