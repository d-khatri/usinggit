#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

struct person{
    int stime;
    int ftime;
    int apartment;
};

bool fun1(const person& lhs, const person& rhs)
{
  return lhs.ftime < rhs.ftime;
}

int main()
{

    int t,n,k,i,j,counter;
    map<int,int>m;
    cin>>t;
    while(t--){
        counter=0;  cin>>n>>k;
       // arry=new int[n+1];
        for(i=0;i<=n;i++)arry[i]=0;
        person *pointer = new person[n];

        for(i=0;i<n;i++){
            cin>>pointer[i].stime;
            cin>>pointer[i].ftime;
            cin>>pointer[i].apartment;
        }
        sort(pointer,pointer+n,fun1);
//        for(i=0;i<n;i++)cout<<pointer[i].stime<<"\t"<<pointer[i].ftime<<"\t"<<pointer[i].apartment<<endl;
//        for(i=0;i<=k;i++)cout<<arry[i]<<"\t";cout<<endl;
                                                        //  here not working by taking an array of size n
//        for(i=0;i<n;i++){
//            if(pointer[i].stime>=arry[(pointer[i].apartment)]){
////                cout<<"here arry[apartment] value is "<<arry[(pointer[i].apartment)]<<endl;
//                counter++; arry[(pointer[i].apartment)]=pointer[i].ftime;
//            }
//        }

        for(i=0;i<n;i++){
            if(m.find(pointer[i].apartment)==m.end() || m[pointer[i].apartment]<=pointer[i].stime ){
                m[pointer[i].apartment]=pointer[i].ftime;counter++;
            }

        }

        cout<<counter<<endl;

    }
    return 0;
}
