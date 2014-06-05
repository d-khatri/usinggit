#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

struct rowprofit{
    int profit;
    int flag;
    int row;
};

bool fun1(const rowprofit &lhs,const rowprofit &rhs){
    if(lhs.flag!=rhs.flag && lhs.flag>rhs.flag)return false;
    else if(lhs.flag!=rhs.flag && lhs.flag<rhs.flag)return true;
    else if(lhs.flag==rhs.flag && lhs.profit>rhs.profit) return false;
    else if(lhs.flag==rhs.flag && lhs.profit<rhs.profit) return true;
}

int main()
{
    int t,n,m,k,**profit,**loss,*icolor,i,j,maxs,tempprofit,flag,ans;
    //freopen("input.txt","r",stdin);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        ans=0;
        struct rowprofit* pointer;
        pointer=new struct rowprofit[n];
        icolor=new int[n]; profit=new int*[n]; loss=new int*[n];

        for(i=0;i<n;i++){profit[i]=new int[m];loss[i]=new int[m];}

        for(i=0;i<n;i++)cin>>icolor[i];
        for(i=0;i<n;i++)for(j=0;j<m;j++) cin>>profit[i][j];
        for(i=0;i<n;i++) for(j=0;j<m;j++) cin>>loss[i][j];

        for(i=0;i<n;i++){
            for(j=0,maxs=-1;j<m;j++){
                if(icolor[i]==(j+1)){tempprofit=profit[i][j];flag=j;}
                else {tempprofit=profit[i][j]-loss[i][j];}
                if(tempprofit>maxs)maxs=tempprofit;
            }
            if(maxs==profit[i][flag])flag=1;else flag=0;
            pointer[i].profit=maxs;pointer[i].flag=flag;pointer[i].row=i;
        }

        sort(pointer,pointer+n,fun1);

        //for(i=0;i<n;i++)cout<<pointer[i].row<<"\t"<<pointer[i].profit<<"\t"<<pointer[i].flag<<endl;

        for(i=0;i<n;i++,k--){
            if(k)ans+=pointer[i].profit;
            else{ans+=profit[(pointer[i].row)][(icolor[(pointer[i].row)])-1];}
        }

        cout<<ans<<endl;

    }
    return 0;
}
