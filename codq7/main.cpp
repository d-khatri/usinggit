#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int t,d,m,days;

    while(cin>>t){
    cin>>d>>m;
    if(m==1)days=d;
    else if(m==2)days=37+d;
    else if(m==3)days=79+d;
    else if(m==4)days=108+d;
    else if(m==5)days=142+d;
    else if(m==6)days=193+d;
    days=days%6;
    cout<<days<<endl;
    }
    return 0;
}
