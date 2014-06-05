#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>

using namespace std;
#define SIZE 65536

int main()
{
    char buffer[SIZE],m;
    unsigned long n, k, ti, d;
    int c, j;
    ti=d = 0;

    scanf("%lu %lu\n", &n, &k);
    m=getchar();
    while ( (c=fread(buffer, 1, SIZE, stdin)) > 0){
        cout<<"c is "<<c<<endl;

        for (j=0;j<c;j++){

            if (buffer[j] == '\n'){
                if (ti % k == 0) d++;
                ti = 0;
            } else if(buffer[j]!=' '){
                ti = ti*10 + (buffer[j] - '0');
            }
        }
    cout<<"for loop done\n";
    }

    printf("answer %lu\n", d);

    return 0;

}
