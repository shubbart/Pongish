#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "GameState.h"
#include <string>
#include <windows.h>


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
	enemy.texture = sfw::loadTextureMap("./Images/enemy.gif");
	enemy2.texture = sfw::loadTextureMap("./Images/enemy2.png");
	extra.texture = sfw::loadTextureMap("./Images/P.png");
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
	sprintf_s(scorefont, "SCORE");
	sfw::drawString(font, scorefont, 0, 25, 25, 25);
	sfw::drawString(font, std::to_string(score.total).c_str(), 150, 25, 25, 25, 0, ' ');
	sprintf_s(scorefont, "POWER");
	sfw::drawString(font, scorefont, 300, 25, 25, 25);
	sfw::drawString(font, std::to_string(player.ammo).c_str(), 500, 25, 25, 25, 0, ' ');
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
	{
		ball.yVel = -ball.yVel;
		PlaySound("./Sound/wall.wav", NULL, SND_ASYNC);
	}
		


	if ((ball.xPos - ball.radius) <= -10 || ball.xPos + ball.radius >= 800)
	{
		ball.xVel = -ball.xVel;
		PlaySound("./Sound/wall.wav", NULL, SND_ASYNC);
	}

	if (player.xPos < ball.xPos + ball.radius &&
			player.xPos + player.width > ball.xPos &&
			player.yPos < ball.yPos + ball.radius &&
			player.height + player.yPos > ball.yPos)
		{
			ball.yPos = player.yPos + player.height;
			ball.yVel = -ball.yVel;
			++score.total;
			++score.temp;
			PlaySound("./Sound/paddle.wav", NULL, SND_ASYNC);
					
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
		PlaySound("./Sound/drop.wav", NULL, SND_ASYNC);
	}

	if (player.lives == 0)
		PlaySound("./Sound/StH.wav", NULL, SND_ASYNC);
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


void GameState::battle()
{

	if (score.total % 8 == 0 && enemy.exist == 0 && score.total > 0 && score.total % 40 != 0)
	{
		enemy.exist = 1;
	}

	if (enemy.exist == 1)
	{
		enemy.xPos = enemy.xStart;

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
			score.total = score.total + 3;
			enemy.xStart = -80;
			enemy.xPos = enemy.xStart;
			ball.yVel = -ball.yVel;
			PlaySound("./Sound/explosion.wav", NULL, SND_ASYNC);
		}

	if (enemy.xPos >= 880)
		{
			enemy.exist = 0;
			enemy.xStart = -80;
		}
	
}


void GameState::battle2()
{

	if (score.total % 45 == 0 && enemy2.exist == 0 && score.total > 0)
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
		score.total = score.total + 10;
		++player.lives;
		enemy2.xStart = 820;
		enemy2.yStart = 480;
		enemy2.xPos = enemy2.xStart;
		enemy2.yPos = enemy2.yStart;
		ball.yVel = -ball.yVel;
		PlaySound("./Sound/explosion2.wav", NULL, SND_ASYNC);
	}

	if (enemy2.xPos <= -60)
	{
		enemy2.exist = 0;
		enemy2.xStart = 820;
		enemy2.yStart = 480;
	}
}

void GameState::missle()
{
	if (sfw::getKey(KEY_TAB) && enemy2.exist == 1 && player.ammo > 0)
	{
		ball.xPos = enemy2.xPos;
		ball.yPos = enemy2.yPos;
		--player.ammo;
	}
	
	else if (sfw::getKey(KEY_TAB) && enemy.exist == 1 && enemy2.exist == 0 && player.ammo > 0)
	{
		ball.xPos = enemy.xPos;
		ball.yPos = enemy.yPos;
		--player.ammo;
	}

}

void GameState::extraMissle()
{
	if (score.total % 35 == 0 && score.total > 0 && extra.exist == 0)
	{
		extra.exist = 1;
	}

	if (extra.exist == 1)
	{

		extra.xPos = randRange(20, 780);
		extra.yPos = extra.yStart;

		extra.yPos = extra.yPos - extra.yVel;

		extra.yStart = extra.yPos;

		sfw::drawTexture(extra.texture, extra.xPos, extra.yPos, extra.radius, extra.radius, false, 0);

	}

	if (player.xPos < extra.xPos + extra.radius &&
		player.xPos + player.width > extra.xPos &&
		player.yPos < extra.yPos + extra.radius &&
		player.height + player.yPos > extra.yPos)
	
	{
		extra.exist = 0;
		extra.xStart = -80;
		extra.yStart = 650;
		extra.xPos = extra.xStart;
		extra.yPos = extra.yStart;
		++player.ammo;
		PlaySound("./Sound/pickup.wav", NULL, SND_ASYNC);

	}
	
	if (extra.yPos <= 0)
	{
		extra.exist = 0;
		extra.xPos = extra.xStart;
		extra.yStart = 650;
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
	score.temp = 0;
}

bool GameState::resetEnemy()
{
	return
	enemy.exist = 0;
	enemy.xStart = -80;
	enemy.xPos = enemy.xStart;
}

bool GameState::resetEnemy1()
{
	return
	enemy.exist = 0;
	enemy.xStart = 880;
	enemy.xPos = enemy.xStart;
}

bool GameState::resetEnemy2()
{
	return
	enemy2.exist = 0;
	enemy2.xStart = 820;
	enemy2.yStart = 480;
	enemy2.xPos = enemy2.xStart;
	enemy2.yPos = enemy2.yStart;
}

bool GameState::resetMissles()
{
	return player.ammo = 3;
}

bool GameState::resetExtraM()

{
	return
	extra.exist = 0;
	extra.xStart = -40;
	extra.yStart = 480;
	extra.xPos = extra.xStart;
	extra.yPos = extra.yStart;
}