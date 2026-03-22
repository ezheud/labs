// main.cpp - демонстрация работы с потоками
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Stroka.h"
using namespace std;

// --- задание 2: программа шифратор (с потоками) ---
void encryptFile(const char* inputFile, const char* outputFile, const char* key) {
    ifstream fin(inputFile, ios::binary);
    ofstream fout(outputFile, ios::binary);
    
    if (!fin.is_open()) {
        cout << "Error: Cannot open input file!" << endl;
        return;
    }
    if (!fout.is_open()) {
        cout << "Error: Cannot create output file!" << endl;
        return;
    }
    
    int key_len = strlen(key);
    int key_idx = 0;
    char ch;
    int count = 0;
    
    while (fin.get(ch)) {
        ch = ch ^ key[key_idx % key_len];
        fout.put(ch);
        key_idx++;
        count++;
    }
    
    fin.close();
    fout.close();
    
    cout << "Processed " << count << " bytes." << endl;
    cout << "Key: \"" << key << "\"" << endl;
}

// --- задание 4: демонстрация методов управления потоками ---
void demonstrateStreamStates() {
    cout << "\n--- STREAM STATE METHODS ---\n";
    
    // 1. Состояния потоков
    ifstream file("test.txt");
    
    cout << "After opening file:" << endl;
    cout << "  good(): " << (file.good() ? "true" : "false") << endl;
    cout << "  eof(): " << (file.eof() ? "true" : "false") << endl;
    cout << "  fail(): " << (file.fail() ? "true" : "false") << endl;
    cout << "  bad(): " << (file.bad() ? "true" : "false") << endl;
    
    // 2. Чтение до конца
    char ch;
    while (file.get(ch));
    
    cout << "\nAfter reading to EOF:" << endl;
    cout << "  eof(): " << (file.eof() ? "true" : "false") << endl;
    
    // 3. Очистка состояния
    file.clear();
    cout << "\nAfter clear():" << endl;
    cout << "  eof(): " << (file.eof() ? "true" : "false") << endl;
    
    file.close();
    
    // 4. Методы форматирования
    cout << "\n--- FORMATTING METHODS ---\n";
    
    cout << "Default format:" << endl;
    cout << 123.456789 << endl;
    
    cout << "\nAfter setf(ios::fixed) and precision(2):" << endl;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << 123.456789 << endl;
    
    cout << "\nAfter width(10) and fill('*'):" << endl;
    cout.width(10);
    cout.fill('*');
    cout << 123 << endl;
    
    cout << "\nAfter unsetf(ios::fixed) and scientific:" << endl;
    cout.unsetf(ios::fixed);
    cout.setf(ios::scientific);
    cout << 123.456789 << endl;
    
    // 5. Манипуляторы
    cout << "\nMANIPULATORS\n";
    cout << "Hex: " << hex << 255 << dec << endl;
    cout << "Oct: " << oct << 255 << dec << endl;
    cout << "Setw(10): " << setw(10) << "Hello" << endl;
    cout << "Setprecision(3): " << setprecision(3) << 3.14159 << endl;
}

//задание 4: собственная программа
void demonstrateCustomFileProcessing() {
    cout << "\nCUSTOM FILE PROCESSING\n";
    
    // Создаем файл с данными
    ofstream out("data.txt");
    out << "Hello World" << endl;
    out << "C++ Programming" << endl;
    out << "File Streams" << endl;
    out << "123 456 789" << endl;
    out.close();
    
    // Читаем и обрабатываем файл
    ifstream in("data.txt");
    if (!in.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    
    string line;
    int lineNum = 0;
    int wordCount = 0;
    int charCount = 0;
    
    cout << "File content:" << endl;
    cout << "-------------" << endl;
    
    while (getline(in, line)) {
        lineNum++;
        cout << lineNum << ": " << line << endl;
        
        // Подсчет слов и символов
        charCount += line.length();
        bool inWord = false;
        for (char c : line) {
            if (isalnum(c)) {
                if (!inWord) {
                    wordCount++;
                    inWord = true;
                }
            } else {
                inWord = false;
            }
        }
    }
    
    cout << "-------------" << endl;
    cout << "Lines: " << lineNum << endl;
    cout << "Words: " << wordCount << endl;
    cout << "Chars: " << charCount << endl;
    
    in.close();
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    cout << "LAB8" << endl;
    cout << "streams and file operations" << endl;
    
    // ЗАДАНИЕ 1: РАБОТА С КЛАССОМ STROKA 
    cout << "--- TASK 1: STROKA CLASS WITH STREAMS ---\n" << endl;
    
    Stroka s1("Hello");
    Stroka s2;
    
    cout << "s1 = " << s1 << endl;
    cout << "Enter a string: ";
    cin >> s2;
    cout << "You entered: " << s2 << endl;
    
    // Работа с файлами через класс Stroka
    ofstream fout("stroka_test.txt");
    fout << "Writing to file: " << s1 << endl;
    fout << "Another line: " << s2 << endl;
    fout.close();
    
    ifstream fin("stroka_test.txt");
    Stroka s3, s4;
    fin >> s3 >> s4;
    cout << "\nRead from file: " << s3 << " " << s4 << endl;
    fin.close();
    
    // ЗАДАНИЕ 2: ПРОГРАММА-ШИФРАТОР
    cout << "\n--- TASK 2: ENCRYPTION PROGRAM ---\n" << endl;
    
    // Создаем тестовый файл
    ofstream test("original.txt");
    test << "This is a test file for encryption." << endl;
    test << "Line 2: testing." << endl;
    test << "1234567890" << endl;
    test.close();
    
    cout << "Original file created: original.txt" << endl;
    
    // Шифруем
    encryptFile("original.txt", "encrypted.bin", "secret");
    cout << "Encrypted: encrypted.bin" << endl;
    
    // Расшифровываем
    encryptFile("encrypted.bin", "decrypted.txt", "secret");
    cout << "Decrypted: decrypted.txt" << endl;
    
    //  ЗАДАНИЕ 4: МЕТОДЫ УПРАВЛЕНИЯ ПОТОКАМИ 
    demonstrateStreamStates();
    demonstrateCustomFileProcessing();
    
    // ЗАДАНИЕ 4: ИЛЛЮСТРАЦИЯ ВОЗМОЖНОСТЕЙ ПОТОКОВ 
    cout << "\n--- ADDITIONAL STREAM DEMONSTRATION ---\n" << endl;
    
    // Работа с флагами состояния
    cout << "Demonstrating error handling:" << endl;
    int num;
    cout << "Enter a number: ";
    cin >> num;
    
    if (cin.fail()) {
        cout << "Error! Invalid input." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Stream cleared." << endl;
    } else {
        cout << "You entered: " << num << endl;
    }
    
    // Работа с позиционированием в файле
    fstream file("position.txt", ios::out | ios::in | ios::trunc);
    file << "0123456789";
    
    cout << "\nFile position demonstration:" << endl;
    cout << "Initial position: " << file.tellp() << endl;
    
    file.seekp(5);
    file << "ABC";
    
    file.seekg(0);
    string content;
    file >> content;
    cout << "After seekp(5) and write: " << content << endl;
    
    file.close();
    
    cout << "Finish" << endl;
    
    return 0;
}