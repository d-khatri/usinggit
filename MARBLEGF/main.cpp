#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <vector>
#include <stdio.h>
using namespace std;


int main()
{
    long long int n,q,i,temp,first,last,answer,j;
    vector<long long int>myvec;
    char casevalue;
    scanf("%lld",&n);
    scanf("%lld",&q);
    for(i=0;i<n;i++){
        scanf("%lld",&temp);
        myvec.push_back(temp);
    }

    for(j=0;j<q;j++){
            cin>>casevalue>>first>>last;
            //cout<<casevalue<<a<<b<<endl;
            answer=0;
            //cout<<"casevalue and takeinput first last are " <<casevalue<<"\t"<<takeinput<<"\t"<<first<<"\t"<<last<<endl;
            switch(casevalue){
                case 'S':
                    for(i=first;i<=last;i++){
                        answer+=myvec[i];
                    }
                    printf("%lld\n",answer);
                    break;

                case 'G':
                    myvec[first]+=last;
                    break;

                case 'T':
                    myvec[first]-=last;
                    break;

            }
    }

    return 0;
}
