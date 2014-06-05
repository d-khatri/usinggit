#include <iostream>

using namespace std;

int main()
{
    string str="zyxwvutsrqponmlkjihgfedcba";
    string tempstr="";
    int testcase,input,temp,tempinput;
    cin>>testcase;
    while(testcase--){
        cin>>input;
        tempstr="";
        tempinput=input%25;
        if(tempinput!=0){
            for(int i=(26-tempinput-1);i<=(str.size()-1);i++){
                tempstr+=str[i];
            }
        }

        if(1<=input && input<25){
            //cout<<"1\n";
        }
        if(25<=input && input<50){
            tempstr+=str;
            //cout<<"2\n";

        } else if(50<=input && input<75){
            tempstr+=str; tempstr+=str;
            //cout<<"2\n";
        }
        else if(75<=input && input<100){
            tempstr+=str; tempstr+=str; tempstr+=str;
            //cout<<"4\n";
        }
        if(input==100)
            cout<<"zyxwvutsrqponmlkjihgfedcbazyxwvutsrqponmlkjihgfedcbazyxwvutsrqponmlkjihgfedcbazyxwvutsrqponmlkjihgfedcba\n";
        else cout<<tempstr<<endl;

    }
    return 0;
}
