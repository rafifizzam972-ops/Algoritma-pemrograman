#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int baris;
    int kolom;

        cout << "masukkan jumlah baris Matrix : ";
        cin >> baris;
        cout << "masukkan jumlah kolom Matrix : ";
        cin >> kolom;

    int matrix[baris][kolom];
    int matrixTranspose[kolom][baris];
    cout << "Matrix (" << baris << "x" << kolom << ") :" << endl;
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            cout << "Masukkan nilai Matrix [" << i << "][" << j << "] : ";
            cin >> matrix[i][j];
            matrixTranspose[j][i] = matrix[i][j];
        }
    }
    cout << endl;

    cout << "Matrix asli: " << endl;
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
        cout << endl;

        cout << "Matrix transpose: " << endl;
    for (int i = 0; i < kolom; i++)
    {
        for (int j = 0; j <baris; j++)
        {
            cout << matrixTranspose[i][j] << " ";
        }
        cout << endl;
    }
        cout << endl;
    return 0;
}