#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long int t,r,x1,y1,x2,y2,x3,y3,d1,d2,d3;
    cin>>t;
    while(t--){
        cin>>r;
        r*=r;
        cin>>x1; cin>>y1; cin>>x2; cin>>y2; cin>>x3; cin>>y3;
        d1=(pow((x1-x2),2)+pow((y1-y2),2)); d2=(pow((x1-x3),2)+pow((y1-y3),2)); d3=(pow((x3-x2),2)+pow((y3-y2),2));
        if( (d1<=r && d2<=r)  || (d1<=r && d3<=r) || (d2<=r && d3<=r) ) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}
