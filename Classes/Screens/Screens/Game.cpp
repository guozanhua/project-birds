#ifndef CONST_GAME
#define CONST_GAME

#include "Game.h"

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

Game::Game()
{
    this->mFinishScreen = new End(this);

    this->mFinishScreen->show();
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

void Game::onEnter()
{
    Screen::onEnter();
}

void Game::onExit()
{
    Screen::onExit();
}

#endif