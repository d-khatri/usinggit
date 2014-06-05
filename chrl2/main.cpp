#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
   int c,h,e,ans,i;
   c=h=e=ans=0;
   string s;
   cin>>s;
   for(i=0;i<s.length();i++){
       if(s[i]=='C')c=1;
       if(c==1 && s[i]=='H' && h==0)h++;
       if(h==1 && s[i]=='E' && e==0)e++;
       if(e==1 && s[i]=='F'){ans++;c=h=e=0;}
   }
   cout<<ans<<endl;
   return 0;
}
