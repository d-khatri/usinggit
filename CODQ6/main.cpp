#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;


int main()
{
    int t,arry[8][2],**store,i,j;
    cin>>t;

    arry[7][0]=20;arry[7][1]=700;   arry[1][0]=37;arry[1][1]=1000;  arry[2][0]=41;arry[2][1]=790;
    arry[3][0]=17;arry[3][1]=290;   arry[4][0]=29;arry[4][1]=640;   arry[5][0]=14;arry[5][1]=490;    arry[6][0]=30;arry[6][1]=710;

    store=new int*[189];
    for(i=0;i<189;i++)store[i]=new int[8];
    for(i=0;i<8;i++)store[0][i]=0;  for(i=0;i<189;i++)store[i][0]=0;

    for(i=1;i<=t;i++){
        for(j=1;j<8;j++){
            if(arry[j][0]>i){store[i][j]=store[i][j-1];}
            else{
                store[i][j]=max(arry[j][1]+store[i-(arry[j][0])][j-1] , store[i][j-1] );
            }
        }
    }
    cout<<"\t  ";
    for(j=0;j<8;j++){
        cout<<j<<"\t";
    }
    cout<<endl<<endl<<endl;
    for(i=0;i<=t;i++){
        cout<<i<<"\t  ";
        for(j=0;j<8;j++){
            cout<<store[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<store[t][7]<<endl;

    return 0;
}
