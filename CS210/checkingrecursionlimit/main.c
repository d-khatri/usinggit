#include<stdio.h>
long long int fib(int n)
{
   if (n <= 1)
      return n;
   return fib(n-1) + fib(n-2);
}

int main ()
{
  int n = 60;
  printf("%lld", fib(n));
  getchar();
  return 0;
}
