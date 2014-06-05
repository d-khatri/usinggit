#include <iostream>
#include <cstdlib>
#include<algorithm>
#include <list>
using namespace std;

class hashing
{
	list<long long int> *a;  //array of pointers that stores remainders as indices
	public:
		hashing()
		{
			a=new list<long long int>[50000];
		}
		void insertel(long long int x)
		{
			long long int i=x%50000,b;   //i is the remainder and also the index for particular value being inserted
			b=searchel(x);		//checking if new element is not a duplicate entry 
			if(b==-1)			//if element not duplicate, then insert
			{
				a[i].push_back(x);		
				a[i].sort();		//sorting each time when new value is inserted
				cout<<x<<" inserted.\n";
			}
			else 
				cout<<x<<" already present, not inserted.\n";	//element not inserted if already present
		}
		void deleteel(long long int x)
		{
			long long int i=x%50000;
			a[i].remove(x);			//delete the element
			cout<<x<<" deleted.\n";
		}
		int searchel(long long int x)
		{
			long long int i=x%50000,flag=1;
			if(binary_search(a[i].begin(),a[i].end(),x))	//searching value using binary search: binary_search(start of the list,end of the list, value to search)
			{
				cout<<x<<" found.\n";
				return(1);	//if found return 1
			}
			else return(-1);	//else return -1
		}
};
int main() {
	cout<<"Simple Hash Table Implementation(50000 modulo, sorted array with binary search): \n\n";
	
	hashing obj;
	long long int x,b,ch;
	while(1)
	{
		cout<<"1.Insert\n2.Delete\n3.Search\n4.Exit\nEnter Your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Enter element to insert: ";
					cin>>x;
					obj.insertel(x);
					break;
			case 2: cout<<"Enter element to delete: ";
					cin>>x;
					b=obj.searchel(x);	//first search if element is actually present or not
					if(b!=-1)			
						obj.deleteel(x);	//if element found,then delete
					else cout<<"Element not found.\n";
					break;
			case 3: cout<<"Enter element to search: ";
					cin>>x;
					b=obj.searchel(x);
					break;
			case 4: exit(0);
			default: cout<<"Enter correct choice.\n\n";
					break;
		}
	}
	return 0;
}