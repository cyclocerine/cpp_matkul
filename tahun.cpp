#include <iostream>
using namespace std;

int main() {
    int tl, ts, umur;
    cout << "input tahun lahir anda " << endl;
    cin >> tl;
    cout << "input tahun saat ini " << endl;
    cin >> ts;
    umur = ts - tl;
    cout << "umur anda adalah " << umur <<endl;
}