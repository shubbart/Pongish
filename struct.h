#pragma once
#ifndef STRUCT_H
#define STRUCT_H

struct Player
{
	int texture;
	int xPos = 325;
	int yPos = 50;
	int width = 120;
	int height = 15;
	int lives = 3;
	int score = 0;
};

struct Wall
{
	int texture;
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
	int total = 0;
	int lost;
};

#endif