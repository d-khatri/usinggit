#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

long long int gcdfun(long long int u, long long int v)
{
  int shift;
  if (u == 0) return v;
  if (v == 0) return u;
  for (shift = 0; ((u | v) & 1) == 0; ++shift) {
         u >>= 1;
         v >>= 1;
  }
   while ((u & 1) == 0)
    u >>= 1;
  do {
       while ((v & 1) == 0)  /* Loop X */
           v >>= 1;

       if (u > v) {
         long long int t = v; v = u; u = t;}
       v = v - u;
     } while (v != 0);
  return u << shift;
}

int main()
{
    long long int t,n,ms,mr,i,j,siz,rip,ans,ar,gcd;
    freopen("input.txt","r",stdin);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n>>ms>>mr;
        for(i=0;i<n;i++){
            cin>>siz>>rip;
            if(siz>ms || rip>mr)ans++;
        }
        cin>>ar;
        gcd=gcdfun(ans,ar);
        ans/=gcd;ar/=gcd;
        cout<<ans<<"/"<<ar<<endl;
    }
    return 0;
}
