
#include "sfwdraw.h"


Player player;
Wall wall;
Ball ball;
Score score;


void main()
{

	sfw::initContext(800, 600, "SoliPong");

	player.texture = sfw::loadTextureMap("./Images/player.png", 100, 25);
	player.xPos = 325;
	player.yPos = 100;
	player.width = 120;
	player.height = 15;
	player.lives = 3;

	wall.texture = sfw::loadTextureMap("./Images/wall.png");
	wall.xPos = 0;
	wall.yPos = 600;
	wall.width = 800;
	wall.height = 75;

	ball.xPos = 380;
	ball.yPos = 320;
	ball.radius = 13;
	ball.xVel = 2;
	ball.yVel = 5;

	score.texture = sfw::loadTextureMap("./res/tonc_font.png");
	score.total = 0;

	sfw::setBackgroundColor(BLACK);



	while (sfw::stepContext() && player.lives > 0)
	{
		sfw::drawTexture(wall.texture, wall.xPos, wall.yPos, wall.width, wall.height, 0, false, 0, BLUE);
		sfw::drawTexture(player.texture, player.xPos, player.yPos, player.width, player.height, false, 0);
		sfw::drawCircle(ball.xPos, ball.yPos, ball.radius, ball.radius, GREEN);

		if (sfw::getKey(KEY_LEFT) && player.xPos > 0)
		{
			player.xPos -= 10;
		}

		else if (sfw::getKey(KEY_RIGHT) && player.xPos < 680)
		{
			player.xPos += 10;
		}

		ball.xPos -= ball.xVel;
		ball.yPos -= ball.yVel;


		if ((ball.yPos - ball.radius) >= (wall.yPos - 100))
		{
			ball.yVel = -ball.yVel;
		}

		if ((ball.xPos - ball.radius) <= 0 || ball.xPos - ball.radius >= 787)
		{
			ball.xVel = -ball.xVel;
		}

		if (player.xPos < ball.xPos + ball.radius &&
			player.xPos + player.width > ball.xPos &&
			player.yPos < ball.yPos + ball.radius &&
			player.height + player.yPos > ball.yPos)

		{
			ball.yVel = -ball.yVel;
			score.total = score.total + 1;
		}


		if (ball.yPos < 0)
		{
			player.lives = player.lives - 1;
			ball.xPos = 380;
			ball.yPos = 320;
			ball.xVel = 2;
		}
		
	}


	sfw::termContext();
}