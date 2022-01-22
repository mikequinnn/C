#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

FILE* f;
char* filepath = "MA_TRAN.C";
void taoTep(int a[][100],int b[][100],int* n,int*m)
{
    f = fopen(filepath,"w");
    printf("Nhap kich thuoc 2 ma tran: ");
    scanf("%d%d",n,m);
    fprintf(f,"%d %d\n",*n,*m);
    fprintf(f,"Ma tran A\n");
    printf("Ma tran A: \n");
    //nhap tren ma hinh
    for(int i=0;i<*n;i++)
    {
        for(int j=0;j<*m;j++)
        {
            printf("a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    //in tren file
    for(int i=0;i<*n;i++)
    {
        for(int j=0;j<*m;j++)
        {
            fprintf(f,"%d",a[i][j]);
        }
        fprintf(f,"\n");
    }
    fprintf(f,"Ma tran B\n");
    printf("Ma tran B: \n");
    for(int i=0;i<*n;i++)
    {
        for(int j=0;j<*m;j++)
        {
            printf("b[%d][%d]=",i,j);
            scanf("%d",&b[i][j]);
        }
    }
    for(int i=0;i<*n;i++)
    {
        for(int j=0;j<*m;j++)
        {
            fprintf(f,"%d",b[i][j]);
        }
        fprintf(f,"\n");
    }
    fclose(f);
}
void docMaTran(int a[][100],int b[][100])
{
   int i,j;
   int m,n;
   char chon;
   f = fopen(filepath,"r");
   fscanf(f,"%d%d",&n,&m);
   printf("Ma Tran A: \n");
   for(i=0;i<n;i++)
   {
       for(j=0;j<m;j++)
       {
           fscanf(f,"%d",&a[i][j]);
       }
   }
   for(i=0;i<n;i++)
   {
       for(j=0;j<m;j++)
       {
           printf("%3d",a[i][j]);
       }
       printf("\n");
   }
   printf("Ma Tran B: \n");
   for(i=0;i<n;i++)
   {
       for(j=0;j<m;j++)
       {
           fscanf(f,"%d",&b[i][j]);
       }
   }
   for(i=0;i<n;i++)
   {
       for(j=0;j<m;j++)
       {
           printf("%3d",b[i][j]);
       }
       printf("\n");
   }
   printf("Bam nut bat ky de ve menu \n");
   fclose(f);
}
void maTranC(int a[][100],int b[][100],int c[][100],int n,int m)
{
    f = fopen(filepath,"a");
    int i,j;
    printf("Ma Tran C: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%3d",c[i][j]);
        }
        printf("\n");
    }
     fprintf(f,"Ma Tran C: \n");
     for(i=0;i<n;i++)
     {
        for(j=0;j<m;j++)
        {
            fprintf(f,"%3d",c[i][j]);
        }
        fprintf(f,"\n");
     }
     printf("Ma Tran C da duoc them cuoi file.\n");
     fclose(f);

}
void MENU()
{
    printf("\t1. Doc du lieu tu file\n");
    printf("\t2. Ma tran tong\n");
    printf("\t3. Thoat\n");
    printf("\t Moi chon: ");
}
int main()
{
    int a[100][100],b[100][100],c[100][100],n,m,chon;
    taoTep(a,b,&n,&m);
    while(1)
    {
        getch();
        system("cls");
        MENU();
        scanf("%d",&chon);
        switch(chon)
        {
        case 1:
            printf("ban chon doc du lieu tu file\n");
            docMaTran(a,b);
            break;
        case 2:
            printf("ba chon ma tran tong\n");
            maTranC(a,b,c,n,m);
            printf("bam nut bat ky de ve menu\n");
            break;
        case 4:
            return 0;
        default:
            printf("nhap lai\n");
        }
    }
}

