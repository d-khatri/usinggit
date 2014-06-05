#include <iostream>
#include <cstdio>
using namespace std;

int main()
{

   int integer=0x303132;
   char* p;
   p=(char*)&integer;
   if(*p=='0')cout<<"big\n"<<endl;
   else if(*p=='2') cout<<"small\n";
   else cout<<"error\n";
    return 0;
}
