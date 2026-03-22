// Stroka.cpp
#include "Stroka.h"
#include <cstring>
#include <cstdio>

// Простые функции для работы со строками
int my_len(const char* s) {
    int n = 0;
    while (s[n]) n++;
    return n;
}

void my_copy(char* d, const char* s) {
    int i = 0;
    while (s[i]) {
        d[i] = s[i];
        i++;
    }
    d[i] = '\0';
}

int my_cmp(const char* s1, const char* s2) {
    int i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i]) {
        i++;
    }
    return s1[i] - s2[i];
}

void my_cat(char* d, const char* s) {
    int i = 0, j = 0;
    while (d[i]) i++;
    while (s[j]) {
        d[i + j] = s[j];
        j++;
    }
    d[i + j] = '\0';
}

// Конструктор по умолчанию
Stroka::Stroka() {
    capacity = 80;
    str = new char[capacity];
    str[0] = '\0';
    length = 0;
}

// Конструктор из C-строки
Stroka::Stroka(const char* s) {
    length = my_len(s);
    capacity = length + 1;
    str = new char[capacity];
    my_copy(str, s);
}

// Конструктор с заданным размером
Stroka::Stroka(int size) {
    if (size <= 0) size = 1;
    capacity = size;
    str = new char[capacity];
    str[0] = '\0';
    length = 0;
}

// Конструктор копирования
Stroka::Stroka(const Stroka& other) {
    length = other.length;
    capacity = other.capacity;
    str = new char[capacity];
    my_copy(str, other.str);
}

// Деструктор
Stroka::~Stroka() {
    delete[] str;
}

// Оператор присваивания
Stroka& Stroka::operator=(const Stroka& other) {
    if (this != &other) {
        delete[] str;
        length = other.length;
        capacity = other.capacity;
        str = new char[capacity];
        my_copy(str, other.str);
    }
    return *this;
}

// Оператор конкатенации
Stroka Stroka::operator+(const Stroka& other) const {
    Stroka result;
    int new_length = length + other.length;
    
    if (new_length + 1 > result.capacity) {
        delete[] result.str;
        result.capacity = new_length + 1;
        result.str = new char[result.capacity];
    }
    
    my_copy(result.str, str);
    my_cat(result.str, other.str);
    result.length = new_length;
    return result;
}

// Оператор сравнения
bool Stroka::operator==(const Stroka& other) const {
    return my_cmp(str, other.str) == 0;
}

// Оператор "не равно"
bool Stroka::operator!=(const Stroka& other) const {
    return !(*this == other);
}

// Длина строки
int Stroka::getLength() const {
    return length;
}

// Вместимость
int Stroka::getCapacity() const {
    return capacity;
}

// Ввод строки
void Stroka::input() {
    char buffer[256];
    cin.getline(buffer, 256);
    
    int new_len = my_len(buffer);
    
    if (new_len + 1 > capacity) {
        delete[] str;
        capacity = new_len + 1;
        str = new char[capacity];
    }
    
    my_copy(str, buffer);
    length = new_len;
}

// Вывод строки
void Stroka::output() const {
    cout << str;
}

// Очистка
void Stroka::clear() {
    str[0] = '\0';
    length = 0;
}

// Проверка на пустоту
bool Stroka::isEmpty() const {
    return length == 0;
}

// Доступ по индексу
char Stroka::at(int index) const {
    if (index >= 0 && index < length) {
        return str[index];
    }
    return '\0';
}

// Установка символа
void Stroka::setAt(int index, char ch) {
    if (index >= 0 && index < length) {
        str[index] = ch;
    }
}