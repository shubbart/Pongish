
#include "sfwdraw.h"
#include "GameState.h"

using namespace sfw;


void main()
{
	
	sfw::initContext(800, 600, "SoliPong");
	sfw::setBackgroundColor(BLACK);

	 GameState gs = createGameState();

	while (sfw::stepContext())
	{
		updateGameState(gs);
		drawGameState(gs);
	}

	sfw::termContext();
}