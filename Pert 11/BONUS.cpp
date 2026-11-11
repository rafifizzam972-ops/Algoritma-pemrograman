
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int n = 0;
    int pilihan;

    string *namaProyekArr = new string[n];
    float *jumlahAnggaranArr = new float[n];
    int *jumlahPekerjaArr = new int[n];

    do
    {
        cout << "\n===== MANAJEMEN PROYEK =====\n";
        cout << "1. Tambah proyek\n";
        cout << "2. Hapus proyek\n";
        cout << "3. Tampilkan seluruh proyek\n";
        cout << "4. Statistik proyek\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
            // =========================
            // TAMBAH PROYEK
            // =========================
            case 1:
            {
                n++;

                string *namaTemp = new string[n];
                float *anggaranTemp = new float[n];
                int *pekerjaTemp = new int[n];

                for (int i = 0; i < n - 1; i++)
                {
                    namaTemp[i] = namaProyekArr[i];
                    anggaranTemp[i] = jumlahAnggaranArr[i];
                    pekerjaTemp[i] = jumlahPekerjaArr[i];
                }

                cout << "\nNama proyek: ";
                cin.ignore();
                getline(cin, namaTemp[n - 1]);

                do
                {
                    cout << "Anggaran proyek: ";
                    cin >> anggaranTemp[n - 1];

                    if (anggaranTemp[n - 1] < 0)
                    {
                        cout << "Anggaran tidak boleh negatif!\n";
                    }

                } while (anggaranTemp[n - 1] < 0);

                do
                {
                    cout << "Jumlah pekerja: ";
                    cin >> pekerjaTemp[n - 1];

                    if (pekerjaTemp[n - 1] < 0)
                    {
                        cout << "Jumlah pekerja tidak boleh negatif!\n";
                    }

                } while (pekerjaTemp[n - 1] < 0);

                delete[] namaProyekArr;
                delete[] jumlahAnggaranArr;
                delete[] jumlahPekerjaArr;

                namaProyekArr = namaTemp;
                jumlahAnggaranArr = anggaranTemp;
                jumlahPekerjaArr = pekerjaTemp;

                cout << "Proyek berhasil ditambahkan!\n";

                break;
            }

            // =========================
            // HAPUS PROYEK
            // =========================
            case 2:
            {
                if (n == 0)
                {
                    cout << "Belum ada proyek!\n";
                    break;
                }

                cout << "\nDaftar proyek:\n";

                for (int i = 0; i < n; i++)
                {
                    cout << i + 1 << ". "
                         << namaProyekArr[i] << endl;
                }

                int indeks;

                cout << "Masukkan nomor proyek yang dihapus: ";
                cin >> indeks;

                if (indeks < 1 || indeks > n)
                {
                    cout << "Nomor proyek tidak valid!\n";
                    break;
                }

                string *namaTemp = new string[n - 1];
                float *anggaranTemp = new float[n - 1];
                int *pekerjaTemp = new int[n - 1];

                for (int i = 0, j = 0; i < n; i++)
                {
                    if (i == indeks - 1)
                    {
                        continue;
                    }

                    namaTemp[j] = namaProyekArr[i];
                    anggaranTemp[j] = jumlahAnggaranArr[i];
                    pekerjaTemp[j] = jumlahPekerjaArr[i];

                    j++;
                }

                delete[] namaProyekArr;
                delete[] jumlahAnggaranArr;
                delete[] jumlahPekerjaArr;

                namaProyekArr = namaTemp;
                jumlahAnggaranArr = anggaranTemp;
                jumlahPekerjaArr = pekerjaTemp;

                n--;

                cout << "Proyek berhasil dihapus!\n";

                break;
            }

            // =========================
            // TAMPILKAN PROYEK
            // =========================
            case 3:
            {
                if (n == 0)
                {
                    cout << "Belum ada proyek!\n";
                    break;
                }

                cout << "\n===== DAFTAR PROYEK =====\n";

                for (int i = 0; i < n; i++)
                {
                    cout << "\nProyek ke-" << i + 1 << endl;
                    cout << "Nama     : " << namaProyekArr[i] << endl;

                    cout << "Anggaran : Rp "
                         << fixed << setprecision(2)
                         << jumlahAnggaranArr[i] << endl;

                    cout << "Pekerja  : "
                         << jumlahPekerjaArr[i] << endl;
                }

                break;
            }

            // =========================
            // STATISTIK PROYEK
            // =========================
            case 4:
            {
                if (n == 0)
                {
                    cout << "Belum ada proyek untuk dihitung!\n";
                    break;
                }

                float totalAnggaran = 0;
                float rataPekerja = 0;

                int indeksTerbesar = 0;

                for (int i = 0; i < n; i++)
                {
                    totalAnggaran += jumlahAnggaranArr[i];
                    rataPekerja += jumlahPekerjaArr[i];

                    if (jumlahAnggaranArr[i] >
                        jumlahAnggaranArr[indeksTerbesar])
                    {
                        indeksTerbesar = i;
                    }
                }

                rataPekerja /= n;

                cout << "\n===== STATISTIK PROYEK =====\n";

                cout << "Total anggaran : Rp "
                     << fixed << setprecision(2)
                     << totalAnggaran << endl;

                cout << "Rata-rata pekerja : "
                     << rataPekerja << endl;

                cout << "Anggaran terbesar : Rp "
                     << jumlahAnggaranArr[indeksTerbesar]
                     << endl;

                cout << "Nama proyek terbesar : "
                     << namaProyekArr[indeksTerbesar]
                     << endl;

                break;
            }

            case 0:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    delete[] namaProyekArr;
    delete[] jumlahAnggaranArr;
    delete[] jumlahPekerjaArr;

    return 0;
}
