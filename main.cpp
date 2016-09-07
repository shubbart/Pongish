
#include "sfwdraw.h"
#include <string>
#include "rand.h"
#include "struct.h"
#include "collisions.h"
#include "movement.h"
#include "difficulty.h"




void main()
{
	
	sfw::initContext(800, 600, "SoliPong");

	player.texture = sfw::loadTextureMap("./Images/player.png", 100, 25);
	wall.texture = sfw::loadTextureMap("./res/rock.tga");

	unsigned font = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);


	sfw::setBackgroundColor(BLACK);

	while (sfw::stepContext() && player.lives > 0)
	{
		sfw::drawTexture(wall.texture, wall.xPos, wall.yPos, wall.width, wall.height, 0, false, 0);
		sfw::drawTexture(player.texture, player.xPos, player.yPos, player.width, player.height, false, 0);
		sfw::drawCircle(ball.xPos, ball.yPos, ball.radius, ball.radius, GREEN);
		sfw::drawString(font, std::to_string(score.total).c_str(), 0, 25, 25, 25, 0, ' ');
		sfw::drawString(font, std::to_string(player.lives).c_str(), 765, 35, 35, 35, 0, ' ');

		moveLeft();
		moveRight();

		ball.xPos -= ball.xVel;
		ball.yPos -= ball.yVel;

		topWallCollision();
		sideWallCollision();
		playerCollision();
		ballDrop();

		difficulty();

	}


	sfw::termContext();
}