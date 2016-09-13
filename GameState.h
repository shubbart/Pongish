#pragma once
#include "sfwdraw.h"
#include "struct.h"

class GameState
{


	Player player;
	Wall wall;
	Ball ball;
	Score score;
	unsigned font;

public:
	void init();
	void start();
	void move();
	void collision();
	void drop();
	void draw();
	void extraLife();
	bool isAlive() const;
	void gameOver() const;
};




