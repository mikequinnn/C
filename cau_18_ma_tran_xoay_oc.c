#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

int inputNum()
{
    int n;
    do
    {
        printf("Nhap n: ");
        scanf("%d",&n);
    }while(n<=0);
    return n;
}
void inputMaTrix(int a[][100],int n)
{
    int left,top,right,bot;
    left = 0;
    top = 0;
    right = n-1;
    bot = n-1;
    int i;
    int k = 1;
    while(1)
    {
        for(i=left;i<=right;i++)
        {
            a[top][i]=k++;
        }
        top++;
        if(k>n*n)
        {
            break;
        }
        for(i=top;i<=bot;i++)
        {
            a[i][right]=k++;
        }
        right--;
        if(k>n*n)
        {
            break;
        }
        for(i=right;i>=left;i--)
        {
            a[bot][i]=k++;
        }
        bot--;
        if(k>n*n)
        {
            break;
        }
        for(i=bot;i>=top;i--)
        {
            a[i][left]=k++;
        }
        left++;
        if(k>n*n)
        {
            break;
        }
    }
}
void outputMaTrix(int a[][100],int n)
{
    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
}
void menu()
{
    int n;
    int a[100][100];
    int flag = 0;
    int check = 0;
    int chon;
    while(1)
    {
        printf("\t\tMENU\n");
        printf("\t1.Nhap n\n");
        printf("\t2.Tinh ma tran xoay \n");
        printf("\t3.Hien thi ma tran\n");
        printf("\t4.Ket thuc!\n");
        printf("\tMoi ban chon: ");
        scanf("%d",&chon);
        switch(chon)
        {
        case 1:
            printf("Ban da chon nhap n\n");
            n = inputNum();
            printf("Ban da nhao xong");
            flag = 1;
            break;
        case 2:
            if(flag == 0)
            {
                printf("Hay nhao n truoc !\n");
                break;
            }
                printf("Ban da chon tinh ma tran xoay \n");
                inputMaTrix(a,n);
                printf("Da tinh ma tran xoay xong\n");
                check = 1;
                break;
        case 3:
            if(flag == 0)
            {
                printf("Hay nhap n truoc\n");
                break;
            }
            if(check == 0)
            {
                printf("Hay tinh ma tran truoc\n");
                break;
            }
            printf("Ban da chon hien thi ma tran xoay\n");
            outputMaTrix(a,n);
            printf("Da hien thi xong\n");
            break;
        case 4:
            printf("Ban chon ket thuc\n");
            break;
        default:
            printf("Nhap tu 1-4!!!\n");
            break;
        }
        printf("Bam nut bat ky de ve menu\n");
        getch();
        system("cls");
    }
}
int main()
{
    menu();
    return 0;
}
