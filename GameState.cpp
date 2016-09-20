#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "GameState.h"
#include <string>


int randRange(int start, int end)
{
	srand(time(NULL));
	return rand() % (end - start + 1) + start;
}

void GameState::init()
{
	sfw::setBackgroundColor(BLACK);
	player.texture = sfw::loadTextureMap("./Images/player.png", 100, 25);
	wall.texture = sfw::loadTextureMap("./Images/wall.png");
	ball.texture = sfw::loadTextureMap("./Images/ball.gif");
	enemy.texture = sfw::loadTextureMap("./Images/enemy1.gif");
	enemy2.texture = sfw::loadTextureMap("./Images/enemy2.png");
	font = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	text = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
}

void GameState::draw()
{
	char scorefont[10];
	char livesfont[10];
	sfw::drawTexture(wall.texture, wall.xPos, wall.yPos, 200, wall.height, 0, false, 0);
	sfw::drawTexture(wall.texture, 200, wall.yPos, 200, wall.height, 0, false, 0);
	sfw::drawTexture(wall.texture, 400, wall.yPos, 200, wall.height, 0, false, 0);
	sfw::drawTexture(wall.texture, 600, wall.yPos, 200, wall.height, 0, false, 0);
	sfw::drawTexture(player.texture, player.xPos, player.yPos, player.width, player.height, false, 0);
	sfw::drawTexture(ball.texture, ball.xPos, ball.yPos, ball.radius, ball.radius, false, 0);
	//sfw::drawCircle(ball.xPos, ball.yPos, ball.radius, ball.radius, MAGENTA);
	sprintf_s(scorefont, "SCORE");
	sfw::drawString(font, scorefont, 0, 25, 25, 25);
	sfw::drawString(font, std::to_string(score.total).c_str(), 150, 25, 25, 25, 0, ' ');
	sprintf_s(livesfont, "LIVES");
	sfw::drawString(font, livesfont, 625, 25, 25, 25);
	sfw::drawString(font, std::to_string(player.lives).c_str(), 775, 25, 25, 25, 0, ' ');
}
void GameState::start()
{
	ball.xPos -= ball.xVel;
	ball.yPos -= ball.yVel;
}


void GameState::move()
{

	if (sfw::getKey(KEY_LEFT) && player.xPos > 0)
		player.xPos -= 10;

	if (sfw::getKey(KEY_RIGHT) && player.xPos < 680)
		player.xPos += 10;
}

void GameState::collision()
{
	if ((ball.yPos - ball.radius) >= (wall.yPos - 100))
			ball.yVel = -ball.yVel;
		


	if ((ball.xPos - ball.radius) <= -10 || ball.xPos + ball.radius >= 800)
			ball.xVel = -ball.xVel;
		
	

	if (player.xPos < ball.xPos + ball.radius &&
			player.xPos + player.width > ball.xPos &&
			player.yPos < ball.yPos + ball.radius &&
			player.height + player.yPos > ball.yPos)
		{
			ball.yVel = -ball.yVel;
			++score.total;
			++score.temp;
			
			if (ball.xVel == 0)
			{
				ball.xVel = ball.xVel + randRange(-1, 1);
			}

		}
	
}

void GameState::drop()
{
	if (ball.yPos < 0)
	{
		--player.lives;
		score.temp = 0;
		ball.xPos = 380;
		ball.yPos = 320;
		ball.xVel = 0;
		player.xPos = 325;
	}
}

void GameState::difficulty()
{
	if (score.temp == 3 && ball.xVel > 0)
	{
		ball.xVel = ball.xVel + 2;
		score.temp = 0;
	}

	if (score.temp == 3 && ball.xVel < 0)
	{
		ball.xVel = ball.xVel - 2;
		score.temp = 0;
	}
}

bool GameState::isAlive() const 
{
	return player.lives > 0;
}

bool GameState::resetLives()
{
	return player.lives = 3;
}

bool GameState::resetScore()
{
	return score.total = 0;
}

void GameState::battle()
{

	if (score.total % 10 == 0 && enemy.exist == 0 && score.total > 0)
	{
		enemy.exist = 1;
	}

	if (enemy.exist == 1)
	{
		enemy.xPos = enemy.xStart;
		enemy.yPos = enemy.yStart;

		enemy.xPos = enemy.xPos + enemy.xVel;

		enemy.xStart = enemy.xPos;

		sfw::drawTexture(enemy.texture, enemy.xPos, enemy.yPos, enemy.width, enemy.height, false, 0);
	}

	if (enemy.xPos < ball.xPos + ball.radius &&
			enemy.xPos + enemy.width > ball.xPos &&
			enemy.yPos < ball.yPos + ball.radius &&
			enemy.height + enemy.yPos > ball.yPos)
		{
			enemy.exist = 0;
			score.total = score.total + 2;
			enemy.xStart = -80;
			enemy.xPos = enemy.xStart;
			ball.yVel = -ball.yVel;
		}

	if (enemy.xPos >= 880)
		{
			enemy.exist = 0;
			enemy.xStart = -80;
		}
	
}

void GameState::battle2()
{

	if (score.total % 50 == 0 && enemy2.exist == 0 && score.total > 0 ||
		score.total % 55 == 0 && enemy2.exist == 0 && score.total > 0)
	{
		enemy2.exist = 1;
	}

	if (enemy2.exist == 1)
	{
		enemy2.xPos = enemy2.xStart;
		enemy2.yPos = enemy2.yStart;

		enemy2.xPos = enemy2.xPos - enemy2.xVel;
		enemy2.yPos = enemy2.yPos - enemy2.yVel;

		enemy2.xStart = enemy2.xPos;
		enemy2.yStart = enemy2.yPos;

		sfw::drawTexture(enemy2.texture, enemy2.xPos, enemy2.yPos, enemy2.width, enemy2.height, 270, false, 0);

		if ((enemy2.yPos) <= 100 || (enemy2.yPos) >= 500)
			enemy2.yVel = -enemy2.yVel;
	}


	if (enemy2.xPos < ball.xPos + ball.radius &&
		enemy2.xPos + enemy2.width > ball.xPos &&
		enemy2.yPos < ball.yPos + ball.radius &&
		enemy2.height + enemy2.yPos > ball.yPos)
	{
		enemy2.exist = 0;
		++player.lives;
		score.total = score.total + 10;
		enemy2.xStart = 820;
		enemy2.yStart = 480;
		enemy2.xPos = enemy2.xStart;
		enemy2.yPos = enemy2.yStart;
		ball.yVel = -ball.yVel;
	}

	if (enemy2.xPos <= -60)
	{
		enemy2.exist = 0;
		enemy2.xStart = 820;
		enemy2.yStart = 480;
	}
}