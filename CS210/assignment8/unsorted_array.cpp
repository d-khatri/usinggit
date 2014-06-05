#include<iostream>
#include<cstdlib>
#include<fstream>
#include<algorithm>
#defind long long int ll;
#define MAXI 50000000;
#define MAXD 1000000;
#define MAXS 1000000000;
using namespace std;

bool search(ll* arry,ll siz;ll num){
	for(ll i=0;i<siz;i++){
		if(arry[i]==num) return true; 
	}
return false;
}


int main(){
	ll arry[MAXI],i,temp,siz=0; 
	bool result;
	ifstream readptr;
	readptr.open("file.txt");
	

	for(i=0;i<MAXI;i++){															/*insertion*/
		readptr>>temp;
		result=search(arry,siz,temp);
		if(result==false){		
			a[siz++]=temp;
		}
	}
	
	for(i=0;i<MAXD;i++){															/*deletion*/
		readptr>>temp;		
		result=search(arry,siz,temp);
		if(result==false) cout<<"not persent in current array\n";
		if(result==true){
			arry[i]=arry[siz-1];
			siz-=1;		
		}
	}
	
	for(i=0;i<MAXS;i++){														    /*search*/
		readptr>>temp;
		cout<<search(arry,siz,temp);
	}	

	readptr.close();
return 0;
}