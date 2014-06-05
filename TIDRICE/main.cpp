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
#include <utility>
using namespace std;

int main()
{
    int i,t,n,counter;
    char tempc;
    string temps,prev;
    cin>>t;
    while(t--){
        cin>>n;
        counter=0;
        pair<string,int>p[n];
        for(i=0;i<n;i++){
            cin>>temps>>tempc;
            p[i].first=temps;
            if(int(tempc)==43)p[i].second=1;
            else p[i].second=-1;
        }
        sort(p.begin(),p.end());

        prev=p[0].first;
        for(i=0;i<n-1;i++){
            if(!prev.compare(p[i+1].first) )counter+=p[i].second;
            prev=p[i+1];
        }
        cout<<counter<<endl;
    }
    return 0;
}
