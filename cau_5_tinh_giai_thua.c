#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int n,gt = 1;
    printf("Nhap n = ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        gt *=i;
    }
    printf("%d! = %d",n,gt);
    return 0;
}

