#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int t,n,temp,i,out;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        if(n==1){
            scanf("%llu\n",&temp);
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
