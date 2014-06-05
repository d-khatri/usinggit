#include <iostream>
#include<cstdio>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,answer=0;
		scanf("%d",&n);

		while(n)
		{
			answer=answer+ n/5;
			n/=5;

		}

		printf("%d\n",answer);
	}
}
