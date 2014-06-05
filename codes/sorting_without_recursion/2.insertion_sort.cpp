#include <iostream>
using namespace std;

    void selection(int *a,int ctr){
		int temp=a[ctr-1],pos=0,j,k;
		for(k=0;k<ctr-1;k++){
			if(a[k]>temp)break;
		}
		for(j=ctr-2;j>=k;j--) a[j+1]=a[j];
		a[k]=temp;
    }    
    
int main()
{
	int i,ctr=0,a[50],num;
	cout<<"press -420 to stop\n";
	cin>>num;
	while(num!=-420){
		a[ctr++]=num;
		selection(a,ctr);
		for(i=0;i<ctr;i++)cout<<a[i]<<"\t"; cout<<endl;
		cin>>num; 
	}
    return 0;
}
