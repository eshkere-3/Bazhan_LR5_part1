#ifndef _BAZHAN_MATHTASK_H_
#define _BAZHAN_MATHTASK_H_

#include <iostream>
#include <limits> // для numeric_limits

using namespace std;

// Функция контроля ввода данных
int inputValidation() {
    int number;
    while (true) {
        cout << "Введите целое число: ";
        cin >> number;

        // Проверка на ошибки ввода
        if (cin.fail()) {
            cin.clear(); // сбрасываем состояние потока
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // игнорируем неверный ввод
            cout << "Ошибка: введите корректное целое число." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очищаем буфер
            return number;
        }
    }
}

// Метод ввода данных
void inputDimensions(int &length, int &width) {
    cout << "Введите длину прямоугольника: ";
    length = inputValidation();
    cout << "Введите ширину прямоугольника: ";
    width = inputValidation();
}

// Метод вычисления площади прямоугольника
int calculateArea(int length, int width) {
    return length * width;
}

#endif