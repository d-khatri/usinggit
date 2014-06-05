#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long int t,n,i,temp,ans,zeros,ones,twos;
    cin>>t;
    while(t--){
        cin>>n;
        ans=n*(n-1)/2;
        zeros=ones=twos=0;
        for(i=1;i<=n;i++){
            scanf("%lld",&temp);
            if(temp==0 ){
                ans-=i-1;
                zeros++;
            }
            else if(temp==1 ){
                ans-=i-1;
                ones++;
            }
            else if(temp==2){
                ans-=ones;
                ans-=zeros;
                ans-=twos;
                twos++;
            }
            else{
                ans-=ones;
                ans-=zeros;
            }
            //cout<<zeros<<"\t"<<ones<<"\t"<<ans<<endl;
        }
        //cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}
