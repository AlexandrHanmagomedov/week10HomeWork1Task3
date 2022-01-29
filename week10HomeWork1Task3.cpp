/*
Задание 3. Создайте двухмерный массив. Заполните его случайными числами и покажите на экран. Пользователь
выбирает количество сдвигов и положение (влево, вправо, вверх, вниз). Выполнить сдвиг массива и показать на
экран полученный результат. Сдвиг циклический.Например, если мы имеем следующий массив
1 2 0 4 5 3
4 5 3 9 0 1
и пользователь выбрал сдвиг на 2 разряда вправо, то мы получим
5 3 1 2 0 4
0 1 4 5 3 9
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(0));
    int smeshen = 1;
    int storona = 1;
    const int numRows = 5;
    const int numCols = 5;
    int i = 0, j = 0;
    unsigned int arr[numRows][numCols] = {};
    cout << "\nMassiv \n";
    for (int i = 0; i < numRows; ++i)  // строки
    {
        for (int j = 0; j < numCols; ++j)//колонки
        {
            arr[i][j] = rand() % 10;
            cout << "  ";
            cout << arr[i][j];
        }
        cout << "\n";
    }
    cout << "\n\tViberite kol-vo smesheniy \n";
    cin >> smeshen;

    cout << "\t1. Vverh\n\t2. Vniz\n\t3. Vlevo\n\t4. Vpravo\n";
    cin >> storona;

    int x = 0, y = 0;
    if (storona == 1) //вверх
    {
        smeshen %= numRows;
        x = 1;
        smeshen += numRows;
    }
    else if (storona == 2) //вниз
    {
        smeshen %= numRows;
        x = -1;
        smeshen -= numRows;
    }
    else if (storona == 3)//влево
    {
        smeshen %= numCols;
        y = 1;
        smeshen += numCols;
    }
    else if (storona == 4)//вправо
    {
        smeshen %= numCols;
        y = -1;
        smeshen -= numCols;
    }
    for (i = 0; i < numRows; i++)
    {
        for (j = 0; j < numCols; j++)
        {
            cout << "  ";
            cout << arr[(i + (smeshen * x)) % numRows][(j + (smeshen * y)) % numCols];
        }
        cout << endl;
    }

}