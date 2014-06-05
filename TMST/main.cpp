//this is comment lol
#include <iostream>
#include <algorithm>
#include <fstream>
#include <math.h>
using namespace std;

int main()
{
    long long int t,i,j,n,a,b,c,d,*arry,*countarry,temp,ans;
    //freopen("input.txt","r",stdin);
    arry=new long long int[3000000];
    countarry = new long long int[1000000];
    cin>>t;
    while(t--){
        cin>>n>>a>>b>>c>>d;
        ans=0;
        for(i=0;i<1000000;i++)countarry[i]=0;

        arry[0]=d;countarry[d]++;

        for(i=1;i<n;i++){
            temp=a*arry[i-1]*arry[i-1]+b*arry[i-1]+c;
            if(temp<1000000){
                arry[i]=temp;
                countarry[temp]++;
            }
            else{
                temp=temp%1000000;
                arry[i]=temp;
                countarry[temp]++;
            }
        }


        for(i=0,j=0;i<n;){
            if(countarry[j]!=0){
                arry[i]=j;countarry[j]--;i++;
            }   else   j++;
        }

        for(i=0;i<n;i=i+2){
            ans+=arry[i];
        }
        if(n>1){
            for(i=1;i<n;i=i+2){
                ans-=arry[i];
            }
        }



        cout<<llabs(ans)<<endl;
        //cout<<"--------------------------------\n";
    }
    return 0;
}
