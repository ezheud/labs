// Лабораторная работа №4
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int my_len(const char* s) {
    int n = 0;
    while (s[n]) n++;
    return n;
}

void my_copy(char* d, const char* s) {
    while ((*d++ = *s++));
}

int my_cmp(const char* s1, const char* s2) {
    while (*s1 && *s2 && *s1 == *s2) {
        s1++; s2++;
    }
    return *s1 - *s2;
}

void my_cat(char* d, const char* s) {
    while (*d) d++;
    while ((*d++ = *s++));
}

int main() {
    // Часть 1: библиотечные функции
    cout << " 1. БИБЛИОТЕЧНЫЕ ФУНКЦИИ " << endl;
    
    char a[] = "qwerty";
    char b[] = "1234567890";
    char c[100];
    
    cout << "strlen: " << strlen(a) << ", " << strlen(b) << endl;
    
    strcpy(c, a);
    cout << "strcpy: " << c << endl;
    
    strcpy(c, a);
    strcat(c, b);
    cout << "strcat: " << c << endl;
    
    cout << "strcmp: " << strcmp(a, b) << " (отрицательное = a<b)" << endl << endl;
    
    // Часть 2: собственные функции
    cout << " 2. СОБСТВЕННЫЕ ФУНКЦИИ " << endl;
    
    cout << "my_len: " << my_len(a) << ", " << my_len(b) << endl;
    
    my_copy(c, a);
    cout << "my_copy: " << c << endl;
    
    my_copy(c, a);
    my_cat(c, b);
    cout << "my_cat: " << c << endl;
    
    cout << "my_cmp: " << my_cmp(a, b) << endl << endl;
    
    // Часть 3: динамическая память
    cout << "3. ДИНАМИЧЕСКАЯ ПАМЯТЬ" << endl;
    
    char* p1 = (char*)malloc(100);
    char* p2 = (char*)calloc(100, 1);
    
    my_copy(p1, "Malloc строка");
    my_copy(p2, "Calloc строка");
    
    cout << "malloc: " << p1 << endl;
    cout << "calloc: " << p2 << endl;
    
    // Демонстрация разницы
    char* m = (char*)malloc(5);
    char* cl = (char*)calloc(5, 1);
    
    cout << "malloc(5) байты: ";
    for (int i = 0; i < 5; i++) cout << (int)m[i] << " ";
    cout << "(мусор)" << endl;
    
    cout << "calloc(5) байты: ";
    for (int i = 0; i < 5; i++) cout << (int)cl[i] << " ";
    cout << "(нули)" << endl << endl;
    
    free(p1); free(p2); free(m); free(cl);
    
    // Часть 4: массив строк
    cout << "4. МАССИВ СТРОК" << endl;
    
    const char* arr[] = {"Строка1", "Строка2", "Строка3", "Строка4", "Строка5"};
    int n = 5;
    
    cout << "Массив строк:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "  [" << i << "] = " << arr[i] << endl;
    }
    
    // Динамический массив
    char** dyn = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        dyn[i] = (char*)malloc((my_len(arr[i]) + 1) * sizeof(char));
        my_copy(dyn[i], arr[i]);
    }
    
    // Поиск самой длинной
    int max_idx = 0;
    for (int i = 1; i < n; i++) {
        if (my_len(dyn[i]) > my_len(dyn[max_idx])) {
            max_idx = i;
        }
    }
    cout << "\nСамая длинная: " << dyn[max_idx] << endl;
    
    // Конкатенация
    char res[100] = "";
    my_copy(res, dyn[0]);
    my_cat(res, " + ");
    my_cat(res, dyn[1]);
    cout << "Конкатенация: " << res << endl;
    
    // Освобождение
    for (int i = 0; i < n; i++) free(dyn[i]);
    free(dyn);
    
    system("pause");
    return 0;
}