#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<conio.h>
#define MAX 100

int nhapMang(int a[])
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    return n;
}
void inMang(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%3d",a[i]);
    }
    printf("\n");
}
int ghepMang(int a1[],int a2[],int a3[],int n1,int n2)
{
    int i,j,k;
    i=j=k=0;
    while(1)
    {
        if(a1[i]<a2[j])
        {
            a3[k] = a1[i];
            k++;
            i++;
        }
        else
        {
            a3[k] = a2[j];
            k++;
            j++;
        }
        if(i>= n1 || j>= n2)
        {
            break;
        }
    }
    if(i>=n1)
    {
        while(j<n2)
        {
            a3[k]=a2[j];
            k++;
            j++;
        }
    }
    if(j>=n2)
    {
        while(i<n1)
        {
            a3[k]=a1[i];
            k++;
            i++;
        }
    }
    return k;
}
void MENU()
{
    printf("\t1.Nhap 2 day so nguyen theo chieu tang dan\n");
    printf("\t2.Ghep 2 day\n");
    printf("\t3.In 3 day so\n");
    printf("\t4.Ket thuc\n");
    printf("\tVui long chon: ");
}
int main()
{
    int n1,n2,n3;
    int chon;
    int a1[MAX],a2[MAX],a3[MAX];
    while(1)
    {
        MENU();
        scanf("%d",&chon);
        system("cls");
        switch(chon)
        {
        case 1:
            {
            printf("\tBan da chon nhap 2 ma tran \n");
            printf("\tNhap mang thu 1:\n");
            printf("\tNhap so luong phan tu: ");
            n1 = nhapMang(a1);
            printf("\tNhap mang thu 2: \n");
            printf("\tNhap so luong phan tu: ");
            n2 = nhapMang(a2);
            printf("\tNhap xong 2 mang");
            printf("\tBam nut bat ky ve menu\n");
            break;
            }
        case 2:
            {
            printf("\tBan da chon ghep 2 mang\n");
            n3 = ghepMang(a1,a2,a3,n1,n2);
            printf("\tghep thanh cong\n");
            break;
            }
        case 3:
            {
            printf("\tBan chon hien thi 3 mang\n");
            printf("\tMang thu 1: \n");
            inMang(a1,n1);
            printf("\tMang thu 2: \n");
            inMang(a2,n2);
            printf("\tMang thu 3: \n");
            inMang(a3,n3);
            break;
            }
        case 4:
            {
            printf("\tBan chon ket thuc\n");
            return 0;
            }
        default:
            {
            printf("Nhap tu 0 - 4!\n");
            break;
            }
        }
        printf("\nbam nut bat ky de ve menu");
        getch();
        system("cls");
    }
}

