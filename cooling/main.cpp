#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
    int t,n,ans,temp,i;
	cin>>t;
	while(t--){
	    vector<int> weight;
        vector<int> cap;
        ans=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){scanf("%d",&temp); weight.push_back(temp);}
		for(i=0;i<n;i++){scanf("%d",&temp); cap.push_back(temp);}
		sort(cap,cap+n);
		for(i=0;i<n;i++){
			if(weight[i]<=cap[i])ans++;
		}
		printf("%d\n",ans);
	}
return 0;
}
