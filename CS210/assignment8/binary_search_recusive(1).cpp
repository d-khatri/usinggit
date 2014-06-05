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

bool bin_search(long long int* arry,long long int siz,long long int num){
	if(siz==0)return false;	
	long long int first=0,last=siz-1;
	long long int middle=(first+last)/2;
	while(first<=last){
		if(num>arry[middle]){ first=middle+1; }
		if(num<arry[middle]){last=middle-1;}
		if(num==arry[middle]){ /*printf(" location is %lld",(middle+1));*/ return (true);}
		middle=(first+last)/2;
	}
return false;
}


int main(){
	long long int arry[MAXI],i,temp,siz=0; 
	bool result;
	ifstream readptr;
	readptr.open("file.txt");
	

	for(i=0;i<MAXI;i++){															/*insertion*/
		readptr>>temp;
		result=bin_search(arry,siz,temp);
		if(result==false){		
			arry[siz++]=temp;
			sort(arry,arry+siz);
		}
	}
	cout<<"after 10th operatiom\n";
	for(i=0;i<siz;i++)cout<<arry[i]<<"\t"; cout<<endl;	

	for(i=0;i<MAXD;i++){															/*deletion*/
		readptr>>temp;	
		cout<<"value to delete is "<<temp<<endl;	
		result=bin_search(arry,siz,temp);
		if(result==true) printf("not persent in current array\n");
		if(result==false){
			cout<<"persent and result is "<<result<<endl;			
			arry[result]=arry[siz-1];
			siz-=1;
			for(int j=0;j<siz;j++)cout<<arry[j]<<"\t"; cout<<endl;
			sort(arry,arry+siz);		
			for(int j=0;j<siz;j++)cout<<arry[j]<<"\t"; cout<<endl;
		}
	}

	for(i=0;i<MAXS;i++){														    /*bin_search*/
		readptr>>temp;
		result=bin_search(arry,siz,temp);
		printf("key found result is %d\n",result);
	}	

	readptr.close();
return 0;
}