#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    long long int t,n,i,*a,maxs,pos;
    freopen("input.txt","r",stdin);
    cin>>t;
    while(t--){
        cin>>n;
        maxs=pos=0;
        a=new long long int[n];
        for(i=n-1;i>=0;i--){
            scanf("%lld",&a[i]);
            if(a[i]>=i+1 && (a[i]+(n-(i+1)))>maxs){maxs=a[i];pos=n-(i+1); maxs=maxs+pos;}
        }
    if(maxs==0)cout<<n<<endl;
    else cout<<maxs<<endl;
    }
    return 0;
}
