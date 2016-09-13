#include "MainMenu.h"
#include "sfwdraw.h"
#include <cstdio>

void MainMenu::init(int a_font) { text = a_font; }

void MainMenu::play() { timer = 15.f; }

void MainMenu::draw()
{
	char buffer[80];
	sprintf_s(buffer, "To begin playing press 'Enter'!\nTo exit the game press 'ESC'!\n");
	sfw::drawString(text, buffer, 0, 150, 16, 16);
	//sfw::drawLine(0, 80, 100 + 500 * (timer / 15.f), 80);
}

void MainMenu::step()
{
	timer -= sfw::getDeltaTime();
}

APP_STATE MainMenu::next()
{
	if (sfw::getKey(KEY_ENTER))
		return ENTER_ACTION;
	
	if (sfw::getKey(KEY_ESCAPE))
		return TERMINATE;

	return MAINMENU;
}



