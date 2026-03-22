// main.cpp - упрощенная версия без реальной графики
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;

// Эмуляция графических констант
const int WHITE = 15, RED = 4, YELLOW = 14, DARKGRAY = 8;
int bkColor = DARKGRAY;

int getbkcolor() { return bkColor; }
void setbkcolor(int c) { bkColor = c; }
void cleardevice() { system("cls"); }
void delay(int ms) { 
    for(int i=0; i<ms*1000; i++); 
}

class Point {
protected:
    int X, Y, Cvet;
public:
    Point() : X(0), Y(0), Cvet(WHITE) {}
    Point(int XN, int YN, int Color) : X(XN), Y(YN), Cvet(Color) {}
    virtual ~Point() {}
    virtual void Show() = 0;
    virtual void Hide() = 0;
    void Locat(int &XL, int &YL) { XL = X; YL = Y; }
    void Fly(int Cost) {
        Show();
        int XX, YY;
        do {
            Locat(XX, YY);
            int dx = rand() % (2 * Cost + 1) - Cost;
            int dy = rand() % (2 * Cost + 1) - Cost;
            XX += dx;
            YY += dy;
            if (XX < 0) XX = 0;
            if (XX > 80) XX = 80;
            if (YY < 0) YY = 0;
            if (YY > 24) YY = 24;
        } while (XX == X && YY == Y);
        Hide();
        X = XX; Y = YY;
        Show();
        delay(300);
    }
    int getX() { return X; }
    int getY() { return Y; }
};

class Krug : public Point {
protected:
    int Radius;
public:
    Krug() : Point(), Radius(0) {}
    Krug(int XN, int YN, int R, int Color) : Point(XN, YN, Color), Radius(R) {
        Show();
    }
    virtual void Show() override {
        cout << "\033[" << Y+1 << ";" << X+1 << "H";
        cout << "●";
    }
    virtual void Hide() override {
        cout << "\033[" << Y+1 << ";" << X+1 << "H";
        cout << " ";
    }
    void ChangeSize(int delta) {
        Hide();
        Radius += delta;
        if (Radius < 1) Radius = 1;
        if (Radius > 5) Radius = 5;
        Show();
    }
    void ChangeColor(int newColor) {
        Cvet = newColor;
    }
};

class Ring : public Krug {
protected:
    int Width;
public:
    Ring() : Krug(), Width(0) {}
    Ring(int XN, int YN, int R, int Color, int Wid) : Krug(XN, YN, R, Color), Width(Wid) {
        Show();
    }
    virtual void Show() override {
        cout << "\033[" << Y+1 << ";" << X+1 << "H";
        cout << "○";
    }
    void ChangeWidth(int delta) {
        Width += delta;
        if (Width < 1) Width = 1;
        if (Width > Radius) Width = Radius;
    }
};

int main() {
    srand(time(NULL));
    system("cls");
    
    cout << "Нажмите любую кнопку" << endl;
    getch();
    system("cls");
    
    Krug krug(20, 12, 3, RED);
    Ring ring(60, 12, 4, YELLOW, 2);
    
    for (int i = 0; i < 10; i++) {
        krug.Fly(10);
        ring.Fly(8);
        cout << "\033[1;1H";
        cout << "Step " << i+1 << "/10";
    }
    
    cout << "\033[24;1H";
    cout << "Нажмите любую кнопку для выхода";
    getch();
    
    return 0;
}