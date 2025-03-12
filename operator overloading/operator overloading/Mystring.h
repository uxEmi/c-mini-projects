#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class Mystring {
private:
    char* p;
public:
    Mystring& operator*=(const int& n)
    {
        char* buff = new char[strlen(p)*n+1];
        strcpy(buff, p);
        for (int i = 0; i < n - 1; i++)
            strcat(buff, p);
        delete[] p;
        p = new char[strlen(buff) + 1];
        strcpy(p, buff);
        delete[] buff;
        return *this;
    }
    Mystring& operator=(Mystring&& t)
    {
        delete[] p;
        p = new char[strlen(t.p) + 1];
        strcpy(p,t.p);
        t.p = nullptr;
        return *this;
    }
    Mystring& operator=(const Mystring& rv)
    {
        if (this == &rv)
            return *this;
        delete[] p;
        p = new char[strlen(rv.p)+1];
        strcpy(p,rv.p);
        return *this;
    }
    Mystring operator*(const int &n)
    {
        char* buff = new char[strlen(p)*n+1];
        strcpy(buff, p);
        for (int i = 0; i < n - 1; i++)
            strcat(buff, p);
        Mystring temp = Mystring(buff);
        delete[] buff;
        return temp;
    }
    char* get()
    {
        return this->p;
    }
    Mystring& operator+=(const Mystring& rv)
    {
        strcat(p,rv.p);
        return *this;
    }
    bool operator<(const Mystring& rs)
    {
        if (strcmp(p, rs.p) <0)
            return true;
        return false;
    }
    bool operator>(const Mystring& rs)
    {
        if (strcmp(p, rs.p) > 0)
            return true;
        return false;
    }
    Mystring operator+(const Mystring& rv)
    {
        char* buff = new char[strlen(p) + strlen(rv.p) + 1];
        strcpy(buff,p);
        strcat(buff, rv.p);
        Mystring temp = Mystring(buff);
        return temp;
    }
    bool operator!=(const Mystring& rs)
    {
        if (strcmp(p, rs.p) != 0)
            return true;
        return false;
    }
    bool operator==(const Mystring& rs)
    {
        if (strcmp(p, rs.p) == 0)
            return true;
        return false;
    }
    Mystring operator-()
    {
        char* buff = new char[strlen(p) + 1];
        strcpy(buff, p);
        for (int i = 0; i < strlen(buff); i++)
            buff[i] = tolower(buff[i]);
        Mystring temp = Mystring(buff);
        delete[] buff;
        return temp;
    }
    Mystring(){
        p = new char[1];
        *p = '\0';
    }
    Mystring(const char* s) {
        p = new char[strlen(s) + 1];
        strcpy(p,s);
    }
    Mystring(const Mystring& obj)
    {   
        p = new char[strlen(obj.p)+1];
        strcpy(p,obj.p);
    }
    Mystring(Mystring&& obj)noexcept
    {
        p = new char[strlen(obj.p)+1];
        strcpy(p,obj.p);
        obj.p = nullptr;
    }
    ~Mystring()
    {
        delete [] p;
    }
};