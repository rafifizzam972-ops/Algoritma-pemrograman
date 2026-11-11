#include <iostream>

using namespace std;

int HitungTotal(int *arr, int n)
{
    if (n <= 0)
        return 0;

    return arr[n - 1] + HitungTotal(arr, n - 1);
}

int NilaiTerbesar(int *arr, int n)
{
    int nilaiTerbesar = arr[0];
    if (n <= 1)
        return nilaiTerbesar;
    
    for (int i = 1; i < n; i++)
    {
        if (nilaiTerbesar < arr[i])
            nilaiTerbesar = arr[i];
    }
    return nilaiTerbesar;
}

int NilaiTerkecil(int *arr, int n)
{
    int nilaiTerbesar = arr[0];
    if (n <= 1)
        return nilaiTerbesar;
    
    for (int i = 1; i < n; i++)
    {
        if (nilaiTerbesar > arr[i])
            nilaiTerbesar = arr[i];
    }
    return nilaiTerbesar;
}

int main()
{
    int jumlahMahasiswa = 0;
    while (jumlahMahasiswa <= 0)
    {
        cout << "Masukkan Jumlah Mahasiswa : ";
        cin >> jumlahMahasiswa;
        if (jumlahMahasiswa <= 0)
            cout << "Jumlah mahasiswa tidak valid!!" << endl;
    }

    int *arrNilaiMahasiswa = new int[jumlahMahasiswa];
    cout << "Masukkan nilai mahasiswa" << endl;
    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        cout << "Mahasiswa " << i + 1 << " : ";
        cin >> arrNilaiMahasiswa[i];
    }

    cout << endl;
    cout << "Nilai terbesar : " << NilaiTerbesar(arrNilaiMahasiswa, jumlahMahasiswa) << endl;
    cout << "Nilai terkecil : " << NilaiTerkecil(arrNilaiMahasiswa, jumlahMahasiswa) << endl;
    cout << "Rata-rata nilai: " << HitungTotal(arrNilaiMahasiswa, jumlahMahasiswa)/jumlahMahasiswa << endl;

    return 0;
}
