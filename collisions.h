#pragma once
#include "sfwdraw.h"
#include "rand.h"
#include "struct.h"

Player player;
Wall wall;
Ball ball;
Score score;


void topWallCollision()
{
	if ((ball.yPos - ball.radius) >= (wall.yPos - 100))
	{
		ball.yVel = -ball.yVel;
	}
}


void sideWallCollision()
{
	if ((ball.xPos - ball.radius) <= 0 || ball.xPos - ball.radius >= 787)
	{
		ball.xVel = -ball.xVel;
	}
}

void playerCollision()
{
	if (player.xPos < ball.xPos + ball.radius &&
		player.xPos + player.width > ball.xPos &&
		player.yPos < ball.yPos + ball.radius &&
		player.height + player.yPos > ball.yPos)

	{
		ball.yVel = -ball.yVel;
		score.total = ++score.total;

		if (ball.xVel == 0)
		{
			ball.xVel = ball.xVel + randRange(-1, 1);
		}
	}
}

void ballDrop()
{
	if (ball.yPos < 0)
	{
		player.lives = --player.lives;
		ball.xPos = 380;
		ball.yPos = 320;
		ball.xVel = 0;
		player.xPos = 325;
	}
}

