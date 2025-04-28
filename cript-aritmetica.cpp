#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

constexpr int iter = 1000;

bool eval(const vector<int>& v,const vector<string>& input)
{
    string end = "";
    int i = input[0].length(),j = input[1].length(),c = 0;
    while(i>=0 && j>=0)
    {
        int mod=(v[input[0][i]-97]+v[input[1][j]-97])%10;
        end += (char) mod+c+97;
        c=(v[input[0][i]-97]+v[input[1][j]-97])/10;
        i--;
        j--;
    }
    while(i>=0)
    {
        int mod=v[input[0][i]-97]%10;
        end +=(char) mod + c;
        c=0;
        i--;
    }
    while(j>=0)
    {
        int mod=v[input[1][j]-97]%10;
        end +=(char) mod + c;
        c=0;
        j--;
    }

    reverse(end.begin(),end.end());
    cout<<end<<endl;
    return input[2] == end;
}
int main() {
    srand(time(NULL));
    vector<string> input;
    string aux;

    for(int i=0;i<3;i++)
        {
            cin >> aux;
            input.emplace_back(aux);
        }
    vector<int> v(10);

    for(int i=0;i<v.size();i++)
        v[i]=i;

    int restartari = 0;
    bool flag = false;
    while(restartari<100)
    {
        for(int i=0 ;i<iter;i++)
        {
        int poz1 = rand() % 10,poz2 = rand() % 10;
        while(poz1 == poz2)
            poz2 = rand() % 10;
        swap(v[poz1],v[poz2]);
        if(eval(v,input))
            flag = true;
        }
        if(flag)
          break;
        restartari++;
    }
    cout<<"Numarul de restari este "<<restartari<<endl;
    return 0;
}
