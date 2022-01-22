#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void input(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void output(int a[],int n)
{
    int max,min;
    max = min = a[0];
    for(int i=0; i<n; i++)
    {
        if(max < a[i])
        {
            max = a[i];
        }
        if(min > a[i])
        {
            min = a[i];
        }
    }
    printf("value max: %d, max index:",max);
    for(int i=0; i<n; i++)
    {
        if(max == a[i])
        {
            printf("%3d",i);
        }
    }
    printf("\n");

    printf("value min: %d, min index:",min);
    for(int i=0;i<n;i++)
    {
        if(min == a[i])
        {
            printf("%3d",i);
        }
    }
}

int main()
{
    int a[MAX];
    int n;
    printf("Nhap n:");
    scanf("%d",&n);
    input(a,n);
    output(a,n);

}

