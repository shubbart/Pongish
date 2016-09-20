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
	Enemy2 enemy2;
	unsigned font;
	unsigned text;

public:

	void init();
	void start();
	void move();
	void collision();
	void drop();
	void difficulty();
	void draw();
	void battle();
	void battle2();

	bool isAlive() const;
	bool resetLives();
	bool resetScore();
};




