#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long int t,leaves,level,stems,i;
    cin>>t;
    while(t--){

        stems=1;
        leaves=0;
        scanf("%lld",&level);

        for(i=1;i<=level;i++){
            scanf("%lld",&leaves);
            if(leaves>stems) break;
            stems=2*(stems-leaves);
        }


        if(stems!=0 || i!=(level+1) )printf("No\n");
        else if(stems==0)printf("Yes\n");
    }
    return 0;
}
