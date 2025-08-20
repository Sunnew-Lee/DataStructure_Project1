/*
* filename: Inventory.h
* author: sunwoo.lee
* date: 08.19.2025
*/

#pragma once
#include <vector>
#include <string>

using namespace std;

class Inventory
{
public:
	struct Info
	{
		Info(int id, string name, string type, int cost, int rarity):
			id(id),name(name),type(type),cost(cost),rarity(rarity)
		{
		}
		Info() {};

		int id{ -1 }, cost{ -1 }, rarity{ -1 };
		string name;
		string type;
	};

	Inventory(string filepath);
	~Inventory();
	void run();


private:
	void init_info(string filepath);
	void print_info();
	void process_input();

private:
	vector<Info> information;
	int index{ -1 };
	bool is_keypressed{ false };
	bool did_quit{ false };
	bool did_print{ false };
};