#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

string convertinstring(char &oldc){

stringstream ss;
string s;
ss<<oldc;
ss>>s;
return s;
}

int main()
{
    int t,temp2;
    char c;
    string temp,first,second,coperand;
    stack <string> operands;
    stack <string> operators;
    cin>>t;
    t++;
    temp2=t;
    while(t--){
        if(temp2==t)getchar();
        c=getchar();
        //cout<<"in\n";
        //cout<<"c is "<<c<<endl;
        while(c!='\n'){
            //cout<<"in while \n";
            if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')operators.push(convertinstring(c));
            else if(c==')'){
                second=operands.top();   operands.pop();
                first=operands.top();   operands.pop(); operands.pop();
                coperand=operators.top(); operators.pop();
                temp=first+second+coperand;
                //cout<<"tmep is "<<temp<<endl;
                operands.push(temp);
            } else operands.push(convertinstring(c));
            c=getchar();
        }

        if(!operands.empty())cout<<operands.top()<<endl;

    }
    return 0;
}
