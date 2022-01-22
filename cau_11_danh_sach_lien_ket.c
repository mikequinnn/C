#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

typedef struct
{
    char ho_ten[25];
    int tuoi;
    float diem;
}sinhvien;
typedef struct node
{
    sinhvien data;
    struct node* next;
}node;

node* first = NULL;
sinhvien nhapData()
{
    sinhvien sv;
    fflush(stdin);
    printf("\nNhap ho ten sinh vien:");
    gets(sv.ho_ten);
    printf("\nNhap tuoi:");
    scanf("%d",&sv.tuoi);
    printf("\nNhap diem:");
    scanf("%f",&sv.diem);
    return sv;
}
node* taoNode()
{
    node* pnode = (node*)malloc(sizeof(node));
    pnode->data = nhapData();
    pnode->next = NULL;
    return pnode;
}
void themNodeDauTien()
{
    node* pnode = taoNode();
    first = pnode;
}
void themNodeTiepTheo()
{
    if(first==NULL)
    {
        themNodeDauTien();
    }
    else
    {
        node* find;
        for(find = first; find->next != NULL; find = find->next);//them dau chấm phẩy để vòng for chạy đến node cuối cùng
        node* pnode = taoNode();
        find->next = pnode;
    }
}
void hienThiMotSinhVien(sinhvien sv)
{
    printf("%25s%8d%8.2f\n",sv.ho_ten,sv.tuoi,sv.diem);
}
void hienThiDanhSach()
{
    printf("\tDanh sach sinh vien\n");
    printf("\t%4s%25s%8s%8s\n","STT","HO TEN","TUOI","DIEM");
    int stt = 1;
    for(node* i = first;i != NULL;i = i->next)
    {
        printf("\t%4d",stt++);
        hienThiMotSinhVien(i->data);
    }
}
node* timNodeTheoTen(char* hoten)
{
    node* i = NULL;
    for(i = first; i != NULL; i = i->next)
    {
        if(strcmp(i->data.ho_ten,hoten)==0)
        {
            return i;
        }
    }
    return NULL;
}
void chenSV(char* tencanchen)
{
    if(timNodeTheoTen(tencanchen)==NULL)
    {
        printf("Khong co ten %s can chen",tencanchen);
    }
    else
    {
        node* tmp = timNodeTheoTen(tencanchen);
        node* pnode = taoNode();
        pnode->next = tmp->next;
        tmp->next = pnode;
    }
}
void xoaSV(char* tencanxoa)
{
    if(timNodeTheoTen(tencanxoa)==NULL)
    {
        printf("\nKhong co ten %s can xoa",tencanxoa);
    }
    else
    {
        node* del = timNodeTheoTen(tencanxoa);
        if(del==first)
        {
            first = del->next;
            free(del);
        }
        else
        {
            node* tmp;
            for(tmp=first;tmp->next != del;tmp = tmp->next)
            tmp->next = del->next;
            free(del);
        }
    }
}
void suaSV(char* tencansua)
{
    if(timNodeTheoTen(tencansua)==NULL)
    {
        printf("\nKhong co ten %s can sua",tencansua);
    }
    else
    {
        node* tmp = timNodeTheoTen(tencansua);
        tmp->data = nhapData();
    }
}

void MENU()
{
    printf("\tMENU\n");
    printf("\t1.Tao danh sach sinh vien\n");
    printf("\t2.Hien thi danh sach sinh vien\n");
    printf("\t3.Chen sinh vien\n");
    printf("\t4.Xoa sinh vien\n");
    printf("\t5.Sua sinh vien\n");
    printf("\t6.Xoa danh sach va thoat chuong trinh\n");
    printf("Moi ban chon: ");
}
void taoDanhSachSv()
{
    for(int i = 1 ;; i++)
    {
        printf("\nNhap sinh vien thu %d",i);
        themNodeTiepTheo();
        printf("\nNhap tiep? y or n ? ");
        fflush(stdin);
        char c = getch();
        if(c=='n' || c=='N')
        {
            break;
        }
    }
}


int main()
{
    char ten[30];
    int chon;
    while(1)
    {
        MENU();
        scanf("%d",&chon);
        switch(chon)
        {
        case 1:
            printf("\nBan da chon tao danh sach sinh vien\n");
            taoDanhSachSv();
            break;
        case 2:
            printf("\nBan da chon hien thi danh sach sinh vien\n");
            hienThiDanhSach();
            break;
        case 3:
            printf("\nBan da chon chen sinh vien\nNhap sinh vien can chen\n");
            fflush(stdin);
            gets(ten);
            chenSV(ten);
            break;
        case 4:
            printf("\nBan da chon xoa sinh vien\nNhap sinh vien can xoa\n");
            fflush(stdin);
            gets(ten);
            xoaSV(ten);
            break;
        case 5:
            printf("\nBan da chon sua sinh vien\nNhap sinh vien can sua\n");
            fflush(stdin);
            gets(ten);
            suaSV(ten);
            break;
        case 6:
            printf("\nBan da chon thoat chuong trinh\n");
            exit(0);
        default:
            printf("Nhap 1-6 !!\n");
            break;
        }
        printf("Bam nut bat ky de ve menu\n");
        getch();
        system("cls");
    }
}


