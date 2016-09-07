#pragma once
#include "sfwdraw.h"
#include "struct.h"

void difficulty()
{
	bool(player.score > 0 && player.score % 10 == 0);
	{
		ball.xVel = ball.xVel * 2;
	}
}