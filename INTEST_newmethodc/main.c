#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 65536

int main()
{
    char *buffer;
    unsigned long n, k, temp, counter;
    int c, j;
    temp=counter= 0;

    scanf("%lu %lu\n", &n, &k);
    buffer=(char*)malloc(10*n);
    c=fread(buffer, 1, 10*n, stdin);

    for (j=0;j<c;j++){
        if (buffer[j] == '\n'|| buffer[j] == ' '){
            if (temp % k == 0) counter++;
            temp = 0;
        } else {
            temp = temp*10 + (buffer[j] - '0');
        }
    }

    printf("%lu\n", counter);

    return 0;

}
