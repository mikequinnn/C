#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<conio.h>
#define MAX 100

void MENU()
{
    printf("\t1. Nhap 2 ma tran\n");
    printf("\t2. Tinh tich 2 ma tran\n");
    printf("\t3. In 3 ma tran\n");
    printf("\t4. Ket thuc!\n");
    printf("\tVui long chon: ");
}
int nhapSo()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n<0)
            printf("\t\aSo phai lon hon 0! Nhap lai: ");
        else
            return n;
    }
}
void nhapMaTran(int m[][MAX],int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&m[i][j]);
        }
    }
}
void inMaTran(int m[][MAX],int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%3d",m[i][j]);
        }
        printf("\n");
    }
}
void tichMaTran(int m1[][MAX],int m2[][MAX],int m_mul[][MAX],int r1,int n,int c2)
{
    int total;
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            total = 0;
            int k;
            for(k=0;k<n;k++)
            {
                total += m1[i][k] * m2[k][j];
            }
            m_mul[i][j] = total;
        }
    }
}
int main()
{
    int chon;
    int m1[MAX][MAX],m2[MAX][MAX],m_mul[MAX][MAX];
    int flag1 = 0;
    int flag2 = 0;
    int r1,n,c2,tmp;
    while(1)
    {
        MENU();
        scanf("%d",&chon);
        switch(chon)
        {
        case 1:
            {
                printf("\tNhap so dong, so cot ma tran thu nhat: ");
                r1 = nhapSo();
                n = nhapSo();
                printf("\tNhap ma tran 1: \n");
                nhapMaTran(m1,r1,n);
                printf("\tNhap so dong, so cot ma tran thu hai: ");
                do
                {
                    tmp = nhapSo();
                    if(tmp != n)
                        printf("\tSo dong phai bang so cot ma tran truoc, nhap lai");
                }
                while(tmp != n);
                c2 = nhapSo();
                printf("\tNhap ma tran 2: ");
                nhapMaTran(m2,n,c2);
                printf("\tBan da nhap xong 2 ma tran\n");
                flag1 = 1;//dùng để truyền trạng thôi giữa câu lệnh
                break;
            }
        case 2:
            {
                if (flag1==0)
                    {
                        printf("\t\aChua nhap ma tran!!!\n");
                        break;
                    }
                    tichMaTran(m1,m2,m_mul,r1,n,c2);
                    printf("\tDa tinh xong!!\n");
                    flag2 = 1;
                    break;
            }
        case 3:
            {
                if(flag1==0)
                {
                    printf("\t\aChua nhap ma tran !!!\n");
                    break;
                }
                if(flag2==0)
                {
                    printf("\t\aChua tinh tich!!\n");
                    break;
                }
                printf("\tBa ma tran la: \n");
                inMaTran(m1,r1,n);
                printf("\n");
                inMaTran(m2,n,c2);
                printf("\n");
                inMaTran(m_mul,r1,c2);
                printf("\n");
                break;
            }
        case 4:
            {
                printf("\tBan da chon thoat \n");
                return 0;
            }
        }
        printf("Bam nut bat ky ve menu!");
        getch();
        system("cls");
    }
}

