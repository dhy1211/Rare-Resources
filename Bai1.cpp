#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main() {
    int n, a[100], temp;
    cout << "Nhap n: "; cin >> n;

    // Nhap va luu vao 1.txt
    ofstream f1("1.txt");
    for (int i = 0; i < n; i++) {
        cout << "Nhap so thu " << i + 1 << ": "; cin >> a[i];
        f1 << a[i] << " ";
    }
    f1.close();

    // a) Doc tu 1.txt, sap xep roi luu vao 2.txt
    ifstream f1_in("1.txt");
    int count = 0;
    while (f1_in >> temp) {
        a[count++] = temp;
    }
    f1_in.close();

    // Thuat toan Sap xep noi bot (Bubble Sort) tu Chuong 4
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (a[j] > a[j+1]) {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }

    ofstream f2("2.txt");
    for (int i = 0; i < count; i++) f2 << a[i] << " ";
    f2.close();

    // b) Xoa 1.txt va doi ten 2.txt thanh sort.txt
    remove("1.txt");
    rename("2.txt", "sort.txt");

    // c) Them vao cuoi tep sort.txt so 2025
    ofstream f_sort("sort.txt", ios::app);
    f_sort << 2025;
    f_sort.close();

    cout << "Da hoan thanh Bai 1.\n";
    return 0;
}