// Лабораторная работа №3
#include <iostream>
#include <conio.h>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void swap(int &a, int &b) {
    int t = a; a = b; b = t;
}

// 1. Сортировка методом "мини-макс" (выбором)
void sortMinMax(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx]) min_idx = j;
        if (min_idx != i) swap(arr[i], arr[min_idx]);
    }
}

// 2. Пузырьковая сортировка
void sortBubble(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// 3. Быстрая сортировка
void sortQuick(int arr[], int left, int right) {
    if (left >= right) return;
    int pivot = arr[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }
    sortQuick(arr, left, j);
    sortQuick(arr, i, right);
}

// 4. Четные по возрастанию, нечетные по убыванию
void sortEvenAscOddDesc(int arr[], int n) {
    // Сначала собираем отдельно четные и нечетные
    int evens[100], odds[100], ec = 0, oc = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) evens[ec++] = arr[i];
        else odds[oc++] = arr[i];
    }
    // Сортируем четные по возрастанию
    for (int i = 0; i < ec - 1; i++)
        for (int j = 0; j < ec - i - 1; j++)
            if (evens[j] > evens[j + 1]) swap(evens[j], evens[j + 1]);
    // Сортируем нечетные по убыванию
    for (int i = 0; i < oc - 1; i++)
        for (int j = 0; j < oc - i - 1; j++)
            if (odds[j] < odds[j + 1]) swap(odds[j], odds[j + 1]);
    // Объединяем обратно
    int e = 0, o = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) arr[i] = evens[e++];
        else arr[i] = odds[o++];
    }
}

// 5. Сортировка интервала по возрастанию
void sortRangeAsc(int arr[], int n, int N1, int N2) {
    if (N1 < 0) N1 = 0;
    if (N2 >= n) N2 = n - 1;
    for (int i = N1; i < N2; i++) {
        for (int j = N1; j < N2 - (i - N1); j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

// 6. Сортировка интервала по убыванию
void sortRangeDesc(int arr[], int n, int N1, int N2) {
    if (N1 < 0) N1 = 0;
    if (N2 >= n) N2 = n - 1;
    for (int i = N1; i < N2; i++) {
        for (int j = N1; j < N2 - (i - N1); j++) {
            if (arr[j] < arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

int main() {
    int mas[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int n = sizeof(mas) / sizeof(int);
    int temp[13];
    
    cout << "Исходный массив: ";
    printArray(mas, n);
    
    // 1. Сортировка мини-макс
    copy(mas, mas + n, temp);
    sortMinMax(temp, n);
    cout << "Мини-макс:      ";
    printArray(temp, n);
    
    // 2. Пузырьковая
    copy(mas, mas + n, temp);
    sortBubble(temp, n);
    cout << "Пузырьковая:    ";
    printArray(temp, n);
    
    // 3. Быстрая
    copy(mas, mas + n, temp);
    sortQuick(temp, 0, n - 1);
    cout << "Быстрая:        ";
    printArray(temp, n);
    
    // 4. Четные по возрастанию, нечетные по убыванию
    copy(mas, mas + n, temp);
    sortEvenAscOddDesc(temp, n);
    cout << "Четн/Нечетн:    ";
    printArray(temp, n);
    
    // 5. Сортировка интервала по возрастанию (индексы 3-9)
    copy(mas, mas + n, temp);
    sortRangeAsc(temp, n, 3, 9);
    cout << "Интервал asc:   ";
    printArray(temp, n);
    
    // 6. Сортировка интервала по убыванию (индексы 3-9)
    copy(mas, mas + n, temp);
    sortRangeDesc(temp, n, 3, 9);
    cout << "Интервал desc:  ";
    printArray(temp, n);
    
    getch();
    return 0;
}