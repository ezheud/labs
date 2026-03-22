// Krug.h - класс круга
#ifndef KRUG_H
#define KRUG_H

#include "Point.h"

class Krug : public Point {
protected:
    int Radius;

public:
    // Конструкторы
    Krug();
    Krug(int XN, int YN, int R, int Color);
    virtual ~Krug() {}
    
    // Переопределенные виртуальные методы
    virtual void Show() override;
    virtual void Hide() override;
    
    // Дополнительные методы для задания 2
    virtual void ChangeSize(int delta);
    virtual void ChangeColor(int newColor);
    
    // Геттер
    int getRadius() const { return Radius; }
};

#endif