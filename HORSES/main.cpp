#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>
#include <stack>
#include <math.h>
using namespace std;

int main()
{
    int i,t,n;
    long long int *store,*diff;
    cin>>t;
    while(t--){
        cin>>n;
        store=new long long int[n];
        diff=new long long int[n];
        for(i=0;i<n;i++)scanf("%lld",&store[i]);
        sort(store,store+n);
        for(i=0;i<n-1;i++)diff[i]=store[i+1]-store[i];
        cout<<*min_element(diff,diff+n-1)<<endl;
    }
    return 0;
}
