#include <iostream>
using namespace std;

void ssort(int *a,int n){
	int j,k,min,indx,temp;
	for(j=0;j<n;j++){
		min=a[j];
		for(k=j+1;k<n;k++){
			if(min>a[k]){
				min=a[k];
				indx=k;
			}
		}
		if(min!=a[j]){
			a[indx]=a[j];
			a[j]=min;
			}
	}
	for(j=0;j<n;j++)	cout<<a[j]<<"\t";
	cout<<endl;
}


int main()
{
    int n,j,*a;
    cin>>n;
    a=new int[n];
    for(j=0;j<n;j++) cin>>a[j];
    
    ssort(a,n);
    return 0;
}
