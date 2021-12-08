#include <bits/stdc++.h>
using namespace std;
typedef struct nodeDeTai {
    int soLuong;
    char tenDeTai[50], SinhVien[30], maDeTai[30];
} detai;
typedef struct QUEUEDeTai {
    nodeDeTai data;
    QUEUEDeTai *next;
    QUEUEDeTai *prev;
} Queuedt;

void initDeTai(Queuedt *&front, Queuedt *&rear) {
    front = NULL;
    rear = NULL;
};
//
void nhapDeTai(detai &DT) {
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

Queuedt *createNodeDT(detai DT) {
    Queuedt *new_node;
    new_node = (Queuedt *) malloc(sizeof(Queuedt));
    new_node->data = DT;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

bool isEmptyDT(Queuedt *front) {
    return !front;
}

//nhap
void enQueueDT(Queuedt *&front, Queuedt *&rear, Queuedt *createRear) {

    if (rear == NULL) {
        rear = createRear;
        front = rear;
    } else {
        rear->next = createRear;
        createRear->prev = rear;
        rear = createRear;
    }
}

void delQueueDT(Queuedt *&front) {
    if (front == NULL)
        cout<<"\nKhong co gia tri trong danh sach";
    else {
        Queuedt *q = front;
        front = front->next;
        free(q);
    }
}

//nhap
void nhapDT(Queuedt *&front, Queuedt *&rear, detai &DT) {
    int n;

    do {
        cout<<"\nNhap vao so De Tai: ";
        cin>>n;
    } while (n < 0);
    for (int i = 0; i < n; i++) {
        cout<<"\nNhap thong tin De Tai: "<<i+1;
        nhapDeTai(DT);
        enQueueDT(front, rear, createNodeDT(DT));
    }
}

//xuat
void xuatDeTai(Queuedt *front, Queuedt *rear) {
    Queuedt *p;
    p = front;
    if ((front == NULL) && (rear == NULL)) cout<<"\nKhong co gia tri de in ra!";
    else {
        cout << setw(30) << left << "\nTen De Tai";
        cout << setw(12) << left << "Ma De Tai";
        cout << setw(30) << left << "Sinh Vien lam";
        cout << setw(8) << right << "So luong" << endl;
        while (p != NULL) {
        cout << setw(30) << left << p->data.tenDeTai;
        cout << setw(12) << left << p->data.maDeTai;
        cout << setw(30) << left << p->data.SinhVien;
        cout << setw(8) << right << p->data.soLuong << endl;
            p = p->next;
        }
    }
}

void xuat5(Queuedt *front, Queuedt *rear) {
    Queuedt *p;
    p = front;
    cout<<"\nDanh sach De Tai tren 5 cau hoi: ";
    if ((front == NULL) && (rear == NULL)) cout<<"\nKhong co gia tri de in ra!";
    else {
        cout << setw(30) << left << "\nTen De Tai";
        cout << setw(12) << left << "Ma De Tai";
        cout << setw(30) << left << "Sinh Vien lam";
        cout << setw(8) << right << "So luong" << endl;
        while (p != NULL) {
            if (p->data.soLuong > 5) {
            cout << setw(30) << left << p->data.tenDeTai;
            cout << setw(12) << left << p->data.maDeTai;
            cout << setw(30) << left << p->data.SinhVien;
            cout << setw(8) << right << p->data.soLuong << endl;
            }
            p = p->next;
        }
    }

}
void searchMa(Queuedt *front, Queuedt *rear) {
    char ma[50];
    cout<<"\nNhap ma De Tai can tim: ";
    fflush(stdin);
    cin>>ma;
    Queuedt *p = front;
    if ((front == NULL) && (rear == NULL)) cout<<"\nKhong co gia tri de in ra!";
    else {
        cout << setw(30) << left << "\nTen De Tai";
        cout << setw(12) << left << "Ma De Tai";
        cout << setw(30) << left << "Sinh Vien lam";
        cout << setw(8) << right << "So luong" << endl;
        while (p != NULL) {
            if (strcmp(ma, p->data.maDeTai) == 0) {
            cout << setw(30) << left << p->data.tenDeTai;
            cout << setw(12) << left << p->data.maDeTai;
            cout << setw(30) << left << p->data.SinhVien;
            cout << setw(8) << right << p->data.soLuong << endl;
            }
            p = p->next;
        }
    }
}

void searchSV(Queuedt *front, Queuedt *rear) {
    char ma[50];
    cout<<"\nNhap ten Sinh Vien lam De Tai: ";
    fflush(stdin);
    gets(ma);
    Queuedt *p = front;
    if ((front == NULL) && (rear == NULL)) cout<<"\nKhong co gia tri de in ra!";
    else {
        cout << setw(30) << left << "\nTen De Tai";
        cout << setw(12) << left << "Ma De Tai";
        cout << setw(30) << left << "Sinh Vien lam";
        cout << setw(8) << right << "So luong" << endl;
        while (p != NULL) {
            if (strcmp(ma, p->data.SinhVien) == 0) {
            cout << setw(30) << left << p->data.tenDeTai;
            cout << setw(12) << left << p->data.maDeTai;
            cout << setw(30) << left << p->data.SinhVien;
            cout << setw(8) << right << p->data.soLuong << endl;
            }
            p = p->next;
        }
    }
}
//dem
void thongKeSL(Queuedt *front) {
    Queuedt *p = front;
    int i = 0, n;
    cout<<"\nNhap so luong De Tai can kiem tra: ";
    cin>>n;

    while (p != NULL) {
        if (p->data.soLuong > n)
            i++;
        p = p->next;
    }
    if (i == 0) {
        cout<<"Khong co De Tai nao co so luong tren: "<<n;
    } else {
        cout<<"So luong De Tai co so luong lon hon: "<<n<<" la: "<<i;
    }
}

void delRear(Queuedt *&front, Queuedt *&rear) {
    detai X;
    Queuedt *p, *q;
    initDeTai(p, q);
    if (isEmptyDT(front))
        cout<<"\nKhong ton tai gia tri trong danh sach";
    else if (front->next == NULL) {
        front = NULL;
    } else {
        while (front != NULL) {
            X = front->data;
            enQueueDT(p, q, createNodeDT(X));
            delQueueDT(front);
        }
        delQueueDT(p);
        while (p != NULL) {
            X = q->data;
            enQueueDT(front, rear, createNodeDT(X));
            delQueueDT(p);
        }
    }
}

int sizeDT(Queuedt *front) {
    int i = 0;
    Queuedt *p = front;
    while (p != NULL) {
        i++;
        p = p->next;
    }
    return i;
}

void delMid(Queuedt *&front, Queuedt *&rear) {
    Queuedt *p, *q;
    detai DT;
    initDeTai(p, q);
    int k;
    do {
        cout<<"\nNhap vi tri can xoa: ";
        cin>>*&k;
    } while (k < 1 || k > sizeDT(front));
    if (front == NULL) {
        cout<<"\nDanh sach khong co gia tri";
    } else if (front->next == NULL) {
        front = NULL;
        free(front);
    } else {
        int z = 0;
        while (front != NULL) {
            z++;
            DT = front->data;
            enQueueDT(p, q, createNodeDT(DT));
            if (z == k) {
                delQueueDT(q);
            }
            delQueueDT(front);

        }
        while (q != NULL) {
            DT = q->data;
            enQueueDT(front, rear, createNodeDT(DT));
            delQueueDT(q);
        }
    }

}

void sortTenDeTai(Queuedt *&front, Queuedt *&rear) {
    detai DT;
    Queuedt *p, *q;
    initDeTai(p, q);
    while (!isEmptyDT(front)) {
        DT = front->data;
        delQueueDT(front);
        while (!isEmptyDT(p) && strcmp(p->data.tenDeTai, DT.tenDeTai) < 0) {
            enQueueDT(front, rear, createNodeDT(p->data));
            delQueueDT(p);
        }
        enQueueDT(p, q, createNodeDT(DT));

    }
    front=p;
    rear = q;
}
void sortTenSinhVien(Queuedt *&front, Queuedt *&rear) {
    detai DT;
    Queuedt *p, *q;
    initDeTai(p, q);
    while (!isEmptyDT(front)) {
        DT = front->data;
        delQueueDT(front);
        while (!isEmptyDT(p) && strcmp(p->data.SinhVien, DT.SinhVien) < 0) {
            enQueueDT(front, rear, createNodeDT(p->data));
            delQueueDT(p);
        }
        enQueueDT(p, q, createNodeDT(DT));

    }
    front=p;
    rear = q;
}
void fileWrite(Queuedt *front, char *&fileName) {
    Queuedt *x;
    x=front;
    detai DT;
    if (strcmp(fileName, "detai.txt") != 0) {
        cout<<"\nNhap ten file can nhap(*.txt): ";
        fflush(stdin);
        cin>>fileName;
        strcat(fileName, ".txt");
    }
    FILE *f;
    f = fopen(fileName, "ab");
    if (x == NULL) {
        cout<<"\nDanh sach chua co gia tri, nhap truoc khi luu file!";
    }
    if (f == NULL) {
        cout<<"\nLoi khi mo tep";
        exit(1);
    } else {
        while (x != NULL) {
            fwrite(&x->data, sizeof(x->data), 1, f);
            x = x->next;
        }

        fclose(f);
        cout<<"\nDa luu vao file: "<<fileName;
    }
}

void fileRead(Queuedt *&front,Queuedt  *&rear, char *fileName) {
    FILE *f;
    initDeTai(front, rear);
    if (strcmp(fileName, "detai.txt") != 0) {
        cout<<"\nNhap ten file(*.txt): ";
        fflush(stdin);
        cin>>fileName;
        strcat(fileName, ".txt");
    }
    Queuedt *p;
    detai dt;
    f = fopen(fileName, "rb");
    if (f == NULL) {
        cout<<"\nMo file bi loi!";
    } else {
        while (fread(&dt, sizeof(dt), 1, f) == 1) {
            p = (Queuedt *) malloc(sizeof(Queuedt));
            p->data = dt;
            p->next = NULL;
            enQueueDT(front, rear, p);
        }
        fclose(f);
    }
}

void easeFile(char *fileName) {
    FILE *f;
    if (strcmp(fileName, "detai.txt") != 0) {
        cout<<"\nNhap ten file can lam sach(*.txt): ";
        fflush(stdin);
        cin>>fileName;
        strcat(fileName, ".txt");
    }
    f = fopen(fileName, "w");
    fclose(f);

}
void menuDeTai() {
    Queuedt *front, *rear;
    detai DT;
    char *fileName;
    fileName = (char *) malloc(30);
    initDeTai(front, rear);
    int key = 99;
    while (key != 0) {
        system("CLS");
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"---          CHUONG TRINH QUAN LI DE TAI QUEUE       ---"<<endl;
        cout<<"---          1.Nhap De Tai vao danh sach             ---"<<endl;
        cout<<"---          2.Hien danh sach vua nhap               ---"<<endl;
        cout<<"---          3.Hien danh sach De Tai tren 5 cau hoi  ---"<<endl;
        cout<<"---          4.Tim kiem danh sach theo ma De Tai     ---"<<endl;
        cout<<"---          5.Tim kiem danh sach theo Sinh Vien     ---"<<endl;
        cout<<"---          6.Thong ke so De Tai co cau hoi = X     ---"<<endl;
        cout<<"---          7.Xoa thong tin De Tai o dau danh sach  ---"<<endl;
        cout<<"---          8.Xoa thong tin De Tai o cuoi danh sach ---"<<endl;
        cout<<"---          9.Xoa thong tin De Tai o tri danh sach  ---"<<endl;
        cout<<"---          10.Sap xep theo ten De Tai              ---"<<endl;
        cout<<"---          11.Sap xep theo ten Sinh Vien           ---"<<endl;
        cout<<"---          12.Tong so De Tai                       ---"<<endl;
        cout<<"---          13.Lam sach du lieu                     ---"<<endl;
        cout<<"---          0.Thoat khoi chuong trinh               ---"<<endl;
        cout<<"NHAP LUA CHON CUA BAN: ";
        cin>>*&key;
        switch (key) {
            case 1:
                initDeTai(front, rear);
                nhapDT(front, rear, DT);
                fileWrite(front, fileName);
                cout<<"\n";
                system("PAUSE");
                break;
            case 2:
                fileRead(front,rear, fileName);
                cout<<"\nDanh sach De Tai tu file: ";
                xuatDeTai(front,rear);
                cout<<"\n";
                system("PAUSE");
                break;
            case 3:
                fileRead(front,rear, fileName);
                xuat5(front, rear);
                cout<<"\n";
                system("PAUSE");
                break;
            case 4:
                fileRead(front,rear, fileName);
                searchMa(front, rear);
                cout<<"\n";
                system("PAUSE");
                break;
            case 5:
                fileRead(front,rear, fileName);
                searchSV(front, rear);
                cout<<"\n";
                system("PAUSE");
                break;
            case 6:
                fileRead(front,rear, fileName);
                thongKeSL(front);
                cout<<"\n";
                system("PAUSE");
                break;
            case 7:
                fileRead(front,rear, fileName);
                delQueueDT(front);
                cout<<"\nDanh sach vua xoa dau danh sach!";
                xuatDeTai(front,rear);
                cout<<"\n";
                system("PAUSE");
                break;
            case 8:
                fileRead(front,rear, fileName);
                delRear(front, rear);
                cout<<"\nDanh sach vua xoa cuoi danh sach!";
                xuatDeTai(front,rear);
                cout<<"\n";
                system("PAUSE");
                break;
            case 9:
                fileRead(front,rear, fileName);
                delMid(front, rear);
                xuatDeTai(front,rear);
                cout<<"\n";
                system("PAUSE");
                break;
            case 10:
                fileRead(front,rear, fileName);
                sortTenDeTai(front, rear);
                xuatDeTai(front,rear);
                cout<<"\n";
                system("PAUSE");
                break;
            case 11:
                fileRead(front,rear, fileName);
                sortTenSinhVien(front, rear);
                xuatDeTai(front,rear);
                cout<<"\n";
                system("PAUSE");
                break;
            case 12:
                fileRead(front,rear, fileName);
                cout<<"\nTong so De Tai la: "<<sizeDT(front);
                cout<<"\n";
                system("PAUSE");
                break;
            case 13:
                fileRead(front,rear, fileName);
                easeFile(fileName);
                cout<<"\nLam sach thanh cong!";
                cout<<"\n";
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

int main() {
    menuDeTai();
    return 0;
}


