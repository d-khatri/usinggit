#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

bool myfn(long long int i,long long int j){
    return (i<j);
}

int main()
{
    long long int n,k,*arry,i,maxm,j;
    cin>>n>>k;
    arry = new long long int[n];
    for(i=0;i<n;i++){
        scanf("%lld",&arry[i]);
    }

    for(i=0;i<k;i++){
        if(i==2)break;
        maxm=*max_element(arry,arry+n,myfn);
        for(j=0;j<n;j++){
            arry[j]=maxm-arry[j];
        }
    }

    if(k>2){
        if(k%2!=0){
            maxm=*max_element(arry,arry+n,myfn);
            for(j=0;j<n;j++){
                arry[j]=maxm-arry[j];
            }
        }
    }

    for(i=0;i<n;i++){
        printf("%lld ",arry[i]);
    }
    return 0;
}
