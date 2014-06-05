#include <iostream>
#include <string>
using namespace std;

int calfreq(string cypher,int *freqarray){
    int i,defletter=0;
    for(i=0;i<26;i++)freqarray[i]=0;

    for(i=0;i<cypher.size();i++){
        if( 64<int(cypher[i]) && int(cypher[i])<=90  ){
            if(freqarray[(int(cypher[i])-65)]==0)defletter++;
            freqarray[(int(cypher[i])-65)]++;

        } else if(96<int(cypher[i]) && int(cypher[i])<=122){          //small abcd
            if(freqarray[(int(cypher[i])-97)]==0)defletter++;
            freqarray[(int(cypher[i])-97)]++;
        }

    }
    return defletter;
}

int main()
{
    int t,i,fqarray[26],difletters;
    string fq,text,answer;
    cin>>t;
    while(t--){
        fq=text=answer="";
        cin>>fq;    cin>>text;
        difletters=calfreq(text,fqarray);

    }
    return 0;
}
