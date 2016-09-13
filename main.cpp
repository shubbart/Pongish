
#include "sfwdraw.h"
#include "GameState.h"
#include <cstdio>
#include <cstdlib>
#include "struct.h"

void main()
{
	GameState gs;
	
	gs.init();

	while (sfw::stepContext() && gs.isAlive())
	{
		gs.draw();
		gs.start();
		gs.move();
		gs.collision();
		gs.drop();
		gs.extraLife();
		gs.gameOver();
	}

 sfw::termContext();
}