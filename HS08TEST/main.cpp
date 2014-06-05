#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int w;
    float i;
    cin>>w>>i;
    if(w%5!=0 || w>(i-0.5) )printf("%0.2f\n",i);
    else printf("%0.2f\n",(i-w-0.5));
    return 0;
}
