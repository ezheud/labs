// main.cpp
#include <iostream>
#include "Stroka.h"
using namespace std;

int main() {
    cout << "=== LAB 6: CLASS STROKA ===\n" << endl;
    
    // Тест 1: Создание строк
    cout << "1. Creating strings:" << endl;
    Stroka s1("Hello");
    Stroka s2;
    Stroka s3(s1);
    
    cout << "   s1 = "; s1.output(); cout << endl;
    cout << "   s2 = "; s2.output(); cout << "(empty)" << endl;
    cout << "   s3 = "; s3.output(); cout << " (copy of s1)" << endl;
    cout << endl;
    
    // Тест 2: Присваивание
    cout << "2. Assignment:" << endl;
    s2 = "World";
    cout << "   s2 = "; s2.output(); cout << endl;
    s2 = s1;
    cout << "   s2 = s1 -> "; s2.output(); cout << endl;
    cout << endl;
    
    // Тест 3: Конкатенация
    cout << "3. Concatenation:" << endl;
    Stroka s4 = s1 + s2;
    cout << "   s4 = s1 + s2 = "; s4.output(); cout << endl;
    cout << "   Length of s4: " << s4.getLength() << endl;
    cout << endl;
    
    // Тест 4: Сравнение
    cout << "4. Comparison:" << endl;
    Stroka a("test");
    Stroka b("test");
    Stroka c("other");
    
    cout << "   a = test, b = test, c = other" << endl;
    cout << "   a == b: " << (a == b ? "true" : "false") << endl;
    cout << "   a == c: " << (a == c ? "true" : "false") << endl;
    cout << "   a != c: " << (a != c ? "true" : "false") << endl;
    cout << endl;
    
    // Тест 5: Ввод строки
    cout << "5. Input:" << endl;
    cout << "   Enter a string: ";
    Stroka s5;
    s5.input();
    cout << "   You entered: "; s5.output(); cout << endl;
    cout << "   Length: " << s5.getLength() << endl;
    cout << endl;
    
    // Тест 6: Дополнительные методы
    cout << "6. Additional methods:" << endl;
    Stroka s6("Hello World!");
    cout << "   String: "; s6.output(); cout << endl;
    cout << "   Length: " << s6.getLength() << endl;
    cout << "   Capacity: " << s6.getCapacity() << endl;
    cout << "   Is empty? " << (s6.isEmpty() ? "yes" : "no") << endl;
    cout << "   Char at index 4: " << s6.at(4) << endl;
    
    s6.setAt(0, 'h');
    cout << "   After setAt(0, 'h'): "; s6.output(); cout << endl;
    
    s6.clear();
    cout << "   After clear(): "; s6.output(); cout << endl;
    cout << "   Is empty? " << (s6.isEmpty() ? "yes" : "no") << endl;
    
    cout << "\n=== LAB COMPLETED ===" << endl;
    
    return 0;
}