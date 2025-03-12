#pragma once
#include "Movie.h"
#include <vector>
class Movies {
private:
	std::vector<Movie> v;
public:
	Movies()
	{
		v.clear();
	}
	void add(std::string s,int r,int w)
	{
		bool ok = true;
		for (int i = 0; i < v.size(); i++)
			if (v[i].name == s)
			{
				ok = false;
				std::cout << "Sorry but the movie is already registered"<<std::endl;
				break;
			}
		if (ok) {
			Movie obj(s, r, w);
			v.push_back(obj);
		}
	}
	void increment(const std::string& name)
	{
		bool ok = false;;
		for (const auto& i : v)
		if(i.name==name)
		{
			ok = true;
		}
		if (ok)
		{
			for (int i=0;i<v.size();i++)
				if (v[i].name == name)
					v[i].watched_count++;
		}
		else
			std::cout << "Sorry the name isn't registered" << std::endl;
	}
	void display()
	{
		for (const auto& i : v)
			std::cout << i.name << ' ' << std::endl;
	}
};