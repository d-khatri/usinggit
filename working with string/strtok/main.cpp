#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    char str[]="sdath is  a sa'mple .string.";
    char* pch;

    cout<<str<<endl;
    pch=strtok(str,"-,'.");
    cout<<pch<<endl;

    pch=strtok(NULL,"-,'.");
    cout<<pch<<endl;

    pch=strtok(NULL,"-,'.");
    cout<<pch<<endl;
    return 0;
}
