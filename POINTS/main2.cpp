#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
using namespace std;

#define square(a) (a)*(a)

double dist(pair<int,int>a,pair<int,int>b){
return sqrt(square(a.first-b.first)+square(a.second-b.second));
}

int main(){
    int t,num,i;
    pair<int,int>a[100002];
    double answer=0,temp;
    cin>>t;

    while(t--){
        cin>>num;
        answer=0;
        for(i=1;i<=num;i++){
            cin>>a[i].first>>a[i].second;
            a[i].second=-a[i].second;
        }
        //cout<<endl;
        sort(a+1,a+num+1);

        for(i=1;i<num;i++){
            //cout<<a[i].first<<"\t"<<a[i].second<<"\tand\t"<<a[i+1].first<<"\t"<<a[i+1].second<<endl;;
            temp=dist(a[i],a[i+1]);
            //cout<<temp<<endl;
            answer+=temp;
            //answer+=sqrt( pow((a[i].first-a[i+1].first),2)+pow( (a[i].second-a[i+1].second),2) );
        }

        printf("%0.2f\n",answer);

    }
return 0;
}
