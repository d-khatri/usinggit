#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    long long int n,*values,q,i,j,**dparray,query,counter;
    cin>>n;
    values = new long long int[n];

    dparray= new long long int*[n];
    for(i=0;i<n;i++) dparray[i] = new long long int[n];

    for(i=0;i<n;i++)cin>>values[i];

    cin>>q;

    for(i=0;i<n;i++){dparray[i][i]=values[i];}

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
             if(i>j)dparray[i][j]=0;
             else if(i==j){}
             else{
                dparray[i][j]=min(dparray[i][j-1],values[j]);
             }
        }
    }

//    for(j=0;j<n;j++){
//        for(i=0;i<n;i++)cout<<dparray[i][j]<<"\t";
//        cout<<endl;
//    }

    while(q--){
        counter=0;
        cin>>query;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                if(dparray[i][j]==query)counter++;
        }
        cout<<counter<<endl;
    }
    return 0;
}
