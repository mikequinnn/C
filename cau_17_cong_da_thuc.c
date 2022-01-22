#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<conio.h>

void nhapHeSoDaThuc(int a[][100],int d,int c)
{
    for(int i = 0; i < c; i++)
    {
        scanf("%d",&a[d][i]);
    }
}
void tinhTongDaThuc(int a[][100],int c)
{
    for(int i = 0; i < c; i++)
    {
        a[2][i] = a[0][i] + a[1][i];
    }
}
void inHeSoDaThuc(int a[][100],int d,int c)
{
    printf("\t");
    for(int i = 0; i < c; i++)
    {
        if(a[d][i] != 0)
        {
            printf("%4d",a[d][i]);
        }
        else
        {
            printf("%4s","");
        }
    }
    printf("\n");
}
int tinhDaThuc(int a[][100],int c,float x)
{
    float sum = 0;
    for(int i = 0; i < c; i++)
    {
        sum = sum + a[2][i] * pow(x,i);
    }
    return sum;
}
int main()
{
    int a[2][100] = {0};
    int c1,c2;
    float x;
    while(1)
    {
        printf("\t1.Nhap he so cua 2 da thuc\n");
        printf("\t2.Tinh he so cua da thuc\n");
        printf("\t3.In he so cua 3 da thuc\n");
        printf("\t4.In gia tri cua 3 da thuc\n");
        printf("\t5.Ket thuc\n");
        printf("\tMoi ban chon: ");
        int chon;
        scanf("%d",&chon);
        system("cls");
        switch(chon)
        {
        case 1:
            printf("Ban da chon nhap he so cua 2 da thuc \n");
            printf("Nhap bac cua da thuc 1: ");
            scanf("%d",&c1);
            printf("Nhap he so cua da thuc 1: ");
            nhapHeSoDaThuc(a,0,c1);
            printf("Nhap bac cua da thuc 2: ");
            scanf("%d",&c2);
            printf("Nhap he so cua da thuc 2: ");
            nhapHeSoDaThuc(a,1,c2);
            break;
        case 2:
            printf("Tinh he so da thuc\n");
            tinhTongDaThuc(a,c1>c2?c1:c2);
            break;
        case 3:
            printf("In he so cua 3 da thuc\n");
            inHeSoDaThuc(a,0,c1);
            inHeSoDaThuc(a,1,c2);
            inHeSoDaThuc(a,2,c1>c2?c1:c2);
            break;
        case 4:
            printf("In gia tri cua 3 da thuc ");
            printf("Nhap x: ");
            scanf("%d",&x);
            int c3 = c1>c2?c1:c2;
            printf("Gia tri cua da thuc la: %d\n",tinhDaThuc(a,c3,x));
            break;
        case 5:
            printf("Ket thuc\n");
            return 0;
        }
        printf("Bam nut bat ky de ve menu");
        getch();
        system("cls");
    }
}

