#include <iostream>
#define PI 3.14159
using namespace std;

int main() {
    float r, luas, keliling;
    string nama;

    cout << "=== Aplikasi Kalkulator lingkaran ===" << endl;
    cout << "Masukan nama Anda: ";
    getline(cin, nama);
    cout << "Masukan jari-jari lingkaran: ";
    cin >> r;
    cout << endl;
    cout << endl;
    cout << "terima kasih " << nama << endl;
    luas = PI * r * r;
    keliling = 2 * PI * r;
    cout << "luas lingkaran adalah " << luas << endl;
    cout << "keliling lingkaran adalah " << keliling << endl;

    return 0;
}