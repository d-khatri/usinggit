#include <iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<bitset>
using namespace std;

void numbers(int num,int len,int &x0,int &x1){

    while(num){
        if(0==(num%2)) x0++;
        else x1++;
        num=num/2;
    }
    if(x0+x1<len) x0=(len-x1);
}

int fun(int ones,int length){
    int answer=0,templen=length-1;
    for(int i=0;i<ones;i++){
        answer+=pow(2,templen);
        templen--;
    }
return answer;
}

int fun2(int ones,int length){
bitset<5> foo;
for(int i=1;i<=ones;i++) foo.set(i);
return foo.to_ulong();
}

int main()
{
    int test,x0,x1,y0,y1,length,num1,num2,temp;
    cin>>test;
    while(test--){
        x0=x1=y0=y1=temp=0;
        cin>>length; cin>>num1; cin>>num2;
        numbers(num1,length,x0,x1);
        numbers(num2,length,y0,y1);
        temp=min(x0,y1);
        temp+=min(x1,y0);
        cout<<fun(temp,length)<<endl;
        cout<<fun2(temp,length)<<endl;
    }
    return 0;
}
