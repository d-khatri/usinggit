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

int main()
{
    int i,j,k,t,n,a,b,c,counter,flag1,flag2;
    cin>>t;
    while(t--){
        cin>>n>>a>>b>>c;
        counter=flag1=flag2=0;

        for(i=0;i<=a;i++){

            for(j=0;j<=b;j++){

                for(k=0;k<=c;k++){

                    if(i+j+k>n){break;}
                    else {counter++;}
                }

            }

        }
        cout<<counter<<endl;
    }
    return 0;
}
