#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    long long int n,q,x1,y1,x2,y2,**arry,i,j,check[10],result,k,store[10],maxdiffval;
    cin>>n;

    for(i=0;i<=9;i++){
        store[i]=0;
    }

    arry=new long long int*[n];
    for(i=1;i<=n;i++){
        arry[i]=new long long int[n];
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%lld",&arry[i][j]);
            store[((arry[i][j])-1)]=1;
        }
    }

    for(i=0;i<=9;i++){
        if(store[i]==1)maxdiffval++;
    }

    scanf("%lld",&q);
    here:while(q--){
        for(k=0;k<=9;k++){
            check[k]=0;
        }
        result=0;
        scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
        for(i=x1;i<=x2;i++){
            for(j=y1;j<=y2;j++){
                if(check[(arry[i][j]-1)]!=1){
                    check[(arry[i][j]-1)]=1;
                    result++;
                }
                if(result==maxdiffval){
                    printf("%lld\n",maxdiffval);
                    goto here;
                }
            }
        }
        printf("%lld\n",result);
    }
    return 0;
}
