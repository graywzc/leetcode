#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};

    memset(a,1,sizeof(int)*10);

    for(int i = 0; i < 10; i++)
        printf("%d\n",a[i]);

    int b = 1;
    b = 1+b<<8; 
    printf("b=%d\n",b);
}

