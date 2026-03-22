// Point.h - базовый класс для графических объектов
#ifndef POINT_H
#define POINT_H

#include <graphics.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Point {
protected:
    int X, Y;       // Координаты
    int Cvet;       // Цвет

public:
    // Конструкторы
    Point();
    Point(int XN, int YN, int Color);
    virtual ~Point() {}
    
    // Виртуальные методы (чисто виртуальные - абстрактный класс)
    virtual void Show() = 0;
    virtual void Hide() = 0;
    
    // Невиртуальные методы
    void Locat(int &XL, int &YL);
    void Fly(int Cost);
    
    // Геттеры
    int getX() const { return X; }
    int getY() const { return Y; }
    int getColor() const { return Cvet; }
    
    // Сеттеры
    void setX(int x) { X = x; }
    void setY(int y) { Y = y; }
    void setColor(int color) { Cvet = color; }
};

#endif