#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int jumlahProduk = 0;
    while (jumlahProduk <= 0)
    {
        cout << "Masukkan Jumlah Produk : ";
        cin >> jumlahProduk;
        if (jumlahProduk <= 0)
            cout << "Jumlah Produk tidak valid!!" << endl;
    }

    string namaProduks[jumlahProduk];
    int hargaProduks[jumlahProduk];
    int produkTerjuals[jumlahProduk];

    cout << "Masukkan data Produk (nama produk, harga satuan, jumlah terjual) : " << endl;
    for (int i = 0; i < jumlahProduk; i++)
    {
        cout << "PRODUK " << i + 1 << endl;
        cout << "Nama produk         : ";
        cin >> namaProduks[i];
        cout << "Harga satuan produk : ";
        cin >> hargaProduks[i];
        cout << "Jumlah terjual      : ";
        cin >> produkTerjuals[i];

        cout << endl;
    }

    int totalHarga = 0;
    int indexPendapatanTertinggi = 0;
    for (int i = 0; i < jumlahProduk; i++)
    {
        totalHarga += produkTerjuals[i] * hargaProduks[i];
        if (produkTerjuals[i] * hargaProduks[i] > produkTerjuals[indexPendapatanTertinggi] * hargaProduks[indexPendapatanTertinggi])
            indexPendapatanTertinggi = i;
    }

    cout << "Total Pendapatan                   : Rp." << totalHarga << endl;
    cout << "Rata-rata Pendapatan Per Produk    : Rp." << totalHarga / jumlahProduk << endl;
    cout << "Produk dengan Pendapatan Tertinggi : " << namaProduks[indexPendapatanTertinggi]
         << " (Rp." << produkTerjuals[indexPendapatanTertinggi] * hargaProduks[indexPendapatanTertinggi] << ")";

    return 0;
}