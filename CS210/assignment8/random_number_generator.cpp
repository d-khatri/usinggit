#include<iostream>
#include<cstdlib>
#include<time.h>
#include<fstream>
#include<math.h>
using namespace std;

int main(){
	long long int rangeint,temp1int,temp2int,temp3int;
	double range=pow(2,62);
	double temp1=50*pow(10,6);
	double temp2=pow(10,6);
	double temp3=pow(10,9);
	
	temp1int=(int)temp1; temp2int=(int)temp2; temp3int=(int)temp3;	rangeint=(long long int)range;
	cout<<rangeint<<"\t"<<temp1int<<"\t"<<temp2int<<"\t"<<temp3int<<"\t"<<endl;	

	ofstream strmptr;
	strmptr.open("largeinputfile.txt");

	while(temp1--){
		strmptr<<(rand()%rangeint)<<endl;
	}
	
	while(temp2--){
		strmptr<<(rand()%rangeint)<<endl;
	}
	
	while(temp3--){
		strmptr<<(rand()%rangeint)<<endl;
	}
		
	strmptr.close();
	return 0;
}