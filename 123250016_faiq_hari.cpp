#include <iostream>
using namespace std;

int main(){
    int hari;
    cout << "Masukkan angka (1-7) untuk hari dalam seminggu: ";
    cin >> hari;

    switch(hari){
        case 1:
            cout << "Hari ke-1 adalah Senin." << endl;
            break;
        case 2:
            cout << "Hari ke-2 adalah Selasa." << endl;
            break;
        case 3:
            cout << "Hari ke-3 adalah Rabu." << endl;
            break;
        case 4:
            cout << "Hari ke-4 adalah Kamis." << endl;
            break;
        case 5:
            cout << "Hari ke-5 adalah Jumat." << endl;
            break;
        case 6:
            cout << "Hari ke-6 adalah Sabtu." << endl;
            break;
        case 7:
            cout << "Hari ke-7 adalah Minggu." << endl;
            break;
        default:
            cout << "Input tidak valid. Masukkan angka antara 1 hingga 7." << endl;
    }

    return 0;
}