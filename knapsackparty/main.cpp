#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>
#include <stack>
#include <math.h>
using namespace std;


void solveknapsack(int maxweight,int noofitems,int *weight, int *value){
    int i,w,**m,finalweight=0;

    m=new int*[noofitems+1];

    for(i=0;i<=noofitems;i++)
        m[i]=new int[maxweight+1];

for(i=0;i<=noofitems;i++){
    for(w=0;w<=maxweight;w++){
        if(i==0 || w==0)
            m[i][w]=0;
        else if(weight[i-1]<= w){
            m[i][w] =max(value[i-1]+m[i-1][w-weight[i-1]],m[i-1][w]);
            if(max(value[i-1]+m[i-1][w-weight[i-1]],m[i-1][w]) == (value[i-1]+m[i-1][w-weight[i-1]]) && w==maxweight) finalweight+=weight[i-1];
        }
        else
            m[i][w]=m[i-1][w];
    }
}
    cout<<finalweight<<" "<<m[noofitems][maxweight]<<endl;
}


int main()
{
    int b,p,i,j,*pcost,*fun;
    cin>>b>>p;
    pcost=new int[p];
    fun=new int[p];

    while(b!=0 && p!=0){
        for(i=0;i<p;i++)cin>>pcost[i]>>fun[i];
        solveknapsack(b,p,pcost,fun);
        cin>>b>>p;
    }

    return 0;
}
