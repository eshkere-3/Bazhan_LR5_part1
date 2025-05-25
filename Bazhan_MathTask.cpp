#include <iostream>
#include "Bazhan_MathTask.h"

using namespace std;

int main() {
    int length, width;
    
    // Ввод данных
    inputDimensions(length, width);
    
    // Вычисление площади
    int area = calculateArea(length, width);
    
    // Вывод результата
    cout << "Площадь прямоугольника: " << area << endl;
    
    return 0;
}