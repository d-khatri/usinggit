#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;
int main()
{
    long long int n,m,l,i,j,**arry,e1,e2,flag1,flag2,temp1,temp2;
    cin>>n>>m;
    e1=e2=flag1=flag2=0;

    arry=new long long int*[n];

    for(i=0;i<n;i++){
        arry[i]=new long long int[m];
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%lld",&arry[i][j]);
        }
    }

    cin>>l;

    for(i=0;i<l;i++){

        scanf("%lld %lld",&temp1,&temp2);
        if( ( (temp1-1)>n) || ((temp2-1)>m) )flag1=-1;
        else{
            e1+=arry[temp1-1][temp2-1];
        }
        if( ((temp2-1)>n) || ((temp1-1)>m) )flag2=-1;
        else{
            e2+=arry[temp2-1][temp1-1];
        }

    }
    if(flag1==-1 && flag2!=-1)cout<<e2<<endl;
    else if(flag2==-1 && flag1!=-1)cout<<e1<<endl;
    else if(flag1==-1 && flag2==-1)cout<<-1<<endl;
    else if(flag1!=-1 && flag2!=-1)cout<<max(e1,e2)<<endl;
    return 0;
}
