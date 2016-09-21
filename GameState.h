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
	Missle extra;

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
	void missle();
	void extraMissle();

	bool isAlive() const;
	bool resetLives();
	bool resetScore();
	bool resetEnemy();
	bool resetEnemy1();
	bool resetEnemy2();
	bool resetMissles();
	bool resetExtraM();
};




