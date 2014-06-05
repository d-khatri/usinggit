#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>
#include <stack>
#include <math.h>
using namespace std;

int findmaxsubarray(vector <int > inarray){
    int max_so_far,max_ending_here;
    max_so_far=max_ending_here=inarray[0];
    for(size_t i=1;i<inarray.size();i++){
        if(max_ending_here<0) max_ending_here=inarray[i];
        else {
            max_ending_here+=inarray[i];
        }
        if(max_so_far<=max_ending_here)max_so_far=max_ending_here;

    }
    return max_so_far;
}

int main()
{
    int input,output;
    vector <int> data;
    cout<<"give -99 to stop\n";
    cin>>input;
    while(input!=-99){
        data.push_back(input);
        cin>>input;
    }
    output=findmaxsubarray(data);
    cout<<output<<endl;
    return 0;
}
