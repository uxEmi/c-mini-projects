#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

constexpr int W = 3;
constexpr int iter = 150;



class Obiect{
    int g,v;
public:
    Obiect(int _g = 0,int _v = 0):g(_g),v(_v){}
    friend bool eval(int& m,vector<int> binar,const vector<Obiect>& ob);
};

bool eval(int& m,vector<int> binar,const vector<Obiect>& ob){
    int s = 0, g = 0;
    for(int i = 0 ;i < binar.size();i++)
        if(binar[i] == 1)
        {
            s += ob[i].v;
            g += ob[i].g;
        }
    if(W >= g && m < s)
    {
        m = s;
        return true;
    }
    return false;
}


int main()
{
    srand(time(NULL));
    vector<Obiect> ob;



    int nr_de_obiecte;

    cout << "Citeste numarul de obiecte" << endl;
    cin >> nr_de_obiecte;

    for(int i = 0 ;i < nr_de_obiecte;i++)
    {
        int _g,_v;
        cout << "Citeste greutatea si valoarea obiectului" << endl;
        cin >> _g >> _v;
        ob.emplace_back(Obiect(_g,_v));
    }

    int restartari = 0, m = 0;

    vector<int> binar;

    while(restartari < 10){
        binar = vector<int>(ob.size(),0);
        for(int i = 0 ;i < iter;i++)
        {
            int poz = rand() % ob.size();
            while( binar[poz] == 1)
                poz = rand() % ob.size();
            binar[poz] = 1;
            if(!eval(m,binar,ob))
                binar[poz] = 0;
        }
        restartari++;
    }

    cout << m;

    return 0;
}
