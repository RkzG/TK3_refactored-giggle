#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Pegawai
{
    string nomorInduk;
    string nama;
    string alamat;
    string noHp;
    string jabatan;
    string golongan;
    float gaji;
};

float calculateSalary(const string& golongan) {
    if (golongan == "D1") {
        return 2500000;
    }else if(golongan == "D2") {
        return 200000;
    }else if(golongan == "D3") {
        return 1500000;
    }else {
        return 0;
    }
}


int kalkulator() {
    const int threshold = 100000;
    // Diskon diberikan berdasarkan harga sebelum diskon
    int nilai_belanja;
    std::cout << "Masukkan nilai belanja: ";
    std::cin >> nilai_belanja;

    int jumlah_voucher;
    if (nilai_belanja >= threshold) {
        jumlah_voucher = nilai_belanja / threshold;

        const int nilai_diskon =  int(0.05*nilai_belanja);
        printf("Anda mendapat %d voucher \n", jumlah_voucher);
        printf("Anda mendapat diskon 5%% sebesar Rp%d \n",nilai_diskon);
        printf("Tagihan akhir Anda sebesar Rp%d \n", nilai_belanja- nilai_diskon);
    }
    return 0;
}

int payroll() {
    Pegawai pegawai;

    getline(cin, pegawai.nomorInduk);//Tidak dihapus karena sudah menggunakan getline tetapi fungsi dari getline nya tidak bisa membuat baris baru,dan jika dihapus membuat NIP dan nama menjadi 1 line

    cout << "Nip =";
    getline(cin, pegawai.nomorInduk);

    cout << "Nama =";
    getline(cin, pegawai.nama);

    cout << "Alamat =";
    getline(cin, pegawai.alamat); 

    cout << "No HP =";
    getline(cin, pegawai.noHp);

    cout << "Jabatan =";
    getline(cin, pegawai.jabatan);

    cout << "Golongan =";
    getline(cin, pegawai.golongan);

    
    pegawai.gaji = calculateSalary(pegawai.golongan);

   
    if (pegawai.gaji == 0) {
        cout << "Golongan tidak valid!" << endl;
    } else {
        cout << "\nGaji Bulanan" << endl;
        cout << "Nip = " << pegawai.nomorInduk << endl;
        cout << "Nama =" << pegawai.nama << endl;
        cout << "Alamat = " << pegawai.alamat << endl;
        cout << "No HP =" << pegawai.noHp << endl;
        cout << "Jabatan =" << pegawai.jabatan << endl;
        cout << "Golongan = " << pegawai.golongan << endl;
        cout << fixed << setprecision(0);
        cout << "Gaji = Rp" << pegawai.gaji << endl;
    }
    return 0;
}

int main() {

    int soal;
    std::cout << "Masukkan Soal yang ingin dijalankan (1 / 2): ";
    std::cin >> soal;

    if (soal == 1) {
        return kalkulator();
    }

    if (soal == 2) {
        return payroll();
    }

    std::cout << "Hanya bisa pilih 1 atau 2 ";
    return 1;
}
