#include <iostream>
#include <iomanip>

using namespace std;

float HitungTotalDanDiskon(float *arr, int n)
{
    if (n <= 0)
        return 0;

    if (arr[n - 1] > 500000)
        return arr[n - 1] * 90 / 100 + HitungTotalDanDiskon(arr, n - 1);
    else if (arr[n - 1] <= 500000 && arr[n - 1] >= 250000)
        return arr[n - 1] * 95 / 100 + HitungTotalDanDiskon(arr, n - 1);
    else
        return arr[n - 1] + HitungTotalDanDiskon(arr, n - 1);
}

int main()
{
    int jumlahBarang = 0;
    while (jumlahBarang <= 0)
    {
        cout << "Masukkan Jumlah Barang : ";
        cin >> jumlahBarang;
        if (jumlahBarang <= 0)
            cout << "Jumlah Barang tidak valid!!" << endl;
    }

    float *hargaBarangs = new float[jumlahBarang];

    for (int i = 0; i < jumlahBarang; i++)
    {
        cout << "Masukkan harga barang " << i + 1 << " : ";
        cin >> hargaBarangs[i];
    }

    for (int i = 0; i < jumlahBarang; i++)
    {
        if (hargaBarangs[i] > 500000)
            cout << "Diskon Barang ke-" << i + 1 << ": 10%" << endl;
        else if (hargaBarangs[i] <= 500000 && hargaBarangs[i] >= 250000)
            cout << "Diskon Barang ke-" << i + 1 << ": 5%" << endl;
        else
            cout << "Diskon Barang ke-" << i + 1 << ": Tidak Ada" << endl;
    }
    cout << endl;
    cout << "Total Harga Setelah Diskon : " << (int)HitungTotalDanDiskon(hargaBarangs, jumlahBarang);

    return 0;
}