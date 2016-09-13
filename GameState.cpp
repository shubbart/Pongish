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
	sfw::initContext(800, 600, "SoliPong");
	sfw::setBackgroundColor(BLACK);
	player.texture = sfw::loadTextureMap("./Images/player.png", 100, 25);
	wall.texture = sfw::loadTextureMap("./res/rock.tga");
	font = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
}

void GameState::draw()
{
	sfw::drawTexture(wall.texture, wall.xPos, wall.yPos, wall.width, wall.height, 0, false, 0);
	sfw::drawTexture(player.texture, player.xPos, player.yPos, player.width, player.height, false, 0);
	sfw::drawCircle(ball.xPos, ball.yPos, ball.radius, ball.radius, MAGENTA);
	sfw::drawString(font, std::to_string(score.total).c_str(), 0, 25, 25, 25, 0, ' ');
	sfw::drawString(font, std::to_string(player.lives).c_str(), 765, 35, 35, 35, 0, ' ');
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
				ball.xVel = ball.xVel + randRange(-8, 8);
			}

			if (ball.xVel > 0)
			{
				ball.xVel = ball.xVel + randRange(-3, 3);
			}
		}
	
}

void GameState::drop()
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

void GameState::extraLife()
{
	if (player.score % 50 == 0 && player.score > 0)
	{
		++player.lives;
		sfw::drawString(font, "You gained a Life!", 85, 350, 35, 35, 0, ' ');
	}
}
	

bool GameState::isAlive() const
{
	return player.lives > 0;
}
void GameState::gameOver() const
{
	if (player.lives == 0)
		sfw::drawString(font, "You Lost the Game!", 85, 350, 35, 35, 0, ' ');
}