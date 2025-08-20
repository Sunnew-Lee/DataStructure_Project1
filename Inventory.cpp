/*
* filename: Inventory.cpp
* author: sunwoo.lee
* date: 08.19.2025
*/
#include "Inventory.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>

Inventory::Inventory(string filepath) : index(0)
{
	init_info(filepath);

	cout << "Opened Inventory.\n\n";
	print_info();
}


Inventory::~Inventory()
{
}

void Inventory::run()
{
	while (!did_quit)
	{
		process_input();
		print_info();
	}
	cout << "Closed Inventory.\n";
}

//csv reader
void Inventory::init_info(string filepath)
{
	ifstream file;
	file.open(filepath);

	if (!file.is_open())
	{
		__debugbreak();
	}

	string str;
	getline(file, str);	//한줄 버리기

	while (getline(file,str))
	{
		stringstream ss(str);
		string token;

		Info temp;
		getline(ss, token, ',');
		temp.id = stoi(token);

		getline(ss, token, ',');
		temp.name = token;

		getline(ss, token, ',');
		temp.type = token;

		getline(ss, token, ',');
		temp.cost = stoi(token);

		//getline(ss, token, ',');
		//getline(ss, token);
		ss >> temp.rarity;

		information.emplace_back(temp);
	}

	file.close();
}

//첫 번째 목록부터 카드 정보를 보여주기
void Inventory::print_info()
{
	if (did_print)
		return;

	cout << "====================================================Esc to Quit===================================================\n";
	//cout << "|| Index: " << index << '\n';
	cout << "|| ID: " << information[index].id
		<< "\t|\tName: " << information[index].name
		<< "\t|\tType: " << information[index].type
		<< "\t|\tCost: " << information[index].cost
		<< "\t|\tRarity: " << information[index].rarity
		<< "\t||\n";
	cout << "==================================================================================================================\n\n";

	did_print = true;
}

void Inventory::process_input()
{
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		did_quit = true;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		if (!is_keypressed)
		{
			if (--index < 0)
			{
				index = information.size() - 1;
			}
			did_print = false;
			is_keypressed = true;
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		if (!is_keypressed)
		{
			if (++index == information.size())
			{
				index = 0;
			}
			did_print = false;
			is_keypressed = true;
		}
	}
	else
	{
		is_keypressed = false;
	}
}
