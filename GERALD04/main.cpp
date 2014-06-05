#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

int main()
{

    double danswer1,danswer2;
    int t,it1h,it1m,it2h,it2m,d,timediffmin;
    string t1,t2,answer1,answer2,t1h,t1m,t2h,t2m;
    cin>>t;
    while(t--){
        cin>>t1>>t2>>d;
        t1h=t1.substr(0,2); t1m=t1.substr(3,2); t2h=t2.substr(0,2); t2m=t2.substr(3,2);
        istringstream (t1h)>>it1h;  istringstream (t1m)>>it1m;  istringstream (t2h)>>it2h;  istringstream (t2m)>>it2m;
        timediffmin=((it1h-it2h)*60+(it1m-it2m));
        danswer1=(timediffmin+d); danswer1*=1.0;
        if(2*d<timediffmin){ danswer2=timediffmin; danswer2*=1.0;}
        else{
            danswer2=2*d-timediffmin; danswer2/=2; danswer2=2*d-danswer2;
        }
        printf("%0.1f %0.1f \n",danswer1,danswer2);
    }
    return 0;
}
