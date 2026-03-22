// Ring.cpp - реализация класса Ring
#include "Ring.h"

Ring::Ring() : Krug(), Width(0) {}

Ring::Ring(int XN, int YN, int R, int Color, int Wid) 
    : Krug(XN, YN, R, Color), Width(Wid) {
    Show();
}

void Ring::Show() {
    // Сначала рисуем круг
    setcolor(Cvet);
    setfillstyle(SOLID_FILL, Cvet);
    pieslice(X, Y, 0, 360, Radius);
    
    // Затем вырезаем внутреннюю часть (рисуем цветом фона)
    int bkColor = getbkcolor();
    setcolor(bkColor);
    setfillstyle(SOLID_FILL, bkColor);
    pieslice(X, Y, 0, 360, Radius - Width);
}

void Ring::ChangeWidth(int delta) {
    Hide();
    Width += delta;
    if (Width < 1) Width = 1;
    if (Width > Radius - 2) Width = Radius - 2;
    Show();
}