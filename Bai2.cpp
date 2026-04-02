#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main() {
    // Tao file tho.doc va ghi du lieu
    ofstream f_out("tho.doc");
    f_out << "Song bat dau tu gio\n";
    f_out << "Gio bat dau tu dau\n";
    f_out << "Em cung khong biet nua\n";
    f_out << "Khi nao ta yeu nhau\n";
    f_out.close();

    // a) Doc noi dung va b) Tim cau dai nhat
    ifstream f_in("tho.doc");
    char line[100], maxLine[100] = "";
    cout << "--- Noi dung bai tho ---\n";
    
    while (f_in.getline(line, 100)) {
        cout << line << endl;
        if (strlen(line) > strlen(maxLine)) {
            strcpy(maxLine, line);
        }
    }
    f_in.close();

    cout << "\nCau tho co nhieu ki tu nhat: " << maxLine << endl;
    return 0;
}