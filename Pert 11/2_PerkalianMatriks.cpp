#include <iostream>

using namespace std;

int main()
{
    int barisA;
    int kolomA;
    int barisB;
    int kolomB;

    do
    {
        cout << "masukkan jumlah baris Matrix A : ";
        cin >> barisA;
        cout << "masukkan jumlah kolom Matrix A : ";
        cin >> kolomA;
        cout << "masukkan jumlah baris Matrix B : ";
        cin >> barisB;
        cout << "(harus sama dengan Baris A)" << endl;
        cout << "masukkan jumlah kolom Matrix B : ";
        cin >> kolomB;
        if (barisA != kolomB)
        {
            cout << "Ukuran matrix tidak valid!!!" << endl;
            cout << "Baris A harus sama dengan KolomB !" << endl;
        }
    } while (barisA != kolomB);

    int matrixA[barisA][kolomA];
    cout << "Matrix A (" << barisA << "x" << kolomA << ") :" << endl;
    for (int i = 0; i < barisA; i++)
    {
        for (int j = 0; j < kolomA; j++)
        {
            cout << "Masukkan nilai Matrix A [" << i << "][" << j << "] : ";
            cin >> matrixA[i][j];
        }
    }
    cout << endl;

    int matrixB[barisB][kolomB];
    cout << "Matrix B (" << barisB << "x" << kolomB << ") :" << endl;
    for (int i = 0; i < barisB; i++)
    {
        for (int j = 0; j < kolomB; j++)
        {
            cout << "Masukkan nilai Matrix B [" << i << "][" << j << "] : ";
            cin >> matrixB[i][j];
        }
    }
    cout << endl;

    int matrixHasil[barisA][kolomB];
    for (int i = 0; i < barisA; i++)
    {
        for (int j = 0; j < kolomB; j++)
        {
            int total = 0;
            for (int k = 0; k < barisB; k++)
            {
                total += matrixA[i][k] * matrixB[k][j];
            }
            matrixHasil[i][j] = total;
        }
    }

    cout << "Matrix A: " << endl;
    for (int i = 0; i < barisA; i++)
    {
        for (int j = 0; j < kolomA; j++)
        {
            cout << matrixA[i][j] << " ";
        }
        cout << endl;
    }
        cout << endl;

    cout << "Matrix B : " << endl;
    for (int i = 0; i < barisB; i++)
    {
        for (int j = 0; j < kolomB; j++)
        {
            cout << matrixB[i][j] << " ";
        }
        cout << endl;
    }
        cout << endl;

    cout << "Hasil Perkalian Matrix A dan B : " << endl;
    for (int i = 0; i < barisA; i++)
    {
        for (int j = 0; j < kolomB; j++)
        {
            cout << matrixHasil[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}