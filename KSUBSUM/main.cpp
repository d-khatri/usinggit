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
    long long int t,n,k1,k2,k3,i,temp,k;
    vector <long long int> data;
    vector <long long int> subsumdata;
    cin>>t;
    while(t--){
        data.clear();
        subsumdata.clear();
        cin>>n>>k1>>k2>>k3;
        for(i=0;i<n;i++){scanf("%lld",&temp); data.push_back(temp);}

        for(i=0;i<n;i++){
            temp=0;
            for(k=i;k<n;k++){
                temp+=data[k];
                subsumdata.push_back(temp);
            }
        }
        sort(subsumdata.begin(),subsumdata.begin()+subsumdata.size());
        printf("%lld %lld %lld\n",subsumdata[subsumdata.size()-k1],subsumdata[subsumdata.size()-k2],subsumdata[subsumdata.size()-k3]);
    }
    return 0;
}
