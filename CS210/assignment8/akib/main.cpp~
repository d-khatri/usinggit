#include<iostream>
#include<vector>
#include<stack>
#include<stdlib.h>
#include<fstream>
#include<time.h>
#include"hash.h"
#define M 50000

using namespace std;

int main()
{
	int start,end;
	start=clock();
	hash s;
	//ifstream fin;
	//ofstream fout;
	int k;
	unsigned long long int key,p;
	do
	{
		cout<<"\n~~~~~~choose your option~~~~~~~\n"
			<<"\n\t1.add new element"
			<<"\n\t2.delete an element"
			<<"\n\t3.search an element"
			<<"\n\tany other choice to exit"<<endl;

		cin>>k;
		switch(k)
		{
			case 1: cout<<"enter the element value: ";
					cin>>key;
					s.insert(key);
					break;
			case 2: cout<<"enter the element value: ";
					cin>>key;
				//	c=0;
					s.del(key);
					break;
			case 3: cout<<"enter the element value: ";
					cin>>key;
				//	s.search(key);
					if(s.search(key)==NULL)
					{
						cout<<"\tthis key is not found!!!\n";
					}else
					{
						cout<<"\tthis key found!!!\n";
					}
					break;
			default:
			 {end=clock();

	cout<<"time: "<< (end-start)/double(CLOCKS_PER_SEC)<<"seconds"<<endl;
	cout<<"time: "<< (end-start)/(double(CLOCKS_PER_SEC)*60)<<"minutes"<<endl;
 return(0);}
		}

	}while(true);


	return 0;
}
