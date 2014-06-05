#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define FOR(i,a,b) for(register int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)

//#define DEBUG

LL findans(LL p){
    LL newp,oldp,ans,num;
    ans=0;
    oldp=newp=p;
    num=2048;
    while(num){
        oldp=newp;
        newp=oldp-((oldp/num)*num);
        if(newp!=oldp)ans+=oldp/num;

        #ifdef DEBUG
        printf("newp oldp num ans %lld %lld %lld %lld\n",newp,oldp,num,ans);
        #endif // DEBUG

        num/=2;
    }
    return ans;
}


int main()
{
    LL t,p,i,j,temp;
    cin>>t;
    while(t--){
        cin>>p;
        cout<<findans(p)<<endl;
    }
    return 0;
}
