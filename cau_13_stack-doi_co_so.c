#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node { // dinh nghia node
    int data;
    struct node* pnext;
}node;

node* top = NULL;

node* setNode(int value) { // ham tao node
    node* pnode = (node*)malloc(sizeof(node));
    pnode->data = value;
    pnode->pnext = NULL;
    return pnode;
}

int isEmpty() { // ham kiem tra xem danh sach day hay rong
    return top == NULL;
}

void


(int value) { // ham them gia tri vao ngan xep
    node* pnode = setNode(value);
    if(isEmpty()) {
        top = pnode;
    }
    else{
        pnode->pnext = top;
        top = pnode;
    }
}

int pop() { // ham xoa gia tri dau tien cua ngan xep
    if(isEmpty()) {
        exit(1);
    }
    else {
        node* del = top;
        int value = top->data;
        top = top->pnext;
        free(del);
        return value;
    }
}

char compareChar(int n) { // ham chuyen ki tu
    if(n < 10) {
        return n + '0';
    }
    else {
        n -= 10;
        return n + 'A';
    }
}

void show() { // ham hien thi ki tu
    while(!isEmpty()) {
        printf("%c", compareChar(pop()));
    }
}

void compareNumber(int n, int heso) { // ham chuyen doi so thap phan
    while(n>0) {
        push(n%heso);
        n = n/heso;
    }
    show();
}

int menu() { // menu
    int n, key;
    while(1) {
        printf("Nhap so thap phan: ");
        scanf("%d", &n);
        printf("1: Co so 2\n");
        printf("2. Co so 8\n");
        printf("3. Co so 16\n");
        printf("4. Ket thuc\n");
        printf("Chon tu 1->4: ");
        scanf("%d", &key);
        switch(key) {
            case 1:
                compareNumber(n, 2);
                printf("\n");
                break;
            case 2:
                compareNumber(n, 8);
                printf("\n");
                break;
            case 3:
                compareNumber(n, 16);
                printf("\n");
                break;
            case 4:
                printf("Ket thuc\n");
                exit(1);
            default:
                printf("Nhap tu 1->4!\n");
        }
        printf("An phim bat ky de quay lai menu!\n");
        getch();
        system("cls");
    }
}

int main() {
    menu();
}
