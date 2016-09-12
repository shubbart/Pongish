#pragma once
#ifndef STRUCT_H
#define STRUCT_H

struct Player
{
	int texture = sfw::loadTextureMap("./Images/player.png", 100, 25);
	int xPos = 325;
	int yPos = 100;
	int width = 120;
	int height = 15;
	int lives = 3;
	int score = 0;
};

struct Wall
{
	int texture = sfw::loadTextureMap("./res/rock.tga");
	int xPos = 0;
	int yPos = 600;
	int width = 800;
	int height = 75;
};

struct Ball
{
	int xPos = 380;
	int yPos = 320;
	int radius = 13;
	int xVel = 0;
	int yVel = 5;
};

struct Score
{
	int total;
};


#endif