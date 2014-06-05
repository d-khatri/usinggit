#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

#define MAX 10000000

int main()
{
    int t,mins,f1,f2,f3,i,j,counter;
    string name;
    cin>>t;
    while(t--){
        f1=f2=f3=0;
        cin>>name;
        mins=MAX;
        for(j=0;j<name.length();j++){
            f1=f2=f3=counter=0;
            for(i=j;i<name.length();i++){
                counter++;
                if(name[i]=='R')f1=1;
                if(name[i]=='G')f2=1;
                if(name[i]=='B')f3=1;
                if(f1==1 && f2==1 && f3==1)break;
            }
           // cout<<counter<<endl;
        if(counter<mins && f1==1 && f2==1 && f3==1)mins=counter;
        }
        cout<<mins<<endl;
    }
    return 0;
}
