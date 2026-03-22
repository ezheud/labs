// Stroka.cpp - реализация класса Stroka
#include "Stroka.h"
#include <cstdlib>

// ========== ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ ==========
int my_len(const char* s) {
    int n = 0;
    while (s[n]) n++;
    return n;
}

void my_copy(char* d, const char* s) {
    int i = 0;
    while (s[i]) {
        d[i] = s[i];
        i++;
    }
    d[i] = '\0';
}

int my_cmp(const char* s1, const char* s2) {
    int i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i]) i++;
    return s1[i] - s2[i];
}

void my_cat(char* d, const char* s) {
    int i = 0, j = 0;
    while (d[i]) i++;
    while (s[j]) {
        d[i + j] = s[j];
        j++;
    }
    d[i + j] = '\0';
}

// ========== КОНСТРУКТОРЫ И ДЕСТРУКТОР ==========
Stroka::Stroka() {
    capacity = 80;
    str = new char[capacity];
    str[0] = '\0';
    length = 0;
}

Stroka::Stroka(const char* s) {
    length = my_len(s);
    capacity = length + 1;
    str = new char[capacity];
    my_copy(str, s);
}

Stroka::Stroka(int size) {
    if (size <= 0) size = 1;
    capacity = size;
    str = new char[capacity];
    str[0] = '\0';
    length = 0;
}

Stroka::Stroka(const Stroka& other) {
    length = other.length;
    capacity = other.capacity;
    str = new char[capacity];
    my_copy(str, other.str);
}

Stroka::~Stroka() {
    delete[] str;
}

// ========== ОПЕРАТОРЫ ==========
Stroka& Stroka::operator=(const Stroka& other) {
    if (this != &other) {
        delete[] str;
        length = other.length;
        capacity = other.capacity;
        str = new char[capacity];
        my_copy(str, other.str);
    }
    return *this;
}

Stroka Stroka::operator+(const Stroka& other) const {
    Stroka result;
    int new_length = length + other.length;
    
    if (new_length + 1 > result.capacity) {
        delete[] result.str;
        result.capacity = new_length + 1;
        result.str = new char[result.capacity];
    }
    
    my_copy(result.str, str);
    my_cat(result.str, other.str);
    result.length = new_length;
    return result;
}

bool Stroka::operator==(const Stroka& other) const {
    return my_cmp(str, other.str) == 0;
}

bool Stroka::operator!=(const Stroka& other) const {
    return !(*this == other);
}

// ========== МЕТОДЫ ==========
int Stroka::getLength() const { return length; }
int Stroka::getCapacity() const { return capacity; }
const char* Stroka::c_str() const { return str; }

void Stroka::input() {
    char buffer[256];
    cin.getline(buffer, 256);
    
    int new_len = my_len(buffer);
    if (new_len + 1 > capacity) {
        delete[] str;
        capacity = new_len + 1;
        str = new char[capacity];
    }
    my_copy(str, buffer);
    length = new_len;
}

void Stroka::output() const {
    cout << str;
}

void Stroka::clear() {
    str[0] = '\0';
    length = 0;
}

bool Stroka::isEmpty() const {
    return length == 0;
}

char Stroka::at(int index) const {
    if (index >= 0 && index < length) return str[index];
    return '\0';
}

void Stroka::setAt(int index, char ch) {
    if (index >= 0 && index < length) str[index] = ch;
}

// ========== ЗАДАНИЕ 1: ПЕРЕГРУЖЕННЫЕ ОПЕРАТОРЫ ==========
ostream& operator<<(ostream& os, const Stroka& s) {
    os << s.str;
    return os;
}

istream& operator>>(istream& is, Stroka& s) {
    char buffer[256];
    is >> buffer;
    
    int new_len = my_len(buffer);
    if (new_len + 1 > s.capacity) {
        delete[] s.str;
        s.capacity = new_len + 1;
        s.str = new char[s.capacity];
    }
    my_copy(s.str, buffer);
    s.length = new_len;
    return is;
}

ofstream& operator<<(ofstream& ofs, const Stroka& s) {
    ofs << s.str;
    return ofs;
}

ifstream& operator>>(ifstream& ifs, Stroka& s) {
    char buffer[256];
    ifs >> buffer;
    
    int new_len = my_len(buffer);
    if (new_len + 1 > s.capacity) {
        delete[] s.str;
        s.capacity = new_len + 1;
        s.str = new char[s.capacity];
    }
    my_copy(s.str, buffer);
    s.length = new_len;
    return ifs;
}