#include <iostream>
#include <cstdio>
#define gc getchar_unlocked
using namespace std;

inline int scan( ) {

int n=0;

int ch=getchar_unlocked();

while( ch <48 )ch=getchar_unlocked();

while( ch >47 )

n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();

return n;

}

int main()
{
    int n;
    n=scan();
    cout<<n<<endl
    return 0;
}
