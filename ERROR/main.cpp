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
    long long int i,t,f1,f2,f3,f4,f5,f6,s;
    string store;
    cin>>t;
    while(t--){
        f1=f2=f3=f4=f5=f6=s=0;
        cin>>store;
        //cout<<"string is "<<store<<endl;

        if(store[0]==48)f1=1;
        else f4=1;

        for(i=1;i<store.length();i++){
            if( int(store[i])==49 ){
                if(f1==1){ f2=1;f1=f3=f4=f5=f6=0;}
                else if(f4==1 || f2==1){ f4=1;f1=f2=f3=f5=f6=0;}
                else if(f5==1){ f6=1;f1=f2=f3=f4=f5=0;s=1;}

            } else {
                if(f1==1 || f5==1){ f1=1;f2=f3=f4=f5=f6=0;}
                else if(f2==1){ f3=1;f1=f2=f4=f5=f6=0; s=1;}
                else if(f4==1){ f5=1;f1=f2=f3=f4=f6=0;}
            }
        }
        if(s==1)cout<<"Good\n";
        else cout<<"Bad\n";
    }
    return 0;
}
