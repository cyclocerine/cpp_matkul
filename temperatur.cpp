#include <iostream>
using namespace std;

int main() {
    float celcius, f;
    cout << "konversi celsius ke fahrenheit ";
    cout << "masukan temperatur dalam celsius ";
    cin >> celcius;
    f = (celcius * 9/5)+32;
    cout << celcius << " adalah "<< f << " fahrenheit";
}
