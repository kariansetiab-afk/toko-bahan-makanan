#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

// ==========================
// CLASS BARANG
// ==========================
class Barang {
public:
    string nama;
    int harga;

    Barang(string nama, int harga) {
        this->nama = nama;
        this->harga = harga;
    }
};

// ==========================
// CLASS TRANSAKSI
// ==========================
class Transaksi {
public:
    vector<Barang> daftarBarang;

    void tambahBarang(const Barang& barang) {
        if (barang.harga < 0) {
            throw runtime_error("Harga tidak boleh negatif");
        }
        daftarBarang.push_back(barang);
    }

    int hitungTotal() {
        int total = 0;
        for (size_t i = 0; i < daftarBarang.size(); i++) {
            total += daftarBarang[i].harga;
        }
        return total;
    }

    void tampilkanStruk() {
        cout << "=== STRUK BELANJA ===" << endl;
        for (size_t i = 0; i < daftarBarang.size(); i++) {
            cout << daftarBarang[i].nama << " : Rp"
                 << daftarBarang[i].harga << endl;
        }
        cout << "----------------------" << endl;
        cout << "TOTAL : Rp" << hitungTotal() << endl;
    }
};

// ==========================
// UNIT TEST
// ==========================
void testHitungTotal() {
    Transaksi transaksi;
    transaksi.tambahBarang(Barang("Beras", 10000));
    transaksi.tambahBarang(Barang("Gula", 5000));

    int hasil = transaksi.hitungTotal();

    if (hasil == 15000) {
        cout << "Unit Test Total Belanja: PASS" << endl;
    } else {
        cout << "Unit Test Total Belanja: FAIL" << endl;
    }
}

void testInputBarang() {
    try {
        Transaksi transaksi;
        transaksi.tambahBarang(Barang("Minyak", 20000));
        cout << "Unit Test Input Barang: PASS" << endl;
    } catch (...) {
        cout << "Unit Test Input Barang: FAIL" << endl;
    }
}

// ==========================
// INTEGRATION TEST
// ==========================
void integrationTest() {
    try {
        Transaksi transaksi;

        transaksi.tambahBarang(Barang("Telur", 12000));
        transaksi.tambahBarang(Barang("Susu", 15000));

        int total = transaksi.hitungTotal();

        transaksi.tampilkanStruk();

        if (total == 27000) {
            cout << "Integration Test Toko: PASS" << endl;
        } else {
            cout << "Integration Test Toko: FAIL" << endl;
        }
    } catch (...) {
        cout << "Integration Test Toko: FAIL" << endl;
    }
}

// ==========================
// MAIN
// ==========================
int main() {
    testHitungTotal();
    testInputBarang();
    integrationTest();
    return 0;
}
