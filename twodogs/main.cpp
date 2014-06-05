#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;


int main()
{
long long int *arry,*store,mins,i;
long long int n,k;


cin>>n>>k;
store=new long long int[n+1];
arry=new long long int[1000001];
for(i=0;i<1000001;i++)arry[i]=0;


for(i=1;i<=n;i++){
    cin>>store[i];
    if( (i<=n/2) && (arry[store[i]]==0) )    arry[(store[i])]=i;
}



for(i=n;i>=ceil(n/2);i--){
    if(arry[store[i]]==0)arry[store[i]]=(n-i+1);
    else if( arry[store[i]]!=0 && arry[store[i]]>(n-i+1) )arry[store[i]]=(n-i+1);
}

//for(i=1;i<=n;i++)cout<<arry[store[i]]<<"\t";
//cout<<endl;

mins=1000001;
for(i=1;i<k;i++){
    if(arry[i]!=0 && arry[(k-i)]!=0 && (i!=(k-i))){
        if(max(arry[i],arry[k-i])<mins){mins=max(arry[i],arry[k-i]);}
    }
}
if(mins==1000001)cout<<"-1\n";
else cout<<mins<<endl;
return 0;
}
