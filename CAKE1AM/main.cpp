#include <iostream>
#include <math.h>
#include <cstdio>
#include <stdlib.h>
using namespace std;

int main()
{
    int t,x1,y1,x2,y2,a1,b1,a2,b2,ar1,ar2,ar0,answer;
    cin>>t;
    while(t--){
        cin>>x1>>y1>>x2>>y2;
        cin>>a1>>b1>>a2>>b2;
        ar1=(x2-x1)*(y2-y1);
        ar2=(a2-a1)*(b2-b1);
        if(a1<x2 && a2>=x2){
            if(y2>b1 && b2>=y2)ar0=(x2-a1)*(y2-b1);
            else if(b2>y1 && y1>=b1)ar0=(x2-a1)*(b2-y1);
            else if(y2>=b2 && y1<=b1)ar0=(x2-a1)*(b2-b1);
            else if(b2>=y2 && b1<=y1)ar0=(x2-a1)*(y2-y1);
            else ar0=0;
        }
        else if(a2>x1 && a1<=x1){
            if(y2>b1 && b2>=y2)ar0=(a2-x1)*(y2-b1);
            else if(b2>y1 && y1>=b1)ar0=(a2-x1)*(b2-y1);
            else if(y2>=b2 && y1<=b1)ar0=(a2-x1)*(b2-b1);
            else if(b2>=y2 && b1<=y1)ar0=(a2-x1)*(y2-y1);
            else ar0=0;
        }
        else ar0=0;
        answer=ar1+ar2-ar0;
        cout<<answer<<endl;
    }
    return 0;
}
