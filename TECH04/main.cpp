#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t,i,maxlen,arry1[26],arry2[26],f1;
    string a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        f1=0;
        for(i=0;i<26;i++){arry1[i]=0;arry2[i]=0;}
        if(a.length()!=b.length()){cout<<"NO\n";}
        else{
            for(i=0;i<a.length();i++){
                arry1[(a[i]-97)]++;
            }
            for(i=0;i<b.length();i++){
                arry2[(b[i]-97)]++;
            }
            for(i=0;i<26;i++){
                if(arry1[i]!=arry2[i]){cout<<"NO\n";f1=1;break;}
            }
            if(f1==0)cout<<"YES\n";
        }
    }

    return 0;
}
