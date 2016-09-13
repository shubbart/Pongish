#include "Gameover.h"
#include "sfwdraw.h"
#include <cstdio>

void Gameover::init(int a_font) { text = a_font; }

void Gameover::play() { timer = 15.f; }

void Gameover::draw()
{
	char buffer[120];
	sprintf_s(buffer, "You have lost the game!\nTo return to the main menu press 'TAB'!\nTo exit the game press 'ESC'!\n");
	sfw::drawString(text, buffer, 0, 170, 16, 16);
	sfw::drawLine(0, 80, 100 + 500 * (timer / 15.f), 80);
}

void Gameover::step()
{
	timer -= sfw::getDeltaTime();
}

APP_STATE Gameover::next()
{
	if (sfw::getKey(KEY_TAB))
	return ENTER_MAINMENU;

	if (sfw::getKey(KEY_ESCAPE))
		return TERMINATE;

	return GAMEOVER;
}
