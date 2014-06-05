//using strchr

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main()
{
    char* str="this is a string";
    char* pch;
    cout<<str<<endl;
    pch=strchr(str,'s');
    cout<<pch<<endl;

    pch=strchr(pch+1,'s');
    cout<<pch<<endl;

    pch=strchr(pch+1,'s');
    cout<<pch<<endl;
    return 0;
}
