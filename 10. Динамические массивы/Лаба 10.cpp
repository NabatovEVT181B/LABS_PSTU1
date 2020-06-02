#include <iostream>
using namespace std;

int main()
{
    int rows;
    int cols;

    cout << "ENTER ROWS COUNT: ";
    cin >> rows;
    cout << "ENTER COLUMNS COUNT: ";
    cin >> cols;


    int** mas = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        mas[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            mas[i][j] = rand() % 20;
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << mas[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;

    int delrow;
    int delcol;

    cout << "CHOOSE A ROW TO DELETE: ";
    cin >> delrow;
    cout << "CHOOSE A COLUMN TO DELETE: ";
    cin >> delcol;
    cout << endl;

    int** newmas = new int* [rows - 1];

    for (int i = 0; i < (rows - 1); i++)
    {
        newmas[i] = new int[cols - 1];
    }

    for (int i = 0; i < (rows - 1); i++)
    {
        for (int j = 0; j < (cols - 1); j++)
        {
            newmas[i][j] = rand() % 20;
        }
    }

    int row_jump = 0;
    int col_jump = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == delrow) {
                row_jump = 1;
            }
            if (j == delcol) {
                col_jump = 1;
            }
            else newmas[i - row_jump][j - col_jump] = mas[i][j];
        }
        col_jump = 0;
    }

    for (int i = 0; i < (rows - 1); i++)
    {
        for (int j = 0; j < (cols - 1); j++)
        {
            cout << newmas[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) 
    {
        delete[] mas[i];                                                    
    }

    delete[] mas;       

    for (int i = 0; i < (rows - 1); i++) {
        delete[] newmas[i];
    }

    delete[] newmas;

    mas = nullptr;
    newmas = nullptr;

    return 0;
}

