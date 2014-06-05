#include<iostream>
#include<vector>
#include<stack>
#include<stdlib.h>
#include<fstream>
#include<time.h>
#include"hash.h"
#define M 50000

using namespace std;

node::node()
{
link=NULL;
}
	void hash::insert(unsigned long long int key)
	{
		long long int i;
		node *p, *q, *n1;
		q=search(key);
		if(q==NULL)
		{
			i=key%M;
			n1= new node;
			n1->data=key;
			n1->link=NULL;
			if(A[i]->link==NULL)
			{//cout<<"hii\n";
				A[i]->link=n1;
			}
			else
			{//cout<<"hi1\n";
				p=A[i]->link;
				while(p->link!=NULL)
				{
					p=p->link;
				}
				p->link=n1;
			}
		}
		else
		{
			cout<<"duplicates can't be inserted"<<endl;
		}
	}

	node* hash::search(unsigned long long int key)
	{
		unsigned long long int i;
		node *p, *q, *n1;
		int flag=0;
		i=key%M;
		if(A[i]->link==NULL)
		{
            //cout<<"next is NULL\n";
		//	cout<<"key is not found"<<endl;
			return NULL;
		}
		else
		{
            //cout<<"next is not NULL\n";
			p=A[i]->link;
			while(p!=NULL)
			{
				if(p->data==key)
				{
					flag=1;
					return p;
					break;
				}
				else
				{
					p=p->link;
				}
			}
			if(flag==0)
			{
			//	cout<<"key is not found"<<endl;
				return NULL;
			}
		}
	}


	void hash::del(unsigned long long int key)
	{
		unsigned long long int i,flag=0;
		node *p, *q, *n1, *r;
		q=search(key);
		if(q!=NULL)
		{
			i=key%M;
			if(q==A[i]->link)
			{
				A[i]->link=q->link;
				q->link=NULL;
				delete q;flag=1;
			}
			else
			{
				p=A[i]->link;
				while(p->link!=q && p->link != NULL)
				{
					p=p->link;
				}

				if(p->link==q)
				{
					p->link=q->link;
					q->link=NULL;
					delete q;flag=1;
				}
			}
		}
if(flag==1)
cout<<"Value is deleted\n";
else
cout<<"value is not present\n";

	}



