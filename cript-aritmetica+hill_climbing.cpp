#include <iostream>
#include <unordered_map>
#include <vector>
#include <ctime>
#include <climits>

using namespace std;

constexpr int iter = 150;

int construct_the_number(string s, unordered_map<char,int>& m)
{
    int nr = 0;
    for(int i=0;i<s.length();i++)
        nr = nr*10 + m[s[i]];
    return nr;
}

int eval( unordered_map<char,int>& m,const vector<string>& input)
{
    int nr1 = 0,nr2 = 0,r = 0;
    nr1 = construct_the_number(input[0],m);
    nr2 = construct_the_number(input[1],m);
    r = construct_the_number(input[2],m);
    return abs((nr1 + nr2) - r);
}



int main()
{
    srand(time(NULL));
    unordered_map<char,int> m;

    vector<char> my_letters;

    vector<string> input;

    for(int i=0;i<10;i++)
    {
        char ch;
        cout << "Citeste urmatoarea litera pe care doresti sa o introduci" << endl;
        cin >> ch;
        my_letters.emplace_back(ch);
        m[ch] = i;
    }
    cout << "Acum citeste expresia" << endl;
    for(int i=0;i<3;i++)
    {
        string aux;
        cin >> aux;
        input.emplace_back(aux);
    }

    int restartari = -1,min = INT_MAX;

    bool flag = true;
    while(flag)
    {
        for(int i=0;i<iter && flag;i++)
        {
            int poz1 = rand() % 10,poz2 = rand() % 10;
            while(poz1 == poz2)
                poz1 = rand() % 10;
            swap(m[my_letters[poz1]],m[my_letters[poz2]]);
            if(eval(m,input) == 0)
                flag = false;
            else if(min < eval(m,input))
                    swap(m[my_letters[poz1]],m[my_letters[poz2]]);
        }
        restartari++;
    }
    cout << "A fost nevoie de "<< restartari << " restartari" << endl;
    for(auto it=m.begin();it!=m.end();it++)
        {
            cout << "Pentru " << it->first << " avem "<< it->second << endl;
        }
    return 0;
}
