#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

//#define DEBUG

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define FOR(i,a,b) for(register int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)

int main()
{
    LL i,j,n,m,x,y,p,ans,**arry;
    while(1){
    cin>>n>>m>>p;
    arry = new LL*[n+1];

    REP(i,n+1){
        arry[i] = new LL[m+1];
    }

    REP(i,n+1){
        REP(j,m+1){
            arry[i][j]=0;
        }
    }

    #ifdef DEBUG
        cout<<"array is \n";
        REP(i,n+1){
            REP(j,m+1){
                cout<<arry[i][j]<<" ";
            }
            cout<<endl;
        }
    #endif // DEBUG

    REP(i,p){
        cin>>x>>y;
        arry[x][y]++;

        #ifdef DEBUG
            cout<<"array is \n";
            REP(i,n+1){
                REP(j,m+1){
                cout<<arry[i][j]<<" ";
                }
            cout<<endl;
            }
        #endif // DEBUG

    }


    FOR(i,1,n+1){
        ans=n-1;
        for(j=m;j>=1;j--){
            if(arry[i][j-1]>arry[i][j]+1){
                ans=-1;
                break;
            } else {
                if(j!=1)ans+=arry[i][j]-arry[i][j-1];
            }

        }
        printf("%lld\n",ans);
    }
    }
    return 0;
}


7615031696
