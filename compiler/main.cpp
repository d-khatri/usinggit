#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <stack>
using namespace std;

//#define DEBUG

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define FOR(i,a,b) for(register int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)

int main()
{
    LL i,j,t,counts,tempcounts;
    string temp;
    cin>>t;

    REP(j,t){

        stack<char>mystack;
        cin>>temp;
        counts=tempcounts=0;
        #ifdef DEBUG
        cout<<"taken input is "<<temp<<endl;
        #endif
        REP(i,temp.length()){
            #ifdef DEBUG
            printf("temp[i] is %c\n",temp[i]);
            #endif
            if(temp[i]=='<' ){
                mystack.push(temp[i]);
                //counts++;
            } else if(temp[i]=='>' && mystack.empty()==true){
                break;
            } else if(temp[i]=='>' && mystack.top()=='<'){
                mystack.pop();
                tempcounts+=2;
            }


            if(mystack.empty()==true){
                counts+=tempcounts;
                tempcounts=0;
            }
        }
        printf("%lld\n",counts);

    }


    return 0;
}
