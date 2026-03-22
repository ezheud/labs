// main.cpp - главная программа управления автопарком
#include <iostream>
#include <string>
#include "AutoPark.h"
using namespace std;

// Создание списка автобусов
List<Bus> createBusList() {
    List<Bus> buses;
    
    buses.push_back(Bus(101, "Ivanov", 10));
    buses.push_back(Bus(205, "Petrov", 20));
    buses.push_back(Bus(189, "Sidorov", 15));
    buses.push_back(Bus(156, "Kozlov", 10));
    buses.push_back(Bus(234, "Smirnov", 25));
    buses.push_back(Bus(112, "Volkov", 20));
    buses.push_back(Bus(178, "Morozov", 15));
    buses.push_back(Bus(223, "Novikov", 30));
    buses.push_back(Bus(145, "Lebedev", 25));
    buses.push_back(Bus(197, "Sokolov", 10));
    
    return buses;
}

// Вывод главного меню
void showMenu() {
    cout << "\n========================================" << endl;
    cout << "       BUS PARK MANAGEMENT SYSTEM" << endl;
    cout << "========================================" << endl;
    cout << " 1. Show all buses in the park" << endl;
    cout << " 2. Show all buses on the route" << endl;
    cout << " 3. Send bus to route" << endl;
    cout << " 4. Return bus to park" << endl;
    cout << " 5. Find bus by number" << endl;
    cout << " 6. Sort buses in park by number" << endl;
    cout << " 7. Sort buses in park by route" << endl;
    cout << " 8. Show statistics" << endl;
    cout << " 0. Exit" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Choose action: ";
}

int main() {
    AutoPark park;
    List<Bus> allBuses = createBusList();
    
    cout << "========================================" << endl;
    cout << "     LABORATORY WORK #10" << endl;
    cout << "     BUS PARK MANAGEMENT" << endl;
    cout << "========================================" << endl;
    
    cout << "\nList of all buses in the park:" << endl;
    allBuses.print();
    
    park.initPark(allBuses);
    
    cout << "\nPress Enter to continue...";
    cin.get();
    
    int choice;
    int busNumber;
    Bus foundBus;
    
    do {
        system("cls");
        showMenu();
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                cout << "\n========================================" << endl;
                cout << "BUSES IN THE PARK (" << park.getInParkCount() << " buses):" << endl;
                cout << "----------------------------------------" << endl;
                park.showInPark();
                break;
                
            case 2:
                cout << "\n========================================" << endl;
                cout << "BUSES ON THE ROUTE (" << park.getOnRouteCount() << " buses):" << endl;
                cout << "----------------------------------------" << endl;
                park.showOnRoute();
                break;
                
            case 3:
                cout << "\n========================================" << endl;
                cout << "SEND BUS TO ROUTE" << endl;
                cout << "----------------------------------------" << endl;
                cout << "Enter bus number: ";
                cin >> busNumber;
                
                if (park.sendToRoute(busNumber)) {
                    cout << "SUCCESS: Bus #" << busNumber << " sent to route." << endl;
                } else {
                    cout << "ERROR: Bus #" << busNumber << " not found in the park!" << endl;
                }
                break;
                
            case 4:
                cout << "\n========================================" << endl;
                cout << "RETURN BUS TO PARK" << endl;
                cout << "----------------------------------------" << endl;
                cout << "Enter bus number: ";
                cin >> busNumber;
                
                if (park.returnToPark(busNumber)) {
                    cout << "SUCCESS: Bus #" << busNumber << " returned to park." << endl;
                } else {
                    cout << "ERROR: Bus #" << busNumber << " not found on the route!" << endl;
                }
                break;
                
            case 5:
                cout << "\n========================================" << endl;
                cout << "FIND BUS" << endl;
                cout << "----------------------------------------" << endl;
                cout << "Enter bus number: ";
                cin >> busNumber;
                
                if (park.findBus(busNumber, foundBus)) {
                    cout << "SUCCESS: Bus found:" << endl;
                    cout << "  " << foundBus << endl;
                } else {
                    cout << "ERROR: Bus #" << busNumber << " not found!" << endl;
                }
                break;
                
            case 6:
                cout << "\n========================================" << endl;
                cout << "SORT BUSES IN PARK BY NUMBER" << endl;
                cout << "----------------------------------------" << endl;
                park.sortParkByNumber();
                cout << "SUCCESS: Sorting completed." << endl;
                cout << "\nBuses in park after sorting:" << endl;
                park.showInPark();
                break;
                
            case 7:
                cout << "\n========================================" << endl;
                cout << "SORT BUSES IN PARK BY ROUTE" << endl;
                cout << "----------------------------------------" << endl;
                park.sortParkByRoute();
                cout << "SUCCESS: Sorting completed." << endl;
                cout << "\nBuses in park after sorting:" << endl;
                park.showInPark();
                break;
                
            case 8:
                cout << "\n========================================" << endl;
                cout << "PARK STATISTICS" << endl;
                cout << "----------------------------------------" << endl;
                cout << "Total buses: " << (park.getInParkCount() + park.getOnRouteCount()) << endl;
                cout << "  - In park: " << park.getInParkCount() << endl;
                cout << "  - On route: " << park.getOnRouteCount() << endl;
                break;
                
            case 0:
                cout << "\n========================================" << endl;
                cout << "Program terminated." << endl;
                cout << "========================================" << endl;
                break;
                
            default:
                cout << "\nInvalid choice! Try again." << endl;
        }
        
        if (choice != 0) {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
        
    } while (choice != 0);
    
    return 0;
}