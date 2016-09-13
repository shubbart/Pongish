#pragma once

#include "constdecl.h"

class MainMenu
{
	int text;
	float timer;
	int select;

public:
	void init(int a_font);

	void play();
	void draw();
	void step();

	APP_STATE next();

};
