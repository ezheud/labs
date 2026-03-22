// Krug.cpp - реализация класса Krug
#include "Krug.h"

Krug::Krug() : Point(), Radius(0) {}

Krug::Krug(int XN, int YN, int R, int Color) 
    : Point(XN, YN, Color), Radius(R) {
    Show();
}

void Krug::Show() {
    setcolor(Cvet);
    setfillstyle(SOLID_FILL, Cvet);
    pieslice(X, Y, 0, 360, Radius);
}

void Krug::Hide() {
    int bkColor = getbkcolor();
    setcolor(bkColor);
    setfillstyle(SOLID_FILL, bkColor);
    pieslice(X, Y, 0, 360, Radius);
}

// Изменение размера
void Krug::ChangeSize(int delta) {
    Hide();
    Radius += delta;
    if (Radius < 5) Radius = 5;
    if (Radius > 100) Radius = 100;
    Show();
}

// Изменение цвета
void Krug::ChangeColor(int newColor) {
    Hide();
    Cvet = newColor;
    Show();
}