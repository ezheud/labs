// AutoPark.h - класс для управления автопарком
#ifndef AUTOPARK_H
#define AUTOPARK_H

#include <iostream>
#include <string>
#include "List.h"
using namespace std;

// Структура для хранения информации об автобусе
struct Bus {
    int number;
    string driver;
    int routeNumber;
    
    Bus() : number(0), driver(""), routeNumber(0) {}
    Bus(int n, const string& d, int r) : number(n), driver(d), routeNumber(r) {}
    
    // Метод для получения номера автобуса
    int getNumber() const { return number; }
    
    // Оператор сравнения для поиска по объекту Bus
    bool operator==(const Bus& other) const {
        return number == other.number;
    }
    
    // Оператор вывода
    friend ostream& operator<<(ostream& os, const Bus& bus) {
        os << "Bus #" << bus.number 
           << ", driver: " << bus.driver 
           << ", route: " << bus.routeNumber;
        return os;
    }
};

// Класс для управления автопарком
class AutoPark {
private:
    List<Bus> inPark;     // Автобусы в парке
    List<Bus> onRoute;    // Автобусы на маршруте
    
public:
    AutoPark() {}
    
    void initPark(const List<Bus>& buses);
    bool sendToRoute(int busNumber);
    bool returnToPark(int busNumber);
    void showInPark() const;
    void showOnRoute() const;
    bool findBus(int busNumber, Bus& result) const;
    int getInParkCount() const { return inPark.getSize(); }
    int getOnRouteCount() const { return onRoute.getSize(); }
    void sortParkByNumber();
    void sortParkByRoute();
};

#endif