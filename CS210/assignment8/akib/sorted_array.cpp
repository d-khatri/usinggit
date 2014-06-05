#include<iostream>
#include<vector>
#include<stack>
#include<stdlib.h>
#include<fstream>
#include<time.h>
#include<algorithm>

using namespace std;
class sorted
{
	public:
	long long int A[50000],N;
	sorted()
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
			sort(A,A+N);
		}
		else
		{
			cout<<"duplicates can't be inserted"<<endl;
		}
	}
	long long int search(long long int key)
	{
		long long int low = 1,high = N,mid;
		do
		{
			mid = (low + high) / 2;
			if (key < A[mid])
			{
			   high = mid - 1;
		    }
			else if(key >A[mid])
			{
			   low = mid + 1;
	   	    }
		}while(key != A[mid] && low <= high);
		
		if (key == A[mid])
		{
			return mid;
		}
		else
		{
			return -1;
		}
	}
	
	void del(long long int key)
	{
		long long int i,j,victim,temp;
		victim=search(key);
		if(victim!=N)
		{
			A[victim]=A[N-1];
			N--;
			sort(A,A+N);
		}
	}
};




int main()
{
	int start,end;
	start=clock();
	sorted s;
	ifstream fin;
	ofstream fout;
	int k;
	long long int key,p;
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
	
	cout<<"time: "<< (end-start)/double(CLOCKS_PER_SEC)<<"seconds"<<endl;
	cout<<"time: "<< (end-start)/(double(CLOCKS_PER_SEC)*60)<<"minutes"<<endl;
	
	
	return 0;
}

