#include <iostream>
using namespace std;



long long int fib(long long int n,long long int *arry){
if (arry[n]!=0)return arry[n];
else if(n==0)return 0;
else
    arry[n]=(fib((n-1),arry)+fib((n-2),arry));
    return arry[n];
}

int main()
{
    long long int *meomarray;
    long long int n;
    cin>>n;
    meomarray = new long long int[n+1];
    for(long long int i=0;i<=n;i++)meomarray[i]=0;
    meomarray[0]=0;
    meomarray[1]=1;
    cout<<fib(n,meomarray)<<endl;
    return 0;
}
