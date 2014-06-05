#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
        long long int t,n,speed,counter,i,prev,curr,minimum;
        cin>>t;
        while(t--){
            prev=curr=counter=0;
            scanf("%lld",&n);
            for(i=1;i<=n;i++){
                    scanf("%lld",&speed);
                    prev=curr;
                    curr=speed;
                    if(i==1){
                        counter++;
                        minimum=curr;
                    }
                    else{
                        if(curr<minimum) minimum=curr;
                        if(curr<=prev && curr<=minimum) counter++;
                    }
            }
            printf("%lld\n",counter);
        }
    return 0;
}
