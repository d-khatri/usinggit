#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<algorithm>
//typedef long long int long long int;
#define MAXI 10//50000000
#define MAXD 5//1000000
#define MAXS 6//1000000000
using namespace std;

int bin_search(long long int* arry,long long int siz,long long int num){
	if(siz==0)return -1;	
	long long int first=0,last=siz-1;
	long long int middle=(first+last)/2;
	while(first<=last){
		if(num>arry[middle]){ first=middle+1; }
		if(num<arry[middle]){last=middle-1;}
		if(num==arry[middle]){ /*printf(" location is %lld",(middle+1));*/ return (middle);}
		middle=(first+last)/2;
	}
return -1;
}


int main(){
	long long int arry[MAXI],i,temp,siz=0; 
	int result;
	ifstream readptr;
	readptr.open("file.txt");
	

	for(i=0;i<MAXI;i++){															/*insertion*/
		readptr>>temp;
		result=bin_search(arry,siz,temp);
		if(result==-1){		
			arry[siz++]=temp;
			sort(arry,arry+siz);
		}
	}


	for(i=0;i<MAXD;i++){															/*deletion*/
		readptr>>temp;	
		result=bin_search(arry,siz,temp);
		cout<<result<<endl;
		if(result==-1) printf("not persent in current array\n");
		if(result!=-1){
			cout<<"persent and result is "<<result<<endl;			
			arry[result]=arry[siz-1];
			siz-=1;
			sort(arry,arry+siz);		
		}
	}
	for(int j=0;j<siz;j++)cout<<arry[j]<<"\t";cout<<endl;



	for(i=0;i<MAXS;i++){														    /*bin_search*/
		readptr>>temp;
		result=bin_search(arry,siz,temp);
		printf("key found result is %d\n",result);
	}
	for(int j=0;j<siz;j++)cout<<arry[j]<<"\t";cout<<endl;
	readptr.close();
return 0;
}