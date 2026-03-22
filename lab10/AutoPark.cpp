// AutoPark.cpp - реализация класса AutoPark
#include "AutoPark.h"

// Инициализация автопарка
void AutoPark::initPark(const List<Bus>& buses) {
    inPark.clear();
    Node<Bus>* current = buses.begin();
    while (current != nullptr) {
        inPark.push_back(current->data);
        current = current->next;
    }
}

// Отправка автобуса на маршрут
bool AutoPark::sendToRoute(int busNumber) {
    Bus temp(busNumber, "", 0);
    Node<Bus>* found = inPark.find(temp);
    
    if (found != nullptr) {
        inPark.remove(found->data);
        onRoute.push_back(found->data);
        return true;
    }
    return false;
}

// Возврат автобуса в парк
bool AutoPark::returnToPark(int busNumber) {
    Bus temp(busNumber, "", 0);
    Node<Bus>* found = onRoute.find(temp);
    
    if (found != nullptr) {
        onRoute.remove(found->data);
        inPark.push_back(found->data);
        return true;
    }
    return false;
}

// Вывод автобусов в парке
void AutoPark::showInPark() const {
    if (inPark.isEmpty()) {
        cout << "  No buses in the park." << endl;
    } else {
        inPark.print();
    }
}

// Вывод автобусов на маршруте
void AutoPark::showOnRoute() const {
    if (onRoute.isEmpty()) {
        cout << "  No buses on the route." << endl;
    } else {
        onRoute.print();
    }
}

// Поиск автобуса по номеру
bool AutoPark::findBus(int busNumber, Bus& result) const {
    Bus temp(busNumber, "", 0);
    
    Node<Bus>* found = inPark.find(temp);
    if (found != nullptr) {
        result = found->data;
        return true;
    }
    
    found = onRoute.find(temp);
    if (found != nullptr) {
        result = found->data;
        return true;
    }
    
    return false;
}

// Сортировка автобусов в парке по номеру (пузырьковая)
void AutoPark::sortParkByNumber() {
    if (inPark.getSize() <= 1) return;
    
    bool swapped;
    do {
        swapped = false;
        Node<Bus>* current = inPark.begin();
        while (current != nullptr && current->next != nullptr) {
            if (current->data.number > current->next->data.number) {
                Bus temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

// Сортировка автобусов в парке по маршруту
void AutoPark::sortParkByRoute() {
    if (inPark.getSize() <= 1) return;
    
    bool swapped;
    do {
        swapped = false;
        Node<Bus>* current = inPark.begin();
        while (current != nullptr && current->next != nullptr) {
            if (current->data.routeNumber > current->next->data.routeNumber) {
                Bus temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}