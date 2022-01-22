#include<stdio.h>
#include<stdlib.h>

void nhapMang(int a[100],int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void inMang(int a[100],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%3d",a[i]);
    }
}
void sapXepTangDan(int a[100],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int main()
{
    int a[100];
    int n;
    scanf("%d",&n);
    nhapMang(a,n);
    sapXepTangDan(a,n);
    inMang(a,n);

}


