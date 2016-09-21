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
	int ammo = 3;
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
	int texture;
	int xPos = 380;
	int yPos = 320;
	int radius = 15;
	int xVel = 0;
	int yVel = 5;
};

struct Score
{
	int total = 0;
	int temp = 0;
	int lost;
};

struct Enemy
{
	int exist = 0;
	int texture;
	int xStart = 0;
	int yStart = 480;
	int xPos = -80;
	int yPos = 480;
	int xVel = 1;
	int width = 60;
	int height = 20;
};

struct Enemy2
{
	int exist = 0;
	int texture;
	int xStart = 820;
	int yStart = 480;
	int xPos = 820;
	int yPos = 480;
	int xVel = 3;
	int yVel = 6;
	int width = 40;
	int height = 55;
};



struct Missle
{
	int texture;
	int exist;

	int xStart;
	int yStart = 650;
	int xPos;
	int yPos = 650;
	int xVel = 0;
	int yVel = 2;
	int radius = 20;
};
#endif