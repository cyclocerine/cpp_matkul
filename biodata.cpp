#include <iostream>
using namespace std;

int main() {
    string nama;
    int umur;
    float tb;

    cout << "what's your name? " << endl;
    getline(cin, nama);
    cout << "how old are you? " << endl;
    cin >> umur;
    cout << "how tall are you?(in cm) " << endl;
    cin >> tb;
    cout << "hello " << nama << " umur kamu " << umur << " tinggi kamu " << tb << " cm" <<endl;
}