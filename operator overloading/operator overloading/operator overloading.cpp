#include "Mystring.h"

int main()
{
    Mystring obj("emi"), obj2("matei");
    obj += obj2;
    cout << obj.get() << endl;
}

