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
	wall.texture = sfw::loadTextureMap("./res/rock.tga");
	font = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	text = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
}

void GameState::draw()
{
	char scorefont[10];
	char livesfont[10];
	sfw::drawTexture(wall.texture, wall.xPos, wall.yPos, wall.width, wall.height, 0, false, 0);
	sfw::drawTexture(player.texture, player.xPos, player.yPos, player.width, player.height, false, 0);
	sfw::drawCircle(ball.xPos, ball.yPos, ball.radius, ball.radius, MAGENTA);
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
		


	if ((ball.xPos - ball.radius) <= 0 || ball.xPos - ball.radius >= 787)
			ball.xVel = -ball.xVel;
		
	

	if (player.xPos < ball.xPos + ball.radius &&
			player.xPos + player.width > ball.xPos &&
			player.yPos < ball.yPos + ball.radius &&
			player.height + player.yPos > ball.yPos)
		{
			ball.yVel = -ball.yVel;
			score.total = ++score.total;

			if (ball.xVel == 0)
			{
				ball.xVel = ball.xVel + randRange(-10, 10);
			}

			if (ball.xVel > 0)
			{
				ball.xVel = ball.xVel + randRange(-5, 5);
			}
		}
	
}

void GameState::drop()
{
	if (ball.yPos < 0)
	{
		--player.lives;
		ball.xPos = 380;
		ball.yPos = 320;
		ball.xVel = 0;
		player.xPos = 325;
	}
}

void GameState::extraLife()
{
	if (player.score % 50 == 0 && player.score > 0)
	{
		++player.lives;
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