#include "Splash.h"
#include "sfwdraw.h"
#include <cstdio>

void Splash::init(int a_font) { text = a_font; }

void Splash::play() { timer = 15.f; }

void Splash::draw()
{
	char buffer[80];
	sprintf_s(buffer, "Welcome to SoliPong!\nPress 'TAB' to begin playing!");
	sfw::drawString(text, buffer, 0, 150, 16, 16);
	//sfw::drawLine(0, 80, 100 + 500 * (timer / 15.f), 80);
}


void Splash::step()
{
	timer -= sfw::getDeltaTime();
}

APP_STATE Splash::next()
{
	if (sfw::getKey(KEY_TAB))
		return ENTER_MAINMENU;

	return SPLASH;
}
