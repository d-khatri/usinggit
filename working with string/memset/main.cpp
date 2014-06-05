//using memset
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main()
{
    char str[]="almost every programmer should know the memset";
    memset(str,'-',6);
    cout<<str<<endl;
    return 0;
}
