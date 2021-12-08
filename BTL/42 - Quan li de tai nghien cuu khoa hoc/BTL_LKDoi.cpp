#include <bits/stdc++.h>
using namespace std;
typedef struct DeTai
{
    int soLuong;
    char tenDeTai[50], SinhVien[30], maDeTai[30];
} detai;
typedef struct nodeDeTai
{
    DeTai data;
    struct nodeDeTai *next;
    struct nodeDeTai *prev;
} qldt;
// chuong trinh quan ly dt
void initDeTai(qldt *&head, qldt *&tail)
{
    head = NULL;
    tail = NULL;
};
nodeDeTai *createNode()
{
    qldt *new_node = (qldt *) malloc(sizeof(qldt));
    cout<<"\nNhap ten De Tai: ";
    fflush(stdin);
    gets(*&new_node->data.tenDeTai);
    cout<<"Nhap ma De Tai: ";
    fflush(stdin);
    cin>>*&new_node->data.maDeTai;
    cout<<"Nhap ten Sinh Vien lam De Tai: ";
    fflush(stdin);
    gets(*&new_node->data.SinhVien);
    cout<<"Nhap so luong: ";
    cin>>*&new_node->data.soLuong;
    new_node->next = NULL;
    new_node->prev=NULL;
    return new_node;
}

//nhap
void addHead(qldt *&head, qldt *&tail)
{

    qldt *add_head = createNode();
    if (head == NULL)
    {
        head = add_head;
        tail = head;
    }
    else
    {
        head->prev = add_head;
        add_head->next=head;
        head = add_head;
    }
}

void addTail(qldt *&head, qldt *&tail)
{
    qldt *add_tail = createNode();
    if (head == NULL)
    {
        tail = add_tail;
        head = tail;
    }
    else
    {
        tail->next = add_tail;
        add_tail->prev = tail;
        tail = add_tail;
    }
}

//nhap
void nhapHead(qldt *&head, qldt *&tail)
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
        addHead(head, tail);
    }
}

void nhapTail(qldt *&head, qldt *&tail)
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
        addTail(head, tail);
    }
}

//xuat
void xuat(qldt *head, qldt *tail)
{
    qldt *p;
    p = head;
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

void xuat5(qldt *head, qldt *tail)
{
    qldt *p;
    p = head;
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

//dem
void thongKeSL(qldt *head, qldt *tail)
{
    qldt *p = head;
    int i = 0, n;
    cout<<"\nNhap so luong De Tai can kiem tra: ";
    cin>>n;

    while (p != NULL)
    {
        if (p->data.soLuong > n)
            i++;
        p = p->next;
    }
    if (i == 0)
    {
        cout<<"Khong co De Tai nao co so luong tren: "<<n;
    }
    else
    {
        cout<<"So luong De Tai co so luong lon hon: "<<n<<" la: "<<i;
    }
}

void thongKeSV(qldt *head, qldt *tail)
{
    qldt *p = head;
    char SV[50];
    cout<<"\nNhap ten Sinh Vien can thong ke: ";
    fflush(stdin);
    gets(*&SV);
    int i = 0;
    while (p != NULL)
    {
        if (strcmp(SV, p->data.SinhVien) == 0)
        {
            i++;
        }
        p = p->next;
    }
    if (i == 0)
    {
        cout<<"\nKhong co De Tai nao cua Sinh Vien vua nhap!";
    }
    else
    {
        cout<<"Tong so De Tai cua Sinh Vien: "<<SV<<" la: "<<i;
    }
}

void xoaHead(qldt *&head, qldt *&tail)
{

    if (head != NULL)
    {
        qldt *p = head;
        head=head->next;
        free(p);
    }
    else
    {
        printf("\nKhong ton tai gia tri nao trong danh sach!");
    }
}

void xoaTail(qldt *&head, qldt *&tail)
{
    qldt *p, *q;
    p=head;
    q=tail;
    if (tail != NULL)
    {
        tail=p;
        tail=tail->prev;
        tail->next=NULL;
        free(q);

    }
    else
    {
        printf("\nKhong ton tai gia tri trong danh sach!");
    }
}

int demDT(qldt *head, qldt *tail)
{
  int  i = 0;
    qldt *p = head;
    while (p != NULL)
    {
        i++;
        p = p->next;
    }
    cout<<"\nTong so De Tai: "<<i;
    return i;
}
void sortTenDeTai(qldt *&head, qldt *&tail)
{
    qldt *p, *q;
    p = head;
    if (p != NULL)
    {
        while (p != NULL)
        {
            q = p->next;
            while (q != NULL)
            {
                if (strcmp(p->data.tenDeTai, q->data.tenDeTai) > 0)
                {
                    detai tg = p->data;
                    p->data = q->data;
                    q->data = tg;
                    //bubbleSort
                }
                q = q->next;
            }
            p = p->next;
        }
        cout<<"\nDanh sach De Tai sap xep theo ten De Tai la: ";
        xuat(head, tail);
    }
    else
    {
        cout<<"\nKhong co gia tri nao trong danh sach";
    }
}

void sortTenSV(qldt *&head, qldt *&tail)
{
    qldt *p, *q;
    p = head;
    if (p != NULL)
    {
        while (p != NULL)
        {
            q = p->next;
            while (q != NULL)
            {
                if (strcmp(p->data.SinhVien, q->data.SinhVien) > 0)
                {
                    detai tg = p->data;
                    p->data = q->data;
                    q->data = tg;
                    //bubbleSort
                }
                q = q->next;
            }
            p = p->next;
        }
        cout<<"\nDanh sach De Tai sap xep theo ten Sinh Vien :";
        xuat(head, tail);
    }
    else
    {
        cout<<"\nKhong co gia tri nao trong danh sach";
    }
}

void sortSoLuong(qldt *&head, qldt *&tail)
{
    qldt *p, *q;
    p = head;
    if (p != NULL)
    {
        while (p != NULL)
        {
            q = p->next;
            while (q != NULL)
            {
                if (p->data.soLuong > q->data.soLuong)
                {
                    detai tg = p->data;
                    p->data = q->data;
                    q->data = tg;
                    //bubbleSort
                }
                q = q->next;
            }
            p = p->next;
        }
        cout<<"\nDanh sach De Tai sap xep theo so luong: ";
        xuat(head, tail);
    }
    else
    {
        cout<<"\nKhong co gia tri nao trong danh sach";
    }
}

//tong so cau hoi dt
void tongSocauhoiDT(qldt *head, qldt *tail)
{
    qldt *p = head;
    int i = 0;
    while (p != NULL)
    {
        i += p->data.soLuong;
        p = p->next;
    }
    cout<<"\nTong so cau hoi De Tai dang co: "<<i;
}



void fileWrite(qldt *head, qldt *tail, char *&fileName)
{
    qldt *x;
    detai dt;
    if (strcmp(fileName, "detai.txt") != 0)
    {
        cout<<"\nNhap ten file can nhap(*.txt): ";
        fflush(stdin);
        cin>>fileName;
        strcat(fileName, ".txt");
    }
    FILE *f;
    f = fopen(fileName, "ab");
    x=head;
    if (x == NULL)
    {
        cout<<"\nDanh sach chua co gia tri, nhap truoc khi luu file!";
    }
    if (f == NULL)
    {
        cout<<"\nLoi khi mo tep";
        exit(1);
    }
    else
    {
        while (x != NULL)
        {
            dt=x->data;
            fwrite(&dt, sizeof(dt), 1, f);
            x = x->next;
        }

        fclose(f);
        cout<<"\nDa luu vao file!"<<fileName;
    }
}

void fileRead(qldt *&head, qldt *&tail, char *fileName)
{
    FILE *f;
    if (strcmp(fileName, "detai.txt") != 0)
    {
        cout<<"\nNhap ten file can hien(*.txt): ";
        fflush(stdin);
        cin>>fileName;
        strcat(fileName, ".txt");
    }
    qldt *p;
    detai dt;
    f = fopen(fileName, "rb");
    int n = 0;
    if (f == NULL)
    {
        cout<<"\nMo file bi loi!";
    }
    else
    {
        p=head;
        while (fread(&dt, sizeof(dt), 1, f) ==1)
        {

            p=(qldt*)malloc(sizeof(qldt));
            p->data=dt;
            if(head ==NULL)
            {
                head=p;
                tail=head;
                p->next=NULL;
            }
            else
            {
                p->next=head;
                head=p;
            }
        }
        fclose(f);
    }
}
void easeFile(qldt *&head, qldt *&tail, char *fileName)
{
    FILE *f;
    if (strcmp(fileName, "detai.txt") != 0)
    {
        cout<<"\nNhap ten file can lam sach(*.txt): ";
        fflush(stdin);
        cin>>fileName;
        strcat(fileName, ".txt");
    }
    f = fopen(fileName, "w");
    fclose(f);

}
void menuDeTai()
{
    qldt *head, *tail;
    char *fileName;
    fileName = (char *) malloc(30);
    initDeTai(head, tail);
    int key=99;
    while (key!=0)
    {
        system("CLS");
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"---          CHUONG TRINH QUAN LI DE TAI LKDOI       ---"<<endl;
        cout<<"---          1.Nhap De Tai vao dau danh sach         ---"<<endl;
        cout<<"---          2.Nhap De Tai vao cuoi danh sach        ---"<<endl;
        cout<<"---          3.Hien danh sach vua nhap               ---"<<endl;
        cout<<"---          4.Cap nhat thong tin vao file           ---"<<endl;
        cout<<"---          5.Hien danh sach tu file                ---"<<endl;
        cout<<"---          6.Hien danh sach De Tai tren 5 cau hoi  ---"<<endl;
        cout<<"---          7.Thong ke so De Tai co cau hoi >= X    ---"<<endl;
        cout<<"---          8.Thong ke so De Tai cua Sinh Vien Y    ---"<<endl;
        cout<<"---          9.Xoa thong tin De Tai o dau danh sach  ---"<<endl;
        cout<<"---          10.Xoa thong tin De Tai o cuoi danh sach---"<<endl;
        cout<<"---          11.Sap xep theo ten De Tai              ---"<<endl;
        cout<<"---          12.Sap xep theo ten Sinh Vien           ---"<<endl;
        cout<<"---          13.Sap xep theo so luong De Tai         ---"<<endl;
        cout<<"---          14.Tong so De Tai                       ---"<<endl;
        cout<<"---          15.Tong so cau hoi De Tai               ---"<<endl;
        cout<<"---          16.Lam sach du lieu                     ---"<<endl;
        cout<<"---          0.Thoat khoi chuong trinh               ---"<<endl;
        cout<<"NHAP LUA CHON CUA BAN: ";
        cin>>*&key;
        switch (key)
        {
        case 1:
            initDeTai(head, tail);
            nhapHead(head, tail);
            cout<<"\n";
            system("PAUSE");
            break;
        case 2:
            initDeTai(head, tail);
            nhapTail(head, tail);
            cout<<"\n";
            system("PAUSE");
            break;
        case 3:
            cout<<"\nDanh sach vua nhap vao!";
            xuat(head, tail);
            cout<<"\n";
            system("PAUSE");
            break;
        case 4:
            fileWrite(head, tail, fileName);
            cout<<"\n";
            system("PAUSE");
            break;
        case 5:
            initDeTai(head, tail);
            cout<<"\nDanh sach De Tai tu file: ";
            fileRead(head, tail, fileName);
            xuat(head, tail);
            cout<<"\n";
            system("PAUSE");
            break;
        case 6:
            initDeTai(head, tail);
            fileRead(head, tail, fileName);
            xuat5(head, tail);
            cout<<"\n";
            system("PAUSE");
            break;
        case 7:
            initDeTai(head, tail);
            fileRead(head, tail, fileName);
            thongKeSL(head, tail);
            cout<<"\n";
            system("PAUSE");
            break;
        case 8:
            initDeTai(head, tail);
            fileRead(head, tail, fileName);
            thongKeSV(head, tail);
            cout<<"\n";
            system("PAUSE");
            break;
        case 9:
            initDeTai(head, tail);
            fileRead(head, tail, fileName);
            xoaHead(head, tail);
            cout<<"\nDanh sach vua xoa dau danh sach!";
            xuat(head, tail);
            easeFile(head, tail, fileName);
            fileWrite(head, tail, fileName);
            cout<<"\n";
            system("PAUSE");
            break;
        case 10:
            initDeTai(head, tail);
            fileRead(head, tail, fileName);
            xoaTail(head, tail);
            cout<<"\nDanh sach vua xoa cuoi danh sach!";
            xuat(head, tail);
            easeFile(head, tail, fileName);
            fileWrite(head, tail, fileName);
            cout<<"\n";
            system("PAUSE");
            break;
        case 11:
            initDeTai(head, tail);
            fileRead(head, tail, fileName);
            sortTenDeTai(head, tail);
            cout<<"\n";
            system("PAUSE");
            break;
        case 12:
            initDeTai(head, tail);
            fileRead(head, tail, fileName);
            sortTenSV(head, tail);
            cout<<"\n";
            system("PAUSE");
            break;
        case 13:
            initDeTai(head, tail);
            fileRead(head, tail, fileName);
            sortSoLuong(head, tail);
            cout<<"\n";
            system("PAUSE");
            break;
        case 14:
            initDeTai(head, tail);
            fileRead(head, tail, fileName);
            cout<<"\nTong so De Tai: "<<demDT(head, tail);
            cout<<"\n";
            system("PAUSE");
            break;
        case 15:
            initDeTai(head, tail);
            fileRead(head, tail, fileName);
            tongSocauhoiDT(head, tail);
            cout<<"\n";
            system("PAUSE");
            break;
        case 16:
            initDeTai(head, tail);
            fileRead(head, tail, fileName);
            easeFile(head, tail, fileName);
            cout<<"\nLam sach thanh cong!";
            cout<<"\n";
            system("PAUSE");
            break;
        case 0:
            break;
        default:
            cout<<"\nBan nhap sai, xin vui long nhap lai!";
            cout<<"\n";
            system("PAUSE");
            break;
        }

    }
}

int main()
{
    menuDeTai();
    return 0;
}


