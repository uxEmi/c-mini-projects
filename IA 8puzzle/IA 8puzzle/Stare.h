#pragma once
#include <vector>
using namespace std;

class Stare
{
public:
	vector<vector<int>> matrice;
	int x, y,h1;
	Stare() :x(0), y(0), h1(0), matrice({}) {}
	Stare(int x, int y, vector<vector<int>> matrice,int h) :x(x), y(y),matrice(matrice),h1(h) {}
	bool operator==(const Stare& obj)
	{
		return this->h1==obj.h1 && (this->matrice == obj.matrice) && this->x == obj.x && this->y == obj.y;
	}
	bool operator<(const Stare& obj)const 
	{
		return this->h1 > obj.h1;
	}
};
