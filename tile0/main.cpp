#include <iostream>
#include <cstdio>
using namespace std;


long long int fib(long long int n){
    long long int *arry;
    arry=new long long int[n+1];
    arry[0]=1;
    arry[1]=1;
    for(long long int i=2;i<=n;i++){
        arry[i]=arry[i-1]+arry[i-2];
    }
    return arry[n];
}

int main()
{
    long long int n,t,temp,i;
    cin>>t;
    while(t--){
        cin>>n;
        temp=fib(n);
        if(temp>1000000007)cout<<(temp%1000000007)<<endl;
        cout<<temp<<endl;
    }

    return 0;
}
