#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstdlib>
using namespace std;

bool prime(int n){
    if(n>2 && n%2==0)return false;
    else if(n>3 && n%3==0)return false;
    else if(n>5 && n%5==0)return false;
    else if(n>7 && n%7==0)return false;
    else if(n>11 && n%11==0)return false;
    else {
        for(int i=2;i<n;i++){
            if(n%i==0){return false;}
        }
    }
return true;
}

bool pel(string s){
    int n=s.length();
    for(int i=0;i<=n/2;i++){
        if(s[i]!=s[n-1-i])return false;
    }
return true;
}

int main()
{
    string stemp;
    for(int i=1;i<=1000010;){
        if(prime(i)){
            stringstream out(i);
            stemp<<out;
            {
                if(pel())
            }
            }
        }
    }
    return 0;
}
