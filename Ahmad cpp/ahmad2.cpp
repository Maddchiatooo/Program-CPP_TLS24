#include <iostream>
#include <cmath>
#include <limits>  // Untuk std::numeric_limits

using namespace std;

int main() {
    float bore, stroke, silinder, cc;
    const float PI = 3.1416;
    string jenis_kendaraan;
    bool ulangi = true;

    while (ulangi) {
        // Input jenis kendaraan
        cout << "Masukkan jenis kendaraan (mobil/motor): ";
        cin >> jenis_kendaraan;

        // Mengubah jenis kendaraan menjadi lowercase untuk perbandingan case-insensitive
        for (char &c : jenis_kendaraan) {
            c = tolower(c);
        }

        // Validasi jenis kendaraan
        if (jenis_kendaraan != "mobil" && jenis_kendaraan != "motor") {
            cout << "Jenis kendaraan tidak valid. Program akan dimulai kembali.\n\n";
            continue;
        }

        // Input diameter bore, panjang stroke, dan jumlah silinder
        cout << "Masukkan diameter bore (mm): ";
        while (!(cin >> bore) || bore <= 0) {
            cout << "Input tidak valid. Masukkan angka positif untuk diameter bore (mm): ";
            cin.clear(); // Menghapus flag kesalahan
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan sisa input
        }

        cout << "Masukkan panjang stroke (mm): ";
        while (!(cin >> stroke) || stroke <= 0) {
            cout << "Input tidak valid. Masukkan angka positif untuk panjang stroke (mm): ";
            cin.clear(); // Menghapus flag kesalahan
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan sisa input
        }

        cout << "Masukkan jumlah silinder: ";
        while (!(cin >> silinder) || silinder <= 0) {
            cout << "Input tidak valid. Masukkan angka positif untuk jumlah silinder: ";
            cin.clear(); // Menghapus flag kesalahan
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan sisa input
        }

        // Penghitungan CC
        cc = PI * pow(bore / 2.0, 2) * stroke * silinder / 1000.0;

        cout << "Kapasitas mesin: " << cc << " CC\n";

        // Penentuan SIM
        if (jenis_kendaraan == "motor") {
            if (cc < 250) {
                cout << "SIM C\n";
            } else if (cc <= 500) {
                cout << "SIM C1\n";
            } else {
                cout << "SIM C2\n";
            }
        } else { // mobil
            if (cc <= 6000) {
                cout << "SIM A\n";
            } else {
                cout << "Kapasitas mesin terlalu besar\n";
            }
        }

        ulangi = false; // Mengakhiri loop setelah input valid
    }

    return 0;
}
