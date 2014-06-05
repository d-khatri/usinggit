#include <iostream>

using namespace std;

int main()
{
    int t,n,c,answer;
    cin>>t;
    while(t--){
        answer=0;
        cin>>n>>c;
        if(n%c==0)answer=(n/c)-1;
        cout<<answer<<endl;
    }
    return 0;
}
