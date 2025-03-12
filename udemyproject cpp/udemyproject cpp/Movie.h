#pragma once
#include <iostream>
#include <string>
class Movie {
   private:
	   std::string name;
	   int rating,watched_count;
   public:
	   Movie(std::string n,int r,int w):name(n),rating(r),watched_count(w){}
	   ~Movie()
	   {
		  
	   }
	   friend class Movies;
};