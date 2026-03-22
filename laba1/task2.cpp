// Лабораторная работа №1, задание 2 
#include <stdio.h>

int main() {
    // Эксперимент с int
    printf("=== int ===\n");
    int i_arr[] = {10, 20, 30};
    int *i_ptr = i_arr;
    printf("Адрес: %p, Значение: %d\n", (void*)i_ptr, *i_ptr);
    i_ptr++;
    printf("После ++: %p, Значение: %d\n", (void*)i_ptr, *i_ptr);
    printf("Смещение: %d байт\n\n", sizeof(int));
    
    // Эксперимент с char
    printf("=== char ===\n");
    char c_arr[] = {'A', 'B', 'C'};
    char *c_ptr = c_arr;
    printf("Адрес: %p, Значение: %c\n", (void*)c_ptr, *c_ptr);
    c_ptr++;
    printf("После ++: %p, Значение: %c\n", (void*)c_ptr, *c_ptr);
    printf("Смещение: %d байт\n\n", (int)sizeof(char));
    
    // Эксперимент с double
    printf("=== double ===\n");
    double d_arr[] = {1.1, 2.2, 3.3};
    double *d_ptr = d_arr;
    printf("Адрес: %p, Значение: %.1f\n", (void*)d_ptr, *d_ptr);
    d_ptr++;
    printf("После ++: %p, Значение: %.1f\n", (void*)d_ptr, *d_ptr);
    printf("Смещение: %d байт\n", (int)sizeof(double));
    
    return 0;
}