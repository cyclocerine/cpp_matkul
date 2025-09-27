#include <iostream>

using namespace std;

int main() {
    int pilihan;
    char lanjut = 'y';

    while (lanjut == 'y' || lanjut == 'Y') {
        cout << "\n==================" << endl;
        cout << "       Menu       " << endl;
        cout << "==================" << endl;
        cout << "1. Anak Ayam" << endl;
        cout << "2. Bilangan Ganjil" << endl;
        cout << "3. Jumlah digit" << endl;
        cout << "4. Exit" << endl;
        cout << "==================" << endl;
        
        cout << "Pilih menu (1-4): ";

        if (!(cin >> pilihan)) {
            cout << "Input tidak valid. Silakan masukkan angka pilihan (1-4)." << endl;
            cin.clear(); 
            char opt;
            while (cin.get(opt) && opt != '\n');
            continue;
        }
        
        char opt;
        while (cin.get(opt) && opt != '\n');

        switch (pilihan) {
            case 1: {
                cout << "\nMenu 1:" << endl;
                int jumlahAyam;
                cout << "Masukkan jumlah anak ayam: ";
                
                if (!(cin >> jumlahAyam) || jumlahAyam < 1) {
                    cout << "Input tidak valid. Silakan masukkan angka positif." << endl;
                    cin.clear();
                    while (cin.get(opt) && opt != '\n');
                    break;
                }
                while (cin.get(opt) && opt != '\n');

                cout << "Anak ayam ada " << jumlahAyam << endl;

                for (int i = jumlahAyam - 1; i >= 0; --i) {
                    if (i > 0) {
                        cout << "Mati satu tinggal " << i << endl;
                    } else {
                        cout << "Mati satu sisa induknya" << endl;
                    }
                }
                break;
            }
            case 2: {
                cout << "\nMenu 2:" << endl;
                int angkaAkhir;
                cout << "Masukkan angka akhir: ";

                if (!(cin >> angkaAkhir) || angkaAkhir < 1) {
                    cout << "Input tidak valid. Silakan masukkan angka positif." << endl;
                    cin.clear();
                    while (cin.get(opt) && opt != '\n'); 
                    break;
                }
                while (cin.get(opt) && opt != '\n');
                
                for (int i = 1; i <= angkaAkhir; i += 2) {
                    cout << i << " ";
                }
                cout << endl;
                break;
            }
            case 3: {
                cout << "\nMenu 3:" << endl;
                long long angka;
                int hitung = 0;
                cout << "Masukkan angka: ";
                
                if (!(cin >> angka)) {
                    cout << "Input tidak valid." << endl;
                    cin.clear();
                    while (cin.get(opt) && opt != '\n'); 
                    break;
                }
                while (cin.get(opt) && opt != '\n');

                if (angka == 0) {
                    hitung = 1;
                } else {
                    long long optAngka = angka;
                    if (optAngka < 0) {
                        optAngka = -optAngka;
                    }
                    
                    while (optAngka > 0) {
                        optAngka /= 10;
                        hitung++;
                    }
                }
                
                cout << "Ada " << hitung << " digit" << endl;
                break;
            }
            case 4:
                cout << "Keluar dari program. Terima kasih." << endl;
                lanjut = 'n';
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih 1, 2, 3, atau 4." << endl;
                break;
        }

        if (lanjut != 'n') {
            cout << "\nLanjut? (y/n): ";
            cin >> lanjut;
            while (cin.get(opt) && opt != '\n');
        }
    }

    return 0;
}