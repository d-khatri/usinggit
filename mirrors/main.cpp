#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

int main()
{
    int t,m,n,i,j;
    freopen("input.txt","r",stdin);
    char** arry,temp;
    cin>>t;
    while(t--){
        cin>>n>>m;
        arry=new char*[n];
        for(i=0;i<n;i++)arry[i]=new char[m];

        for(i=0;i<n;i++)cin>>arry[i];

        for(i=0;i<n;i++){
            for(j=0;j<m/2;j++){
                temp=arry[i][j];
                arry[i][j]=arry[i][m-j-1];
                arry[i][m-1-j]=temp;
            }
        }
        for(i=0;i<n;i++)cout<<arry[i]<<endl;

    }
    return 0;
}
