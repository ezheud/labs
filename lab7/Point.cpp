// Point.cpp - реализация базового класса Point
#include "Point.h"

Point::Point() : X(0), Y(0), Cvet(WHITE) {}

Point::Point(int XN, int YN, int Color) : X(XN), Y(YN), Cvet(Color) {}

void Point::Locat(int &XL, int &YL) {
    XL = X;
    YL = Y;
}

void Point::Fly(int Cost) {
    Show();
    
    int XX, YY;
    do {
        Locat(XX, YY);
        
        // Случайное изменение координат
        int dx = rand() % (2 * Cost + 1) - Cost;
        int dy = rand() % (2 * Cost + 1) - Cost;
        XX += dx;
        YY += dy;
        
        // Проверка границ экрана
        if (XX < 0) XX = 0;
        if (XX > getmaxx()) XX = getmaxx();
        if (YY < 0) YY = 0;
        if (YY > getmaxy()) YY = getmaxy();
        
    } while (XX == X && YY == Y);
    
    Hide();
    X = XX;
    Y = YY;
    Show();
    
    delay(300);
}