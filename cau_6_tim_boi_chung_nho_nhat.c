#include<stdio.h>

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=a;i<=a*b;i++)
    {
        if(i%a == 0 && i%b == 0)
        {
            printf("lCM(%3d,%3d) = %d",a,b,i);
            break;
        }
    }

}

