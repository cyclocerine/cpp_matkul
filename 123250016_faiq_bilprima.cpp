#include <iostream>
using namespace std;

int main() {
    int bilangan, i;
    bool Prima = true;

    cout << "Masukkan sebuah bilangan: ";
    cin >> bilangan;

    if (bilangan <= 1) {
        Prima = false;
    } else {
        for (i = 2; i <= bilangan / 2; i++) {
            if (bilangan % i == 0) {
                Prima = false;
                break;
            }
            
        }
    }

    if (Prima) {
        cout << bilangan << " adalah bilangan prima." << endl;
    } else {
        cout << bilangan << " bukan bilangan prima." << endl;
    }

    return 0;
}