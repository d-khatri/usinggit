#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int i,t,n,x,*arry,sum,temp1,temp2,answer;
    cin>>t;
    while(t--){
        sum=0;
        cin>>n>>x;
        arry=new int[n];

        for(i=0;i<n;i++){
            cin>>arry[i];
            sum+=arry[i];
        }

        temp1=sum/x;
        temp2=*min_element(arry,arry+n);
        if(temp1==(sum-temp2)/x)answer=-1;
        else answer=temp1;

        cout<<answer<<endl;
    }
    return 0;
}
