#pragma once
#include "sfwdraw.h"
#include "struct.h"

class GameState
{


	Player player;
	Wall wall;
	Ball ball;
	Score score;
	Enemy enemy;
	unsigned font;
	unsigned text;

public:

	void init();
	void start();
	void move();
	void collision();
	void drop();
	void draw();
	void extraLife();
	void battle();

	bool isAlive() const;
	bool resetLives();
	bool resetScore();
};




