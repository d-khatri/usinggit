#include <iostream>

using namespace std;

int main()
{
    int t;
    long long int n,temp,answer;
    cin>>t;
    while(t--){
        cin>>n;
        temp=n%7;
        if(n==4)answer=0;
        else if(temp==0 )answer = n;           //n=7q+temp
        else if(temp==1)answer=( (((n-1)/7)-1)*7 );
        else if(temp==2)answer=( (((n-2)/7)-2)*7 );
        else if(temp==3)answer=( (((n-3)/7)-3)*7 );
        else if(temp==4)answer=( n-4 );
        else if(temp==5)answer=( (((n-1)/7)-1)*7 );
        else if(temp==6)answer=( (((n-2)/7)-2)*7 );
        if(answer>=0)cout<<answer<<endl;
        else cout<<"-1\n";
    }
    return 0;
}
