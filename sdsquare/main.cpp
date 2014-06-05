#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int cps(int num){


}

int main()
{
    int t,a,b,sqrta,sqrtb,ans,j;
    cin>>t;
    while(t--){
        ans=0;
        scanf("%d %d",&a,&b);
        sqrta=sqrt(a);
        sqrtb=sqrt(b);
        for(int i=sqrta;i<=sqrtb;i++){
            if(cps(i)==1)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
