#include "MainMenu.h"
#include "sfwdraw.h"
#include <cstdio>
#include "GameState.h"
#include <windows.h>

GameState play;

int main = 1;

void MainMenu::init(int a_font)
{ text = a_font;

if (main = 1)
{
	PlaySound("./Sound/QOSilence.wav", NULL, SND_ASYNC);
}

}

void MainMenu::play() { timer = 1.f; }

void MainMenu::draw()
{
	unsigned background = sfw::loadTextureMap("./Images/splashBack.jpg");
	sfw::drawTexture(background, 0, 600, 800, 600, false, 0, ' ');

	char buffer[80];
	sprintf_s(buffer, "To begin playing press 'Enter'!\n\n\nTo exit the game press 'ESC'!\n\n");
	sfw::drawString(text, buffer, 0, 550, 16, 16);
	sprintf_s(buffer, "During the game\n\nPress 'TAB'\n\n to send the ball to an enemy's location!");
	sfw::drawString(text, buffer, 150, 250, 16, 16);
	//sfw::drawLine(0, 80, 100 + 500 * (timer / 1.f), 80);
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



