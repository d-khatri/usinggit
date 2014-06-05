#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>
using namespace std;

int calfreq(char* giventext,vector< pair<int,char> > &vop){
    int i,defletter=0;

    for(i=0;;i++){
        if( 64<int(giventext[i]) && int(giventext[i])<=90  ){
            if(vop[((int(giventext[i]))-65)].first==0)defletter++;
            vop[(int(giventext[i])-65)].first++;

        } else if(96<int(giventext[i]) && int(giventext[i])<=122){          //small abcd
            if(vop[(int(giventext[i])-97)].first==0)defletter++;
            vop[(int(giventext[i])-97)].first++;
        }
        if(giventext[i]==0)break;

    }
    return defletter;
}

int main()
{
    int t,i,difvalue,init,flag,store,j;
    string frq,answer;
    char* text;
    text=new char[150000];
    cin>>t;
    while(t--){
        init=97; difvalue=0;
        vector< pair<int,char> >myvec;
        for(i=0;i<26;i++,init++){
            myvec.push_back( make_pair(0,char(init)) );
        }
        cin>>frq;
        fseek(stdin,0,SEEK_END);
        gets(text);
        difvalue=calfreq(text,myvec);
        sort(myvec.begin(),myvec.end());

     /*   cout<<"second\tfirst\n";
        for(i=0;i<26;i++)
        cout<<myvec[i].second<<"\t"<<myvec[i].first<<endl;*/

        for(i=0;i<26;i++){
            myvec[i].first=frq[i];
        }

        /*cout<<endl<<endl<<endl<<endl;
        cout<<"second\tfirst(in char)\n";
        for(i=0;i<26;i++)
        cout<<myvec[i].second<<"\t"<<char(myvec[i].first)<<endl;

        cout<<endl<<endl<<endl<<endl;
        */
        for(i=0;;i++){

            flag=-1; store=-1;

            if(text[i]==0)break;

            if( 65<=int(text[i]) && int(text[i])<=90 ) { flag=1;text[i]+=32;}

            if( 97<=int(text[i]) && int(text[i])<=122 ){
                //checkinfirst of myvec and replace corresponding value
                for(j=0;j<26;j++){
                    if( (text[i])==myvec[j].second )store=j;
                }
                if(store!=-1){
                    if(flag!=1) text[i]=char(myvec[store].first);
                    else text[i]=char((myvec[store].first)-32);
                }
            }
        }

    cout<<text<<endl;

    }
    return 0;
}
