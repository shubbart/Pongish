#include "Action.h"
#include "GameState.h"
#include <cstdio>

GameState gs;

void Action::init(int a_font) 
{
	text = a_font;
	gs.init();
}

void Action::play()
{
	gs.start();
}

void Action::draw()
{
	gs.draw();
}

void Action::step()
{
	gs.start();
	gs.move();
	gs.collision();
	gs.difficulty();
	gs.drop();
	gs.battle();
	gs.battle2();
	gs.missle();
	gs.extraMissle();
}

APP_STATE Action::next()
{
	if (!gs.isAlive())
	{
		gs.resetLives();
		gs.resetScore();
		gs.resetEnemy1();
		gs.resetEnemy1();
		gs.resetEnemy2();
		gs.resetMissles();
		gs.resetExtraM();
		return GAMEOVER;
	}
	return ACTION;
}
