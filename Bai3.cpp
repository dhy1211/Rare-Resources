#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct SinhVien {
    char hoTen[50];
    char ngaySinh[20];
    char gioiTinh[10];
    float diem;
};

void nhapSV() {
    SinhVien sv;
    cin.ignore();
    cout << "Ho ten: "; cin.getline(sv.hoTen, 50);
    cout << "Ngay sinh: "; cin.getline(sv.ngaySinh, 20);
    cout << "Gioi tinh: "; cin.getline(sv.gioiTinh, 10);
    cout << "Diem: "; cin >> sv.diem;

    ofstream f("sinhvien.dat", ios::binary | ios::app);
    f.write((char*)&sv, sizeof(SinhVien));
    f.close();
}

void xemDS() {
    SinhVien sv;
    ifstream f("sinhvien.dat", ios::binary);
    cout << "\n--- Danh sach sinh vien ---\n";
    while (f.read((char*)&sv, sizeof(SinhVien))) {
        cout << sv.hoTen << " | " << sv.ngaySinh << " | " << sv.diem << endl;
    }
    f.close();
}

// Chuc nang Xoa/Sua: Doc het vao mang -> Xu ly -> Ghi de file
void xoaSV() {
    char tenXoa[50];
    cout << "Nhap ten SV can xoa: "; cin.ignore(); cin.getline(tenXoa, 50);
    
    SinhVien ds[100];
    int n = 0;
    ifstream f_in("sinhvien.dat", ios::binary);
    while (f_in.read((char*)&ds[n], sizeof(SinhVien))) n++;
    f_in.close();

    ofstream f_out("sinhvien.dat", ios::binary); // Mo de ghi de (truncate)
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].hoTen, tenXoa) != 0) {
            f_out.write((char*)&ds[i], sizeof(SinhVien));
        }
    }
    f_out.close();
    cout << "Da thuc hien xoa.\n";
}

int main() {
    int chon;
    do {
        cout << "\n1.Nhap | 2.Xem | 3.Xoa | 0.Thoat: "; cin >> chon;
        if (chon == 1) nhapSV();
        else if (chon == 2) xemDS();
        else if (chon == 3) xoaSV();
    } while (chon != 0);
    return 0;
}