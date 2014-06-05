#include <iostream>
#include <vector>
using namespace std;

void divide(vector <int> myarray,int n){

    if(n==0 || n==1 )return;

    else{
    vector <int> leftv;
    vector <int> rightv;
    int i,j;
    for(i=0;i<n/2;i++) leftv.push_back(myarray[i]);
    for(i=n/2;i<n/;i++) rightv.push_back(myarray[i]);

    divide(leftv,n/2);
    divide(rightv,n/2);
    merge_array(leftv,rightv);
    }
}

int merge_array(vector <int> leftvec, vector <int> rightvec){
int countinversion;


return countinversion;
}

int main()
{
    int temp;
    vector <int> myvec;

    cout<<"enter your array elements and to stop press -99\n";
    cin>>temp;

    while(temp!=-99){
        myvec.push_back(temp);
        cin>>temp;
    }
    return 0;
}
