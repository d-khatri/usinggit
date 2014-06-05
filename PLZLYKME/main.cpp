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

int fact(int n){
    if(n==0) return 1;
    if (n>0) return n*fact(n-1);
};

int NCR(int n,int r){
    if(n==r) return 1;
    if (r==0&&n!=0) return 1;
    else return (n*fact(n-1))/fact(n-1)*fact(n-r);
};

int main()
{
    long long int t,l,d,s,c,flag;
    double answer;
    cin>>t;
    while(t--){
        scanf("%lld %lld %lld %lld",&l,&d,&s,&c);
        answer=flag=0;

        //for(int i=0;i<=d-1;i++){
          //  answer+=NCR(d-1,i)*pow(c,i);
        //}
        answer=pow((c+1),(d-1));
        answer*=s;
        //cout<<answer<<endl;
        if(answer>=l)flag=1;
        if(flag==1)printf("ALIVE AND KICKING\n");
        else printf("DEAD AND ROTTING\n");
    }
    return 0;
}
