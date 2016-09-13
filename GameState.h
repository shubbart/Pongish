#pragma once
#include "sfwdraw.h"
#include "struct.h"

class GameState
{

public:
	Player player;
	Wall wall;
	Ball ball;
	Score score;
	unsigned font;
		
	void init();
	void start();
	void move();
	void collision();
	void drop();
	void draw();
	void gameOver() const;
	void difficulty();
};




