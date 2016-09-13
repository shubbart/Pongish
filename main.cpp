
#include "sfwdraw.h"
#include "GameState.h"
#include <cstdio>
#include <cstdlib>
#include "struct.h"

void main()
{
	GameState gs;
	
	gs.init();

	while (sfw::stepContext())
	{
		gs.draw();
		gs.start();
		gs.move();
		gs.collision();
		gs.drop();
		gs.difficulty();
		gs.gameOver();
	}

	sfw::termContext();
}