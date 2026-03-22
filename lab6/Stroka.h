// Stroka.h
#ifndef STROKA_H
#define STROKA_H

#include <iostream>
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
    void input();
    void output() const;
    void clear();
    bool isEmpty() const;
    char at(int index) const;
    void setAt(int index, char ch);
};

#endif