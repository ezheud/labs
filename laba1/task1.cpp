// Лабораторная работа №1, задание 1
#include <iostream>
using namespace std;

// Прототип функции power
int power(int, int);

int main() {
    int i, k;
    int base, exponent;
    
    // Запрос основания и степени у пользователя
    cout << "Введите основание: ";
    cin >> base;
    cout << "Введите максимальную степень: ";
    cin >> exponent;
    
    cout << "\nРезультаты возведения " << base << " в степень от 0 до " << exponent << ":\n";
    cout << "----------------------------------------\n";
    
    // Цикл для вывода степеней
    for (i = 0; i <= exponent; i++) {
        k = power(base, i);
        cout << base << "^" << i << " = " << k << endl;
    }
    
    return 0;
}

// Функция возведения числа x в степень n
int power(int x, int n) {
    int i;
    int p = 1;  // Начальное значение результата
    
    // Исправленный цикл: умножаем p на x n раз
    // (в исходном коде была ошибка: цикл шел от 1 до n-1, что давало x^(n-1))
    for (i = 0; i < n; i++) {
        p = p * x;
    }
    
    return p;
}