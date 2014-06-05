#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    int t;
    vector <int> vec;
    cin>>t;
    while(true){
        if(t!=42)vec.push_back(t);
        else break;
        cin>>t;
    }
    for(int i=0;i<vec.size();i++)cout<<vec[i]<<endl;
    return 0;
}
