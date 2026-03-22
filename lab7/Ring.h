// Ring.h - класс кольца (наследник Krug)
#ifndef RING_H
#define RING_H

#include "Krug.h"

class Ring : public Krug {
protected:
    int Width;      // Ширина кольца

public:
    // Конструкторы
    Ring();
    Ring(int XN, int YN, int R, int Color, int Wid);
    virtual ~Ring() {}
    
    // Переопределенный виртуальный метод
    virtual void Show() override;
    
    // Дополнительные методы для задания 2
    virtual void ChangeWidth(int delta);
};

#endif