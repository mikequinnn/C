#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100

void nhapMaTran(int a[][MAX], int dong, int cot)
{
    for(int i=0; i<dong; i++)
    {
        for(int j=0; j<cot; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void xuatMaTran(int a[][MAX], int dong, int cot)
{
    for(int i=0; i<dong; i++)
    {
        for(int j=0; j<cot; j++)
        {
            printf("%3d",a[i][j]);
        }
    printf("\n");
    }
}

int maxMaTran(int a[][MAX], int dong, int cot)
{
    int max = a[0][0];
    for(int i=0; i<dong; i++)
    {
        for(int j=0; j<cot; j++)
        {
            if(max < a[i][j])
            {
                max = a[i][j];
            }
        }
    }
    return max;
}
int minMaTran(int a[][MAX], int dong, int cot)
{
    int min = a[0][0];
    for(int i=0; i<dong; i++)
    {
        for(int j=0; j<cot; j++)
        {
            if(min > a[i][j])
            {
                min = a[i][j];
            }
        }
    }
    return min;
}
int laSNT(int n)
{
    if(n<0)
    {
        return 0;
    }
    for(int i=2; i<=sqrt(n); i++)
    {
        if(n%2 == 0)
        {
            return 0;
        }
    }
    return 1;
}
int tongSNT(int a[][MAX],int dong,int cot)
{
    int sum = 0;
    for(int i=0; i<dong; i++)
    {
        for(int j=0; j<cot; j++)
        {
            if(laSNT(a[i][j]))
            {
            sum += a[i][j];
            }
        }
    }
    return sum;
}


int main()
{
    int a[MAX][MAX];
    int dong, cot;
    printf("Nhap dong:");
    scanf("%d",&dong);
    printf("Nhap cot:");
    scanf("%d",&cot);
    nhapMaTran(a,dong,cot);
    printf("Hien thi ma tran\n");
    xuatMaTran(a,dong,cot);
    printf("Value max: %2d\nValue min: %2d\n",maxMaTran(a,dong,cot),minMaTran(a,dong,cot));
    printf("Tong SNT la: %3d",tongSNT(a,dong,cot));



}

