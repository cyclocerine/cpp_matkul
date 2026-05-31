#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Ini struct buat nyimpen data misi shinobi, wajib dipake biar dapet nilai
struct Misi {
    string namaShinobi;
    char rank; // D, C, B, A, atau S
    int tahun;
    string namaMisi;
};

// Prototipe fungsi biar programnya modular, disuruh asdos biar dapet nilai plus
void tampilkanMenu(string fileAktif);
int bacaFile(string namaFile, Misi data[]);
void tulisFile(string namaFile, Misi data[], int jumlahData, bool appendMode);
void tambahMisi(string fileAktif);
void tampilMisi(string fileAktif);
void cariShinobi(string fileAktif);
void urutkanMisi(string fileAktif);
void statistikMisi(string fileAktif);
void gantiFile(string &fileAktif);

// Fungsi buatan sendiri buat bikin huruf besar semua, biar searchingnya ga sensitif
string keUpper(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

int main() {
    // File default pas pertama kali jalan, sesuai petunjuk soal
    string fileAktif = "arsip_konoha.txt";
    int pilihan;

    do {
        tampilkanMenu(fileAktif);
        cout << "Pilih Menu : ";
        
        // Validasi input menu biar ga nge-bug kalo user typo masukin huruf
        if (!(cin >> pilihan)) {
            cout << "\nInput salah! Masukkan angka saja.\n";
            cin.clear();
            cin.ignore(100, '\n');
            system("pause");
            continue;
        }
        cin.ignore(); // Bersihin buffer cin biar getline di bawahnya ga ke-skip

        switch (pilihan) {
            case 1:
                tambahMisi(fileAktif);
                break;
            case 2:
                tampilMisi(fileAktif);
                break;
            case 3:
                cariShinobi(fileAktif);
                break;
            case 4:
                urutkanMisi(fileAktif);
                break;
            case 5:
                statistikMisi(fileAktif);
                break;
            case 6:
                gantiFile(fileAktif);
                break;
            case 7:
                cout << "\n=========================================\n";
                cout << "Program selesai. Sampai jumpa, Hokage!\n";
                cout << "=========================================\n";
                break;
            default:
                cout << "\nPilihan menu tidak ada! Silakan coba lagi.\n";
                system("pause");
                break;
        }
    } while (pilihan != 7);

    return 0;
}

// Fungsi buat nampilin menu utama ke console
void tampilkanMenu(string fileAktif) {
    system("cls"); // Pake cls karena kita running di Windows
    cout << "=========================================\n";
    cout << "    SISTEM ARSIP MISI SHINOBI KONOHA\n";
    cout << "    File Aktif : " << fileAktif << "\n";
    cout << "=========================================\n";
    cout << "1. Tambah Data Misi\n";
    cout << "2. Tampilkan Data\n";
    cout << "3. Cari Shinobi (Binary Search)\n";
    cout << "4. Urutkan Data (Selection Sort)\n";
    cout << "5. Statistik Rank\n";
    cout << "6. Ganti File\n";
    cout << "7. Exit\n";
    cout << "=========================================\n";
}

// Fungsi buat ngambil data dari file txt, return-nya berupa jumlah data
int bacaFile(string namaFile, Misi data[]) {
    ifstream masuk(namaFile);
    if (!masuk.is_open()) {
        return 0; // Kalo file belum dibikin, return 0 data dulu
    }

    int i = 0;
    string tempNama, tempMisi, tempRank, tempTahun;

    // Baca file baris demi baris biar spasi di nama ato misi ga bikin rusak program
    while (getline(masuk, tempNama)) {
        if (tempNama == "") continue; // Skip baris kosong buat jaga-jaga
        
        data[i].namaShinobi = tempNama;
        
        getline(masuk, tempRank);
        data[i].rank = tempRank[0];
        
        getline(masuk, tempTahun);
        data[i].tahun = stoi(tempTahun); // convert string ke integer biasa
        
        getline(masuk, tempMisi);
        data[i].namaMisi = tempMisi;
        
        i++;
    }

    masuk.close();
    return i; // Balikin total data yang berhasil dibaca dari file
}

// Fungsi buat nulis/nyimpen array struct ke dalam file txt
void tulisFile(string namaFile, Misi data[], int jumlahData, bool appendMode) {
    ofstream keluar;
    if (appendMode) {
        keluar.open(namaFile, ios::app); // Tambah data baru di paling bawah file
    } else {
        keluar.open(namaFile, ios::trunc); // Timpa isi file lama (buat nyimpen hasil sort)
    }

    if (!keluar.is_open()) {
        cout << "Gagal membuka file buat nulis data!\n";
        return;
    }

    for (int i = 0; i < jumlahData; i++) {
        keluar << data[i].namaShinobi << "\n";
        keluar << data[i].rank << "\n";
        keluar << data[i].tahun << "\n";
        keluar << data[i].namaMisi << "\n";
    }

    keluar.close();
}

// Menu 1: Tambah data misi secara dinamis terus disimpen ke file
void tambahMisi(string fileAktif) {
    int jumlah;
    cout << "\nJumlah data yang ditambahkan: ";
    cin >> jumlah;
    cin.ignore();

    // Pake array lokal biasa aja, di-set max 100 biar aman ga overfow
    Misi dataBaru[100]; 

    for (int i = 0; i < jumlah; i++) {
        cout << "=== DATA KE-" << (i + 1) << " ===\n";
        
        cout << "Nama Shinobi : ";
        getline(cin, dataBaru[i].namaShinobi);

        // Validasi input rank biar user ga ngasal masukin selain S/A/B/C/D
        while (true) {
            cout << "Rank (D/C/B/A/S): ";
            cin >> dataBaru[i].rank;
            dataBaru[i].rank = toupper(dataBaru[i].rank);
            if (dataBaru[i].rank == 'S' || dataBaru[i].rank == 'A' || 
                dataBaru[i].rank == 'B' || dataBaru[i].rank == 'C' || dataBaru[i].rank == 'D') {
                break;
            }
            cout << "Rank salah! Masukkan rank yang bener.\n";
        }

        cout << "Tahun Misi   : ";
        cin >> dataBaru[i].tahun;
        cin.ignore(); // Bersihin buffer cin setelah input angka biar getline ga kelewat

        cout << "Nama Misi    : ";
        getline(cin, dataBaru[i].namaMisi);
        cout << "\n";
    }

    // Tulis ke file dengan mode append biar numpuk di bawah
    tulisFile(fileAktif, dataBaru, jumlah, true);
    cout << "Data berhasil disimpan.\n";
    system("pause");
}

// Menu 2: Nampilin semua isi arsip yang ada di file aktif
void tampilMisi(string fileAktif) {
    Misi listMisi[500];
    int total = bacaFile(fileAktif, listMisi);

    cout << "\n=========================================\n";
    cout << "               DAFTAR MISI               \n";
    cout << "=========================================\n";

    if (total == 0) {
        cout << "[ Arsip Kosong / Belum Ada Data ]\n";
    } else {
        for (int i = 0; i < total; i++) {
            cout << "Data #" << (i + 1) << "\n";
            cout << "Nama Shinobi : " << listMisi[i].namaShinobi << "\n";
            cout << "Rank Misi    : " << listMisi[i].rank << "\n";
            cout << "Tahun        : " << listMisi[i].tahun << "\n";
            cout << "Nama Misi    : " << listMisi[i].namaMisi << "\n";
            cout << "-----------------------------------------\n";
        }
    }
    system("pause");
}

// Menu 3: Cari Shinobi pake Binary Search
void cariShinobi(string fileAktif) {
    Misi listMisi[500];
    int total = bacaFile(fileAktif, listMisi);

    if (total == 0) {
        cout << "\nArsip kosong! Gak ada data yang bisa dicari.\n";
        system("pause");
        return;
    }

    // Syarat Binary Search: Data wajib diurutin dulu (pake selection sort berdasarkan Nama)
    for (int i = 0; i < total - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < total; j++) {
            if (keUpper(listMisi[j].namaShinobi) < keUpper(listMisi[minIdx].namaShinobi)) {
                minIdx = j;
            }
        }
        // Swap elemen struct-nya
        Misi temp = listMisi[i];
        listMisi[i] = listMisi[minIdx];
        listMisi[minIdx] = temp;
    }

    string cariNama;
    cout << "\nMasukkan nama shinobi: ";
    getline(cin, cariNama);

    // Proses Binary Search standar, nyari indeks tengahnya terus
    int low = 0;
    int high = total - 1;
    int ketemuIdx = -1;
    string namaCariUpper = keUpper(cariNama);

    while (low <= high) {
        int mid = (low + high) / 2;
        string namaMidUpper = keUpper(listMisi[mid].namaShinobi);

        if (namaMidUpper == namaCariUpper) {
            ketemuIdx = mid;
            break; // Udah ketemu langsung break aja
        } else if (namaMidUpper < namaCariUpper) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Kalo datanya ketemu, kita print (bisa handle kalo ada nama shinobi yang sama)
    if (ketemuIdx != -1) {
        cout << "\n=========================================\n";
        cout << "      HASIL PENCARIAN MISI SHINOBI       \n";
        cout << "=========================================\n";

        // Cari batas paling kiri dari nama yang sama biar keprint semua
        int kiri = ketemuIdx;
        while (kiri > 0 && keUpper(listMisi[kiri - 1].namaShinobi) == namaCariUpper) {
            kiri--;
        }

        // Cari batas paling kanan dari nama yang sama
        int kanan = ketemuIdx;
        while (kanan < total - 1 && keUpper(listMisi[kanan + 1].namaShinobi) == namaCariUpper) {
            kanan++;
        }

        // Cetak semua misi dari nama shinobi yang dicari tadi
        int no = 1;
        for (int i = kiri; i <= kanan; i++) {
            cout << "Misi #" << no++ << "\n";
            cout << "Nama Shinobi : " << listMisi[i].namaShinobi << "\n";
            cout << "Rank Misi    : " << listMisi[i].rank << "\n";
            cout << "Tahun        : " << listMisi[i].tahun << "\n";
            cout << "Nama Misi    : " << listMisi[i].namaMisi << "\n";
            cout << "-----------------------------------------\n";
        }
    } else {
        cout << "Shinobi tidak ditemukan.\n";
    }

    system("pause");
}

// Menu 4: Urutkan data pake Selection Sort sesuai perintah soal
void urutkanMisi(string fileAktif) {
    Misi listMisi[500];
    int total = bacaFile(fileAktif, listMisi);

    if (total == 0) {
        cout << "\nArsip kosong! Gak ada data yang bisa diurutkan.\n";
        system("pause");
        return;
    }

    cout << "\nPilihan Pengurutan:\n";
    cout << "1. Nama Shinobi (Ascending / A-Z)\n";
    cout << "2. Tahun Misi (Descending / Terbaru ke Terlama)\n";
    cout << "Pilih Jenis Urutan : ";
    int pilihanSort;
    cin >> pilihanSort;
    cin.ignore();

    // Logika algoritma Selection Sort dari slide kuliah alpro
    for (int i = 0; i < total - 1; i++) {
        int targetIdx = i;
        for (int j = i + 1; j < total; j++) {
            if (pilihanSort == 1) {
                // Ascending berdasarkan Nama Shinobi (A-Z)
                if (keUpper(listMisi[j].namaShinobi) < keUpper(listMisi[targetIdx].namaShinobi)) {
                    targetIdx = j;
                }
            } else if (pilihanSort == 2) {
                // Descending berdasarkan Tahun Misi (Terbaru ke Terlama)
                if (listMisi[j].tahun > listMisi[targetIdx].tahun) {
                    targetIdx = j;
                }
            }
        }
        // Swap data elemen struct array-nya
        if (targetIdx != i) {
            Misi temp = listMisi[i];
            listMisi[i] = listMisi[targetIdx];
            listMisi[targetIdx] = temp;
        }
    }

    // Tampilkan data yang udah selesai di-sorting
    cout << "\n=========================================\n";
    cout << "              DATA TERURUT               \n";
    cout << "=========================================\n";
    for (int i = 0; i < total; i++) {
        cout << "Nama Shinobi : " << listMisi[i].namaShinobi << "\n";
        cout << "Rank Misi    : " << listMisi[i].rank << "\n";
        cout << "Tahun        : " << listMisi[i].tahun << "\n";
        cout << "Nama Misi    : " << listMisi[i].namaMisi << "\n";
        cout << "-----------------------------------------\n";
    }

    // Tulis balik hasil urutannya ke file biar permanen kesimpen yang rapi
    tulisFile(fileAktif, listMisi, total, false);
    cout << "Data berhasil diurutkan dan diperbarui di file!\n";
    system("pause");
}

// Menu 5: Statistik jumlah misi berdasarkan masing-masing Rank
void statistikMisi(string fileAktif) {
    Misi listMisi[500];
    int total = bacaFile(fileAktif, listMisi);

    int d = 0, c = 0, b = 0, a = 0, s = 0;

    // Loop buat ngitung jumlah masing-masing rank misi yang ketemu
    for (int i = 0; i < total; i++) {
        char r = toupper(listMisi[i].rank);
        if (r == 'D') d++;
        else if (r == 'C') c++;
        else if (r == 'B') b++;
        else if (r == 'A') a++;
        else if (r == 'S') s++;
    }

    cout << "\n=========================================\n";
    cout << "             STATISTIK MISI              \n";
    cout << "=========================================\n";
    cout << "Total Misi : " << total << "\n";
    cout << "Rank D : " << d << "\n";
    cout << "Rank C : " << c << "\n";
    cout << "Rank B : " << b << "\n";
    cout << "Rank A : " << a << "\n";
    cout << "Rank S : " << s << "\n";
    cout << "=========================================\n";

    system("pause");
}

// Menu 6: Mengganti nama file arsip aktif saat program jalan
void gantiFile(string &fileAktif) {
    string fileBaru;
    cout << "\nFile saat ini      : " << fileAktif << "\n";
    cout << "Masukkan nama file baru : ";
    getline(cin, fileBaru);

    // Otomatis tambahin ekstensi .txt kalo semisal user kelupaan ngetik
    if (fileBaru.length() < 4 || fileBaru.substr(fileBaru.length() - 4) != ".txt") {
        fileBaru += ".txt";
    }

    fileAktif = fileBaru;
    cout << "File aktif berhasil diganti menjadi " << fileAktif << "\n";
    system("pause");
}