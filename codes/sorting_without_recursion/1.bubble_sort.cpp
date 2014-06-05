#include <iostream>
using namespace std;

void bubble(int *a,int n){
int j,k,temp,p=1;

	for(k=1;k<n;k++){
    	for(j=0;j<(n-k);j++){
    	    
    	    if(a[j]>a[j+1]){ temp=a[j+1];	a[j+1]=a[j];		a[j]=temp;
    	   		 p++; /*count no. of swaps if no swaps then array is sorted done in linear time */  }
    		}
	if(p==1)
	break;
	}

	for(j=0;j<n;j++) cout<<a[j]<<" ";
}


int main()
{
int i,n,*a;
cin>>n;
a=new int[n];
for(i=0;i<n;i++) cin>>a[i];

bubble(a,n);
    return 0;
}
