#include<iostream>
#include<vector>
#include<stack>
#include<stdlib.h>
#include<fstream>
#include<time.h>

	


using namespace std;
int main()
{
	long long int i, key;
	int insert=1, del=2, serch=3,ext=0;
	ofstream fout;
	
		for(i=0;i<50;i++)
		{
			key=rand();
			cout<<insert<<endl;
			cout<<key<<endl;
			
		}
		for(i=0;i<10;i++)
		{
			key=rand();
			cout<<del<<endl;
			cout<<key<<endl;
			
		}
		for(i=0;i<100;i++)
		{
			key=rand();
			cout<<serch<<endl;
			cout<<key<<endl;
			
		}
		cout<<ext<<endl;
		
		
	}

