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
    string stone,jewel;
    int t,i,j,counter;
    cin>>t;
    while(t--){
        counter=0;
        cin>>jewel>>stone;

        int *arry;
        arry=new int[stone.length()];
        for(i=0;i<stone.length();i++)arry[i]=0;

        for(i=0;i<int(stone.length());i++){
                for(j=0;j<int(jewel.length());j++){
                    if(stone[i]==jewel[j] && arry[i]==0){counter++; arry[i]=1;}
                }
        }
        cout<<counter<<endl;
    }
    return 0;
}
