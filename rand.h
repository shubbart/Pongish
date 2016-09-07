#pragma once
#include <iostream>
#include <ctime>


int randRange(int start, int end)
{
	srand(time(NULL));
	return rand() % (end - start + 1) + start;
}