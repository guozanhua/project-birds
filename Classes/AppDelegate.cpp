#ifndef CONST_APPDELEGATE
#define CONST_APPDELEGATE

#include "AppDelegate.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

ScreenManager* AppDelegate::screens = NULL;

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

bool AppDelegate::applicationDidFinishLaunching()
{
	CCDirector* director 	= CCDirector::sharedDirector();
	CCEGLView*  EGLView 	= CCEGLView::sharedOpenGLView();
	CCSize 	screenSize 		= EGLView->getFrameSize();
    
	director->setOpenGLView(EGLView);
	director->setContentScaleFactor(designResolutionSize.height / screenSize.height);

	vector <string> searchPath;
    
	searchPath.push_back(resources1280x720.directory);

	CCFileUtils::sharedFileUtils()->setSearchPaths(searchPath);

	Options::SCREEN_WIDTH  = designResolutionSize.width;
	Options::SCREEN_HEIGHT = designResolutionSize.height;

	Options::SCREEN_CENTER_X = designResolutionSize.width / 2;
	Options::SCREEN_CENTER_Y = designResolutionSize.height / 2;

	Options::CAMERA_WIDTH  = screenSize.width;
	Options::CAMERA_HEIGHT = screenSize.height;

	Options::CAMERA_CENTER_X  = screenSize.width / 2;
	Options::CAMERA_CENTER_Y = screenSize.height / 2;

	director->setAlphaBlending(false);
	director->setDepthTest(false);
	director->setDisplayStats(true);

	director->setProjection(kCCDirectorProjection2D);

	director->setAnimationInterval(1.0f / 60.0f);

	Screen* pScene = new Loading();

	director->runWithScene(pScene);   

	return true;
}

void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
	CCDirector::sharedDirector()->pause();

	SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    CCDirector::sharedDirector()->resume();

	SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}

#endif