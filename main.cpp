
#include "sfwdraw.h"
#include "GameState.h"
#include <cstdio>
#include <cstdlib>
#include "struct.h"
#include "Splash.h"
#include "Gameover.h"
#include "MainMenu.h"
#include "Action.h"
#include <windows.h>

void main()
{

	sfw::initContext(800,600,"Pong of Solitude");
	unsigned text = sfw::loadTextureMap("./res/fontmap.png", 16, 16);


	
	Splash splash;
	Gameover gameover;
	MainMenu main;
	Action action;

	splash.init(text);
	gameover.init(text);
	main.init(text);
	action.init(text);

	APP_STATE state = ENTER_SPLASH;

	bool quit = false;
	while (sfw::stepContext() && !quit)
	{
		switch (state)
		{
		case ENTER_SPLASH:
			splash.play();
		case SPLASH:
			splash.step();
			splash.draw();
			state = splash.next();
			break;

			
		case ENTER_MAINMENU:
			main.play();
		case MAINMENU:
			main.step();
			main.draw();
			state = main.next();
			break;

		case ENTER_ACTION:
			action.play();
		case ACTION:
			action.step();
			action.draw();
			state = action.next();
			break;

		case ENTER_GAMEOVER:
			gameover.play();
		case GAMEOVER:
			gameover.step();
			gameover.draw();
			state = gameover.next();
			break;

		case TERMINATE: quit = true;
		}
	}
 sfw::termContext();
}
