#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t,p[11],n,i,current,temp,counter;
    cin>>t;
    while(t--){
        for(i=0;i<11;i++)cin>>p[i];

        cin>>n;
        sort(p,p+11);
        current=p[n-1];
        counter=0;
        for(i=0;i<11;i++){
            if(p[i]==current)counter++;
        }
        cout<<"counter is "<<counter<<endl;
        if(counter!=1)cout<<(counter*(counter-1))/2<<endl;
        else cout<<"1\n";

    }
    return 0;
}
