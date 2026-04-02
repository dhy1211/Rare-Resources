#include <iostream>
#include <string>

using namespace std;

int main() {
    // Khai báo mảng tĩnh lưu trữ Can và Chi
    string ds_can[] = {"Giap", "At", "Binh", "Dinh", "Mau", "Ky", "Canh", "Tan", "Nham", "Quy"};
    string ds_chi[] = {"Ty", "Suu", "Dan", "Mao", "Thin", "Ty.", "Ngo", "Mui", "Than", "Dau", "Tuat", "Hoi"};

    int nam_duong;
    cout << "Nhap vao nam duong lich: ";
    cin >> nam_duong;

    if (nam_duong < 0) {
        cout << "Vui long nhap nam duong lich >= 0." << endl;
        return 0;
    }

    // 1. Tinh và xuat nam Am lich
    int idx_can = (nam_duong + 6) % 10;
    int idx_chi = (nam_duong + 8) % 12;

    cout << "\n--- KET QUA ---" << endl;
    cout << "Nam am lich: " << ds_can[idx_can] << " " << ds_chi[idx_chi] << endl;

    // 2. Xuat cac nam Hop (chu ky 4 nam)
    cout << "Cac nam Hop (cach 4 nam): ";
    for (int i = -8; i <= 8; i += 4) {
        if (i == 0) continue;
        int nam_lien_quan = nam_duong + i;
        if (nam_lien_quan >= 0) {
            cout << nam_lien_quan << " ";
        }
    }

    // 3. Xuat cac nam Ky (chu ky 3 nam)
    cout << "\nCac nam Ky (cach 3 nam): ";
    for (int i = -9; i <= 9; i += 3) {
        if (i == 0) continue; 
        int nam_lien_quan = nam_duong + i;
        if (nam_lien_quan >= 0) {
            cout << nam_lien_quan << " ";
        }
    }
    cout << endl;

    return 0;
}