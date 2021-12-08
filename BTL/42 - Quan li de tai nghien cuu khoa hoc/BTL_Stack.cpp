#include <bits/stdc++.h>
using namespace std;
typedef struct NODEDeTai
{
    int soLuong;
    char tenDeTai[50], SinhVien[30], maDeTai[30];
} detai;
typedef struct STACKDeTai
{
    NODEDeTai data;
    STACKDeTai *next;
} StackDT;

void initDeTai(StackDT *&top)
{
    top = NULL;
};

// CHUONG TRINH QUAN LY DETAI
void nhapDT(detai &DT)
{

    cout<<"\nNhap ten De Tai: ";
    fflush(stdin);
    gets(*&DT.tenDeTai);
    cout<<"Nhap ma De Tai: ";
    fflush(stdin);
    cin>>*&DT.maDeTai;
    cout<<"Nhap ten Sinh Vien lam De Tai: ";
    fflush(stdin);
    gets(*&DT.SinhVien);
    cout<<"Nhap so luong: ";
    cin>>*&DT.soLuong;
}

StackDT *createNode(detai DT)
{
    StackDT *new_node;
    new_node = (StackDT *) malloc(sizeof(StackDT));
    new_node->data=DT;
    new_node->next=NULL;
    return new_node;
}

bool isEmptyS(StackDT *top)
{
    return !top;
}

//nhap
void pushDT(StackDT *&top, StackDT *createTop)
{

    if (top == NULL)
    {
        top = createTop;

    }
    else
    {
        createTop->next = top;
        top = createTop;
    }
}

void popDT(StackDT *&top)
{
    if (top == NULL)
        printf("\nKhong co gia tri trong danh detai");
    else
    {
        StackDT *q = top;
        top = top->next;
        free(q);
    }
}

//nhap
void nhapDSDT(StackDT *&top, detai &DT)
{
    int n;

    do
    {
        cout<<"\nNhap vao so De Tai: ";
        cin>>n;
    }
    while (n <= 0);
    for (int i = 0; i < n; i++)
    {
        cout<<"\nNhap thong tin De Tai: "<<i+1;
        nhapDT(DT);
        pushDT(top, createNode(DT));
    }
}

//xuat
void xuatDetai(StackDT *top)
{
    StackDT *p;
    p = top;

        cout << setw(30) << left << "\nTen De Tai";
        cout << setw(12) << left << "Ma De Tai";
        cout << setw(30) << left << "Sinh Vien lam";
        cout << setw(8) << right << "So luong" << endl;
    while (p != NULL)
    {
        cout << setw(30) << left << p->data.tenDeTai;
        cout << setw(12) << left << p->data.maDeTai;
        cout << setw(30) << left << p->data.SinhVien;
        cout << setw(8) << right << p->data.soLuong << endl;
        p = p->next;
    }
}

void xuat5(StackDT *top)
{
    StackDT *p;
    p = top;
    cout<<"\nDanh sach De Tai tren 5 cau hoi: ";
        cout << setw(30) << left << "\nTen De Tai";
        cout << setw(12) << left << "Ma De Tai";
        cout << setw(30) << left << "Sinh Vien lam";
        cout << setw(8) << right << "So luong" << endl;
    while (p != NULL)
    {
        if (p->data.soLuong > 5)
        {
        cout << setw(30) << left << p->data.tenDeTai;
        cout << setw(12) << left << p->data.maDeTai;
        cout << setw(30) << left << p->data.SinhVien;
        cout << setw(8) << right << p->data.soLuong << endl;

        }
        p = p->next;
    }
}

//tim kiem
void searchMa(StackDT *top)
{
    char ma[50];
    cout<<"\nNhap ma De Tai can tim: ";
    fflush(stdin);
    cin>>ma;
    StackDT *p = top;
        cout << setw(30) << left << "\nTen De Tai";
        cout << setw(12) << left << "Ma De Tai";
        cout << setw(30) << left << "Sinh Vien lam";
        cout << setw(8) << right << "So luong" << endl;
    while (p != NULL)
    {
        if (strcmp(ma, p->data.maDeTai) == 0)
        {
        cout << setw(30) << left << p->data.tenDeTai;
        cout << setw(12) << left << p->data.maDeTai;
        cout << setw(30) << left << p->data.SinhVien;
        cout << setw(8) << right << p->data.soLuong << endl;
        p = p->next;
    }

}

//dem
void thongKeSL(StackDT *top)
{
    StackDT *p = top;
    int i = 0, n;
    printf("\nNhap so luong sach can kiem tra: ");
    scanf("%d", &n);

    while (p != NULL)
    {
        if (p->data.soLuong > n)
            i++;
        p = p->next;
    }
    if (i == 0)
    {
        printf("Khong co cuon sach nao co so luong tren %d.", n);
    }
    else
    {
        printf("So quyen sach co so luong lon hon %d la: %d", n, i);
    }
}

void delRear(StackDT *&top)
{
    detai X;
    StackDT  *q;
    initDeTai(q);
    if (isEmptyS(top))
        printf("\nKhong ton tai gia tri trong danh detai");
    else if (top->next == NULL)
    {
        top = NULL;
    }
    else
    {
        while (top != NULL)
        {
            X=top->data;
            pushS(q, createNode(X));
            popS(top);
        }
        popS(q);
        while (q != NULL)
        {
            X=q->data;
            pushS(top, createNode(X));
            popS(q);
        }
    }
}

int sizeS(StackDT *top)
{
    int i = 0;
    StackDT *p = top;
    while (p != NULL)
    {
        i++;
        p = p->next;
    }
    return i;
}

void delMid(StackDT *&top)
{
    StackDT *q;
    detai S;
    initDeTai(q);
    int k;
    do
    {
        printf("\nNhap vi tri can xoa: ");
        scanf("%d", &k);
    }
    while (k < 1 || k > sizeS(top));
    if (top == NULL)
    {
        printf("\nDanh detai khong co gia tri");
    }
    else if (top->next == NULL)
    {
        top = NULL;
        free(top);
    }
    else
    {
        int z = 0;
        while (top!=NULL)
        {
            z++;
            S = top->data;
            pushS(q, createNode(S));
            if (z == k)
            {
                popS(q);
            }
            popS(top);

        }
        while (q != NULL)
        {
            S=q->data;
            pushS(top, createNode(S));
            popS(q);
        }
    }

}
void sortTenDeTai(StackDT *&top)
{
    detai S;
    StackDT *tmpStack;
    initDeTai(tmpStack);
    while (!isEmptyS(top))
    {
        S = top->data;
        popS(top);
        while (!isEmptyS(tmpStack) && strcmp(tmpStack->data.tenDeTai, S.tenDeTai)<0)
        {
            pushS(top, createNode(tmpStack->data));
            popS(tmpStack);
        }
        pushS(tmpStack, createNode(S));
    }
    top = tmpStack;

}

void fileWrite(StackDT *top, char *&fileName)
{
    StackDT *x, *y;
    initDeTai(x);
    initDeTai(y);
    detai S;
    if (strcmp(fileName, "detai.txt") != 0)
    {
        printf("\nNhap ten file can nhap(*.txt): ");
        fflush(stdin);
        scanf("%s", fileName);
        strcat(fileName, ".txt");
    }
    FILE *f;
    f = fopen(fileName, "ab");
    y = top;
    while (y!=NULL)
    {
        S=y->data;
        pushS(x, createNode(S));
        popS(y);
    }
    if (x == NULL)
    {
        printf("\nDanh detai chua co gia tri, nhap truoc khi luu file!");
    }
    if (f == NULL)
    {
        printf("\nLoi khi mo tep");
        exit(1);
    }
    else
    {
        while (x != NULL)
        {
            fwrite(&x->data, sizeof(x->data), 1, f);
            x = x->next;
        }

        fclose(f);
        printf("\nDa luu vao file \"%s\"!", fileName);
    }
}

void fileRead(StackDT *&top, char *fileName)
{
    FILE *f;
    initDeTai(top);
    if (strcmp(fileName, "detai.txt") != 0)
    {
        printf("\nNhap ten file(*.txt): ");
        fflush(stdin);
        scanf("%s", fileName);
        strcat(fileName, ".txt");
    }
    StackDT *p;
    detai sa;
    f = fopen(fileName, "rb");
    if (f == NULL)
    {
        printf("\nMo file bi loi!");
    }
    else
    {
        while (fread(&DTa, sizeof(sa), 1, f) == 1)
        {
            p = (StackDT *) malloc(sizeof(StackDT));
            p->data = sa;
            p->next = NULL;
            pushS(top, p);
        }
        fclose(f);
    }
}

void easeFile(char *fileName)
{
    FILE *f;
    if (strcmp(fileName, "detai.txt") != 0)
    {
        printf("\nNhap ten file can lam detai(*.txt): ");
        fflush(stdin);
        scanf("%s", fileName);
        strcat(fileName, ".txt");
    }
    f = fopen(fileName, "w");
    fclose(f);

}

void menuDT()
{
    StackDT *top;
    detai S;
    char *fileName;
    fileName = (char *) malloc(30);
    initDeTai(top);
    int key = 99;
    while (key != 0)
    {
        system("CLS");
        printf("%*s\n", 40, "****************************************************");
        printf("\n%s", "***       CHUONG TRINH QUAN LY DETAI               ***");
        printf("\n%s", "***      1.Nhap detai vao dau danh detai            ***");
        printf("\n%s", "***      2.Hien danh detai tu file                 ***");
        printf("\n%s", "***      3.Hien danh detai cuon detai cau >5      ***");
        printf("\n%s", "***      4.Tim kiem detai theo ma detai             ***");
        printf("\n%s", "***      5.Thong ke so dau detai gia lon hon X     ***");
        printf("\n%s", "***      6.Xoa thong tin detai o dau danh detai     ***");
        printf("\n%s", "***      7.Xoa thong tin detai o cuoi danh detai    ***");
        printf("\n%s", "***      8.Xoa thong tin detai o vi tri bat ky     ***");
        printf("\n%s", "***      9.Sap xep theo ten detai                  ***");
        printf("\n%s", "***      10.Tong so dau detai trong cua hang       ***");
        printf("\n%s", "***      11.Lam detai du lieu trong file           ***");
        printf("\n%s", "***      0.Thoat khoi chuong trinh                ***");
        printf("\n%s", "***      Nhap lua chon cua ban:");
        scanf("%d", &key);
        switch (key)
        {
            case 1:
                initDeTai(top);
                nhapDSS(top, S);
                fileWrite(top, fileName);
                printf("\n");
                system("PAUSE");
                break;
            case 2:
                fileRead(top, fileName);
                printf("\nDanh detai quyen detai tu file: ");
                xuatDetai(top);
                printf("\n");
                system("PAUSE");
                break;
            case 3:
                fileRead(top, fileName);
                xuat500(top);
                printf("\n");
                system("PAUSE");
                break;
            case 4:
                fileRead(top, fileName);
                searchMa(top);
                printf("\n");
                system("PAUSE");
                break;
            case 5:
                fileRead(top, fileName);
                thongKeSL(top);
                printf("\n");
                system("PAUSE");
                break;
            case 6:
                fileRead(top, fileName);
                popS(top);
                printf("\nDanh detai vua xoa dau danh detai!");
                xuatDetai(top);
                printf("\n");
                system("PAUSE");
                break;
            case 7:
                fileRead(top, fileName);
                delRear(top);
                printf("\nDanh detai vua xoa cuoi danh detai!");
                xuatDetai(top);
                printf("\n");
                system("PAUSE");
                break;
            case 8:
                fileRead(top, fileName);
                delMid(top);
                xuatDetai(top);
                printf("\n");
                system("PAUSE");
                break;
            case 9:
                fileRead(top, fileName);
                sortTenDeTai(top);
                xuatDetai(top);
                printf("\n");
                system("PAUSE");
                break;

            case 10:
                fileRead(top, fileName);
                printf("\nTong so detai trong cua hang la: %d", sizeS(top));
                printf("\n");
                system("PAUSE");
                break;
            case 11:
                fileRead(top, fileName);
                easeFile(fileName);
                printf("\nLam detai thanh cong!");
                printf("\n");
                system("PAUSE");
                break;
            case 0:
                break;
            default:
                printf("\nBan nhap sai, xin vui long nhap lai!");
                printf("\n");
                system("PAUSE");
                break;
        }

    }
}

int main()
{
    menuDT();
    return 0;
}


