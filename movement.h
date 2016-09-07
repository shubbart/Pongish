#pragma once
#include "sfwdraw.h"
#include <string>
#include "rand.h"
#include "struct.h"
#include "collisions.h"


void moveLeft()
{
	if (sfw::getKey(KEY_LEFT) && player.xPos > 0)
	{
		player.xPos -= 10;
	}
}

void moveRight()
{
	if (sfw::getKey(KEY_RIGHT) && player.xPos < 680)
	{
		player.xPos += 10;
	}
}