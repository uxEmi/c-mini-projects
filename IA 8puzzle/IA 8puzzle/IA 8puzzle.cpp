#include <iostream>
#include <queue>
#include <algorithm>
#include "Stare.h"

int l[] = {1,0,-1,0};
int d[] = {0,1,0,-1};
vector<Stare> viz;
vector<vector<int>> init_st = { {1,2,3},{4,5,6},{7,8,0} };
void print(const Stare& v)
{
	for (int i = 0; i < v.matrice.size(); i++)
	{
		for (int j = 0; j < v.matrice[i].size(); j++)
			cout << v.matrice[i][j];
	 cout << endl;
	}
	cout << endl;
}
bool valid(int x,int y,int size)
{
	if (x < 0 || x == size || y < 0 || y == size)
		return false;
	return true;
}
int eur(const vector<vector<int>>& v)
{
	int c = 0;
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v[i].size(); j++)
			if (v[i][j] != init_st[i][j])
				c++;
	return c;
}
bool e_f(const vector<vector<int>>& a) {
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a[i].size(); ++j) {
			if (a[i][j] != init_st[i][j]) {
				return false;
			}
		}
	}
	return true;
}
void rezolvare(int x,int y,vector<vector<int>>& v)
{ 
	priority_queue<Stare> pq;
	viz.push_back(Stare(x,y,v,eur(v)));
	pq.push(Stare(x, y, v, eur(v)));
	while (!e_f(pq.top().matrice))
	{
		Stare aux = pq.top();
		pq.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = aux.x + l[i];
			int yy = aux.y + d[i];
			if (valid(xx, yy, v.size()))
			{
				swap(v[aux.x][aux.y],v[xx][yy]);
				if (find(viz.begin(),viz.end(),Stare(xx, yy, v, eur(v))) == viz.end())
				{
					pq.push(Stare(xx,yy,v,eur(v)));
					viz.push_back(Stare(xx,yy,v,eur(v)));
				}
				swap(v[aux.x][aux.y], v[xx][yy]);
			}
		}
		swap(v[aux.x][aux.y], v[pq.top().x][pq.top().y]);
	}
}
bool se_poate(const vector<vector<int>>& v)
{
	int c = 0;
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v[i].size(); j++)
			for (int k = i ; k < v.size(); k++)
				for (int l = (k == i ? j + 1 : 0); l < v[k].size(); l++)
					if ( v[k][l] && v[i][j] && v[i][j] > v[k][l])
						c++;
	return (c % 2 == 0);
}
int main()
{
	vector<vector<int>> v(3,vector<int>(3,0));
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v[i].size(); j++)
			cin >> v[i][j];
	int x, y;
	bool ok = false;
	if (se_poate(v))
	{
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < v[i].size(); j++)
				if (v[i][j] == 0)
				{
					x = i, y = j;
					ok = true;
					break;
				}
			if (ok)
				break;
		}
		rezolvare(x,y,v);
	}
	else
		cout << "Nu se poate rezolva" << endl;
}
