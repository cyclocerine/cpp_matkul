#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int pilihanRasa, pilihanTopping, pilihanUkuran, jumlahPesanan, member;
    double hargaRasa, hargaTopping, hargaUkuran, totalHarga, diskon, totalBayar;
    string namaRasa, namaTopping, namaUkuran;
    const double DISKON_MEMBER = 0.05;

    cout << "Selamat datang di KuCool Es Krim!" << endl;
    cout << "==================================" << endl;

    cout << "Pilih Rasa Es Krim:" << endl;
    cout << "1. Vanilla - Rp 10.000" << endl;
    cout << "2. Cokelat - Rp 12.000" << endl;
    cout << "3. Stroberi - Rp 15.000" << endl;
    cout << "Masukkan pilihan rasa (1-3): ";
    cin >> pilihanRasa;

    switch (pilihanRasa) {
        case 1:
            namaRasa = "Vanilla";
            hargaRasa = 10000;
            break;
        case 2:
            namaRasa = "Cokelat";
            hargaRasa = 12000;
            break;
        case 3:
            namaRasa = "Stroberi";
            hargaRasa = 15000;
            break;
        default:
            cout << "Pilihan rasa tidak valid. Program keluar." << endl;
            return 1;
    }
    system("clear"); 

    cout << "\nPilih Topping:" << endl;
    cout << "1. Cokelat Chips - Rp 3.000" << endl;
    cout << "2. Kacang Almond - Rp 4.000" << endl;
    cout << "3. Oreo Crumbs - Rp 3.500" << endl;
    cout << "4. Tanpa topping - Rp 0" << endl;
    cout << "Masukkan pilihan topping (1-4): ";
    cin >> pilihanTopping;

    switch (pilihanTopping) {
        case 1:
            namaTopping = "Cokelat Chips";
            hargaTopping = 3000;
            break;
        case 2:
            namaTopping = "Kacang Almond";
            hargaTopping = 4000;
            break;
        case 3:
            namaTopping = "Oreo Crumbs";
            hargaTopping = 3500;
            break;
        case 4:
            namaTopping = "Tanpa topping";
            hargaTopping = 0;
            break;
        default:
            cout << "Pilihan topping tidak valid. Program keluar." << endl;
            return 1;
    }
    system("clear");

    cout << "\nPilih Ukuran Cup:" << endl;
    cout << "1. Small - harga normal" << endl;
    cout << "2. Medium - tambahan Rp 2.000" << endl;
    cout << "3. Large - tambahan Rp 5.000" << endl;
    cout << "Masukkan pilihan ukuran (1-3): ";
    cin >> pilihanUkuran;

    if (pilihanUkuran == 1) {
        namaUkuran = "Small";
        hargaUkuran = 0;
    } else if (pilihanUkuran == 2) {
        namaUkuran = "Medium";
        hargaUkuran = 2000;
    } else if (pilihanUkuran == 3) {
        namaUkuran = "Large";
        hargaUkuran = 5000;
    } else {
        cout << "Pilihan ukuran tidak valid. Program keluar." << endl;
        return 1;
    }

    cout << "\nMasukkan jumlah pesanan: ";
    cin >> jumlahPesanan;

    totalHarga = (hargaRasa + hargaTopping + hargaUkuran) * jumlahPesanan;

    if (totalHarga >= 100000) {
        diskon = 0.20;
    } else if (totalHarga >= 50000) {
        diskon = 0.10;
    } else if (totalHarga >= 30000) {
        diskon = 0.05;
    } else {
        diskon = 0;
    }

    cout << "\nApakah pelanggan adalah member? (1=Ya, 0=Tidak): ";
    cin >> member;
    if (member == 1) {
        diskon += DISKON_MEMBER;
    }

    totalBayar = totalHarga - (totalHarga * diskon);
    cout << "\n==================================" << endl;
    cout << "            STRUK PEMBELIAN        " << endl;
    cout << "==================================" << endl;
    cout << "Rasa Es Krim  : " << namaRasa << endl;
    cout << "Topping       : " << namaTopping << endl;
    cout << "Ukuran Cup    : " << namaUkuran << endl;
    cout << "Jumlah Pesanan: " << jumlahPesanan << endl;
    cout << "----------------------------------" << endl;
    cout << "Harga         : Rp " << totalHarga << endl;
    cout << "Diskon        : " << (diskon * 100) << "%" << endl;
    cout << "----------------------------------" << endl;
    cout << "Total Bayar   : Rp " << totalBayar << endl;
    cout << "==================================" << endl;

    return 0;
}
