#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;


int main()
{
    int t,n,maxweight,*value,*weight,**store,i,j,c,p,ti;
    cin>>t;
    while(t--){
        cin>>n>>maxweight;
        value=new int[n];weight=new int[n];
        store=new int*[n+1];
        for(i=0;i<=n;i++)store[i]=new int[maxweight+1];
        for(i=0;i<n;i++){cin>>c>>p>>ti; value[i]=c*p; weight[i]=ti; }

        for(i=0;i<=n;i++){
            for(j=0;j<=maxweight;j++){
                if(i==0||j==0)store[i][j]=0;
                else{
                    if(weight[i-1]>j)store[i][j]=store[i-1][j];
                    else{
                        store[i][j]=max(value[i-1]+store[i-1][(j-weight[i-1])],store[i-1][j]);
                    }
                }
            }
        }
        cout<<store[n][maxweight]<<endl;
    }
    return  0;
}
