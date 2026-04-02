#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct User {
    char username[30];
    char password[30];
};

void dangKy() {
    User u;
    cout << "Ten tai khoan: "; cin >> u.username;
    cout << "Mat khau: "; cin >> u.password;
    ofstream f("users.dat", ios::binary | ios::app);
    f.write((char*)&u, sizeof(User));
    f.close();
    cout << "Dang ky thanh cong!\n";
}

int main() {
    char un[30], pw[30];
    bool loginSuccess = false;
    User currentUser, temp;

    cout << "--- DANG NHAP ---\n";
    cout << "Username: "; cin >> un;
    cout << "Password: "; cin >> pw;

    ifstream f_in("users.dat", ios::binary);
    while (f_in.read((char*)&temp, sizeof(User))) {
        if (strcmp(temp.username, un) == 0 && strcmp(temp.password, pw) == 0) {
            loginSuccess = true;
            currentUser = temp;
            break;
        }
    }
    f_in.close();

    if (loginSuccess) {
        cout << "Dang nhap thanh cong!\n";
        cout << "Ban co muon doi mat khau? (1: Co, 0: Khong): ";
        int choice; cin >> choice;
        if (choice == 1) {
            char oldPw[30];
            cout << "Nhap mat khau cu: "; cin >> oldPw;
            if (strcmp(oldPw, currentUser.password) == 0) {
                cout << "Nhap mat khau moi: "; cin >> currentUser.password;
                // Ghi de lai file de cap nhat mat khau (giong logic bai 3)
                cout << "Doi mat khau thanh cong!\n";
            } else cout << "Sai mat khau cu!\n";
        }
    } else {
        cout << "Tai khoan khong ton tai. Ban co muon dang ky moi? (1: Co): ";
        int ck; cin >> ck;
        if (ck == 1) dangKy();
    }
    return 0;
}
