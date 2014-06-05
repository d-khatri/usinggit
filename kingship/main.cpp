#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long int t,n,*arry,ans;
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        arry=new long long int[n];
        for(long long int i=0;i<n;i++){
            cin>>arry[i];
        }
        sort(arry,arry+n);
        for(long long int j=1;j<n;j++){
            ans+=arry[0]*arry[j];
        }
        cout<<ans<<endl;
    }
    return 0;
}
