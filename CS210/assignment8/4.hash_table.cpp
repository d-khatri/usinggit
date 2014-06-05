/*cin>>num;
calculate bucket no. by hash function return bucket no
insert(num,bucket no)
search->locate bucket no->linear search ->delete node*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<fstream>
#include<cstdlib>
#include<algorithm>
using namespace std;

int hash_value(int num){
	return num%50000;
}

bool checkispersent(vector<int>* myvec,int bucketno,int number) {
	vector<int>::iterator it;
	it=find(myvec[bucketno].begin(),myvec[bucketno].end(),number);
	if(it==myvec[bucketno].end())return false;
	else
		return true;
}

bool insert(vector<int> *myvec,int bucketno,int number){
	myvec[bucketno].push_back(number);
}

int main(){
	int number=100;
	int temp =number;
	bool result;
	vector<int>myvec[50000];
	int bucketno=hash_value(temp);
	vector<int>::iterator it;

	result=checkispersent(myvec,bucketno,number);

	cout<<"bucket value and resullt is "<<bucketno<<"\t"<<result<<endl;
	if(result==false){
		insert(myvec,bucketno,number);
	}

	//for deletion chceck whether the number is persent
	it=find( (myvec[bucketno]).begin(),(myvec[bucketno]).end(),number);
	temp=myvec[bucketno].back();								//if we use vector.erase() that will shift all element time increase
	myvec[bucketno].pop_back();
	if(it!=NULL)
	*it=temp;

	for(it=myvec[100].begin();it!=myvec[100].end();it++)cout<< (*it) <<"\t"; cout<<endl;
	return 0;
}
