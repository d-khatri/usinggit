#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long int t,n,temp,i,out;
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1){
            cin>>temp;
            printf("0\n");
        }
        else{
            for(i=0;i<n;i++){
                scanf("%lld",&temp);
            }
            out=(n*(n-1))/2;
            printf("%lld\n",out);
        }
    }

    return 0;
}
