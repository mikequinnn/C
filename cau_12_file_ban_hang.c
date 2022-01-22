#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct
{
    char ten_hang[25];
    int don_gia;
    int so_luong;
    int thanh_tien;
}hanghoa;

FILE* f;
char* filepath = "SO_LIEU.C";

void taoHangHoaLenFile(int* n)
{
    hanghoa tmp;
    char chon_tiep;
    *n = 0;
    f = fopen(filepath,"wb");
    while(1)
    {
        (*n)++;
        printf("\t\tTen hang: ");
        fflush(stdin);
        gets(tmp.ten_hang);
        printf("\t\tDon gia: ");
        scanf("%d",&tmp.don_gia);
        printf("\t\tSo luong: ");
        scanf("%d",&tmp.so_luong);
        tmp.thanh_tien = tmp.don_gia * tmp.so_luong;

        fwrite(&tmp,sizeof(hanghoa),1,f);
        printf("\tNhap tiep? y/n ");
        fflush(stdin);
        chon_tiep = getchar();
        if(chon_tiep == 'n' || chon_tiep == 'N')
        {
            break;
        }
    }
    fclose(f);
}
void boSungHangHoaLenFile(int* n)
{
    hanghoa tmp;
    (*n)++;
    printf("\t\tTen hang: ");
    fflush(stdin);
    gets(tmp.ten_hang);
    printf("\t\tDon gia: ");
    scanf("%d",&tmp.don_gia);
    printf("\t\tSo luong: ");
    scanf("%d",&tmp.so_luong);
    tmp.thanh_tien = tmp.don_gia * tmp.so_luong;

    f = fopen(filepath,"ab");
    fwrite(&tmp,sizeof(hanghoa),1,f);
    fclose(f);
}
void hienThiHangHoaLenFile(int n)
{
    hanghoa tmp;
    int i = 1;
    printf("\t\tDANH SACH HANG HOA\n");
    printf("\t|%3s|%25s|%8s|%12s|%14s|\n","STT","TEN HANG","DON GIA","SO LUONG","THANH TIEN");
    printf("\t|---|-------------------------|--------|------------|--------------|\n");
    f = fopen(filepath,"rb");
    for(i=1;i<=n;i++)
    {
        fread(&tmp,sizeof(hanghoa),1,f);
        printf("\t|%3d|%25s|%8d|%12d|%14d|\n",i,tmp.ten_hang,tmp.don_gia,tmp.so_luong,tmp.thanh_tien);
    }
    fclose(f);
}
void MENU()
{
    printf("\t1. Nhap so lieu ban hang len tep\n");
    printf("\t2. Ghi bo sung so lieu ban hang vao cuoi tep SO_LIEU.c\n");
    printf("\t3. Hien thi noi dung tep SO_LIEU.C\n");
    printf("\t4. Ket thuc\n");
    printf("\tVui long chon: ");
}
int main()
{
    int chon;
    char chon_tiep;
    int n = 0;
    while(1)
    {
        MENU();
        scanf("%d",&chon);
        switch(chon)
        {
        case 1:
            printf("\tBan da chon nhap so lieu ban hang len tep\n");
            taoHangHoaLenFile(&n);
            break;
        case 2:
            printf("\tBan da chon ghi bo sung so lieu hang hoa vao cuoi tep SO_LIEU.C\n");
            while(1)
            {
                boSungHangHoaLenFile(&n);
                printf("\tNhap tiep? y/n ");
                fflush(stdin);
                chon_tiep = getchar();
                if(chon_tiep == 'n' || chon_tiep == 'N')
                    break;
            }
                break;

        case 3:
            printf("\tBan da chon hien thi noi dung tep SO_LIEU.C\n");
            hienThiHangHoaLenFile(n);
            break;
        case 4:
            printf("Ban da chon ket thuc\n");
            exit(0);
        default:
            printf("Nhap tu 1-4!!!\n");
            break;
        }
        printf("Bam nut bat ki de ve menu\n");
        getch();
        system("cls");
    }
    return 0;
}


