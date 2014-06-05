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
    long long int i,n,k,temp,counter=0;
    scanf("%lld %lld",&n,&k);
    for(i=0;i<n;i++){
        scanf("%lld",&temp);
        if(temp%k==0)counter++;
    }
    cout<<counter<<endl;
    return 0;
}
