#include<iostream>
#include<algorithm>
#include<fstream>
#include<time.h>

using namespace std;
class unsorted
{
	public:
	long long int A[500000],N;
	unsorted()
	{
		N=0;
	}
	void insert(long long int key)
	{
		long long int p;
		p=search(key);
		if(p==-1)
		{
			A[N]=key;
			N++;
		}
		else
		{
			cout<<"duplicates can't be inserted"<<endl;
		}
	}
	long long int search(long long int key)
	{
		long long int i;
		for(i=0;i<N;i++)
		{
			if(key==A[i])
			{
			//	cout<<"\tthis key is found\n";
				return (i);
				break;
			}
		}
		if(i==N)
		{
		//	cout<<"\tthis key is not found!!!\n";
			return -1;
		}
		
	}
	void del(long long int key)
	{
		long long int i,j,victim,temp;
		victim=search(key);
		if(victim!=-1)
		{
			A[victim]=A[N-1];
			N--;
		}
	}
};
int main()
{
	int start,end;
	start=clock();
	unsorted s;
	ifstream fin;
	ofstream fout;
	int k;
	long long int key, p;
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
					p=s.search(key);
					if(p==-1)
					{
						cout<<"\tthis key is not found!!!\n";
					}else
					{
						cout<<"\tthis key found!!!\n";
					}
					break;
			default:
			 { return(0);}
		}
		
	}while(true);
	
	end=clock();
	
	cout<<"\n\n\n\n\ntime: "<< (end-start)/double(CLOCKS_PER_SEC)<<"seconds"<<endl;
	cout<<"time: "<< (end-start)/(double(CLOCKS_PER_SEC)*60)<<"minutes"<<endl;
	
	return 0;
}
