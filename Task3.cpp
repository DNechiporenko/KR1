#include <iostream>

using namespace std;

void show_array(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void find_sum(int* arr, int length, int zadsumma) {
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] + arr[j] == zadsumma) {
                cout << arr[i] << " " << arr[j] << endl;
            }
        }
    }
}

int main()
{
    int n;
    cout<< "Введите количество элементов массив: ";
    cin >> n; 
    int* arr = new int[n]; // создаем массив
    
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50 + 1;
    } // Заполняем массив рандомными числами от 1 до 50
    show_array(arr, n); // Выводим массив
    
    int zadsumma;
    cout << "Введите число, которому должна равняться сумма: ";
    cin >> zadsumma;
    find_sum(arr, n, zadsumma);
    delete[] arr;
    return 0;
}
