// Stroka.h - класс Stroka с операторами потокового ввода/вывода
#ifndef STROKA_H
#define STROKA_H

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Stroka {
private:
    char* str;
    int length;
    int capacity;

public:
    // Конструкторы
    Stroka();
    Stroka(const char* s);
    Stroka(int size);
    Stroka(const Stroka& other);
    
    // Деструктор
    ~Stroka();
    
    // Операторы
    Stroka& operator=(const Stroka& other);
    Stroka operator+(const Stroka& other) const;
    bool operator==(const Stroka& other) const;
    bool operator!=(const Stroka& other) const;
    
    // Методы
    int getLength() const;
    int getCapacity() const;
    const char* c_str() const;
    void input();
    void output() const;
    void clear();
    bool isEmpty() const;
    char at(int index) const;
    void setAt(int index, char ch);
    
    // Операторы ввода/вывода (дружественные функции)
    friend ostream& operator<<(ostream& os, const Stroka& s);
    friend istream& operator>>(istream& is, Stroka& s);
    
    // Операторы файлового ввода/вывода
    friend ofstream& operator<<(ofstream& ofs, const Stroka& s);
    friend ifstream& operator>>(ifstream& ifs, Stroka& s);
};

#endif