#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

int main()
{
    long long int i,n,x,*arry,total=0,counter=0,usc;
    cin>>n>>x;

    arry=new long long int[n];
    for(i=0;i<n;i++)scanf("%lld",&arry[i]);

    sort(arry,arry+n);

    i=0;
    while(total+arry[i]<=x  && i<n ){
        total+=arry[i];
        counter++;
        i++;
    }

    usc=n-counter;
    cout<<arry[i]<<endl;
    if((x-total) > arry[i]/2) usc--;
    cout<<(usc)<<" "<<(counter)<<endl;
    return 0;
}
