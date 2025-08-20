/*
* filename: Main.cpp
* author: sunwoo.lee
* date: 08.19.2025
*/
#include <iostream>
#include <vector>
#include "Inventory.h"

int main()
{
	Inventory inventory("info.csv");
	inventory.run();

	return 0;
}