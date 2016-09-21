#include "GameState.h"
#include "Gameover.h"
#include "sfwdraw.h"
#include <cstdio>
#include <windows.h>


void Gameover::init(int a_font) {text = a_font;}

void Gameover::play() { timer = 15.f;}

void Gameover::draw()
{
	unsigned background = sfw::loadTextureMap("./Images/gameoverBack.jpg");
	sfw::drawTexture(background, 0, 600, 800, 600, false, 0, ' ');
	char buffer[120];
	//sprintf_s(buffer, "Score: %d",);
	//sfw::drawString(text, buffer, 600, 500, 16, 16);
	sprintf_s(buffer, "Game Over!\n\n\nTo return to the main menu press 'TAB'!\n\n\nTo exit the game press 'ESC'!\n");
	sfw::drawString(text, buffer, 0, 350, 16, 16);
	sprintf_s(buffer, "'Sound of Silence'\n\nPerformed by Benn Down (Quiet One)");
	sfw::drawString(text, buffer, 0, 50, 10, 10);
	sprintf_s(buffer, "Created by: Shawn Hubbart\n\n            shawn.hubbart@gmail.com");
	sfw::drawString(text, buffer, 440, 50, 10, 10);
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
