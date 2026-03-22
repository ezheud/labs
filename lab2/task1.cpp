// Лабораторная работа №2
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <cmath>
using namespace std;

#define N 5

// Прототипы всех функций
float min_matrix(float m[N][N]);
float max_matrix(float m[N][N]);
float min_lower_triangle(float m[N][N]);
float max_lower_triangle(float m[N][N]);
float min_upper_triangle(float m[N][N]);
float max_upper_triangle(float m[N][N]);
float min_main_diag(float m[N][N]);
float max_main_diag(float m[N][N]);
float min_secondary_diag(float m[N][N]);
float max_secondary_diag(float m[N][N]);
float avg_matrix(float m[N][N]);
float avg_lower_triangle(float m[N][N]);
float avg_upper_triangle(float m[N][N]);
void sum_rows(float m[N][N], float sums[]);
void sum_cols(float m[N][N], float sums[]);
void min_rows(float m[N][N], float mins[]);
void max_rows(float m[N][N], float maxs[]);
void min_cols(float m[N][N], float mins[]);
void max_cols(float m[N][N], float maxs[]);
void avg_rows(float m[N][N], float avgs[]);
void avg_cols(float m[N][N], float avgs[]);
void sum_lower_upper(float m[N][N], float &sum_lower, float &sum_upper);
float closest_to_average(float m[N][N]);

int main() {
    float m[N][N];
    int i, j;
    
    // Заполнение матрицы
    srand(12345);
    cout << "Исходная матрица " << N << "x" << N << ":\n";
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            m[i][j] = rand() % 100 / 10.0;
            cout << setw(8) << setprecision(4) << m[i][j];
        }
        cout << endl;
    }
    cout << endl;
    
    // Вывод результатов
    cout << "Минимум матрицы: " << min_matrix(m) << endl;
    cout << "Максимум матрицы: " << max_matrix(m) << endl;
    cout << "Среднее арифметическое: " << avg_matrix(m) << endl;
    cout << "Ближайший к среднему: " << closest_to_average(m) << endl << endl;
    
    cout << "Минимум главной диагонали: " << min_main_diag(m) << endl;
    cout << "Максимум главной диагонали: " << max_main_diag(m) << endl;
    cout << "Минимум второстепенной: " << min_secondary_diag(m) << endl;
    cout << "Максимум второстепенной: " << max_secondary_diag(m) << endl << endl;
    
    cout << "Нижний треугольник - мин: " << min_lower_triangle(m) 
         << ", макс: " << max_lower_triangle(m)
         << ", сред: " << avg_lower_triangle(m) << endl;
    cout << "Верхний треугольник - мин: " << min_upper_triangle(m) 
         << ", макс: " << max_upper_triangle(m)
         << ", сред: " << avg_upper_triangle(m) << endl << endl;
    
    float sum_low, sum_up;
    sum_lower_upper(m, sum_low, sum_up);
    cout << "Сумма нижнего треугольника: " << sum_low << endl;
    cout << "Сумма верхнего треугольника: " << sum_up << endl << endl;
    
    float row_sums[N], col_sums[N];
    sum_rows(m, row_sums);
    sum_cols(m, col_sums);
    
    cout << "Суммы строк: ";
    for (i = 0; i < N; i++) cout << row_sums[i] << " ";
    cout << endl << "Суммы столбцов: ";
    for (j = 0; j < N; j++) cout << col_sums[j] << " ";
    cout << endl;
    
    getch();
    return 0;
}

// ==================== РЕАЛИЗАЦИЯ ФУНКЦИЙ ====================

float min_matrix(float m[N][N]) {
    float min_val = m[0][0];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (m[i][j] < min_val) min_val = m[i][j];
    return min_val;
}

float max_matrix(float m[N][N]) {
    float max_val = m[0][0];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (m[i][j] > max_val) max_val = m[i][j];
    return max_val;
}

float min_lower_triangle(float m[N][N]) {
    float min_val = m[0][0];
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (m[i][j] < min_val) min_val = m[i][j];
    return min_val;
}

float max_lower_triangle(float m[N][N]) {
    float max_val = m[0][0];
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (m[i][j] > max_val) max_val = m[i][j];
    return max_val;
}

float min_upper_triangle(float m[N][N]) {
    float min_val = m[0][0];
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            if (m[i][j] < min_val) min_val = m[i][j];
    return min_val;
}

float max_upper_triangle(float m[N][N]) {
    float max_val = m[0][0];
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            if (m[i][j] > max_val) max_val = m[i][j];
    return max_val;
}

float min_main_diag(float m[N][N]) {
    float min_val = m[0][0];
    for (int i = 1; i < N; i++)
        if (m[i][i] < min_val) min_val = m[i][i];
    return min_val;
}

float max_main_diag(float m[N][N]) {
    float max_val = m[0][0];
    for (int i = 1; i < N; i++)
        if (m[i][i] > max_val) max_val = m[i][i];
    return max_val;
}

float min_secondary_diag(float m[N][N]) {
    float min_val = m[0][N-1];
    for (int i = 1; i < N; i++) {
        int j = N - 1 - i;
        if (m[i][j] < min_val) min_val = m[i][j];
    }
    return min_val;
}

float max_secondary_diag(float m[N][N]) {
    float max_val = m[0][N-1];
    for (int i = 1; i < N; i++) {
        int j = N - 1 - i;
        if (m[i][j] > max_val) max_val = m[i][j];
    }
    return max_val;
}

float avg_matrix(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sum += m[i][j];
    return sum / (N * N);
}

float avg_lower_triangle(float m[N][N]) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++) {
            sum += m[i][j];
            count++;
        }
    return sum / count;
}

float avg_upper_triangle(float m[N][N]) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++) {
            sum += m[i][j];
            count++;
        }
    return sum / count;
}

void sum_rows(float m[N][N], float sums[]) {
    for (int i = 0; i < N; i++) {
        sums[i] = 0;
        for (int j = 0; j < N; j++)
            sums[i] += m[i][j];
    }
}

void sum_cols(float m[N][N], float sums[]) {
    for (int j = 0; j < N; j++) {
        sums[j] = 0;
        for (int i = 0; i < N; i++)
            sums[j] += m[i][j];
    }
}

void min_rows(float m[N][N], float mins[]) {
    for (int i = 0; i < N; i++) {
        mins[i] = m[i][0];
        for (int j = 1; j < N; j++)
            if (m[i][j] < mins[i]) mins[i] = m[i][j];
    }
}

void max_rows(float m[N][N], float maxs[]) {
    for (int i = 0; i < N; i++) {
        maxs[i] = m[i][0];
        for (int j = 1; j < N; j++)
            if (m[i][j] > maxs[i]) maxs[i] = m[i][j];
    }
}

void min_cols(float m[N][N], float mins[]) {
    for (int j = 0; j < N; j++) {
        mins[j] = m[0][j];
        for (int i = 1; i < N; i++)
            if (m[i][j] < mins[j]) mins[j] = m[i][j];
    }
}

void max_cols(float m[N][N], float maxs[]) {
    for (int j = 0; j < N; j++) {
        maxs[j] = m[0][j];
        for (int i = 1; i < N; i++)
            if (m[i][j] > maxs[j]) maxs[j] = m[i][j];
    }
}

void avg_rows(float m[N][N], float avgs[]) {
    for (int i = 0; i < N; i++) {
        float sum = 0;
        for (int j = 0; j < N; j++)
            sum += m[i][j];
        avgs[i] = sum / N;
    }
}

void avg_cols(float m[N][N], float avgs[]) {
    for (int j = 0; j < N; j++) {
        float sum = 0;
        for (int i = 0; i < N; i++)
            sum += m[i][j];
        avgs[j] = sum / N;
    }
}

void sum_lower_upper(float m[N][N], float &sum_lower, float &sum_upper) {
    sum_lower = 0;
    sum_upper = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i >= j) sum_lower += m[i][j];
            if (i <= j) sum_upper += m[i][j];
        }
    }
    // Вычитаем диагональ (она посчитана дважды)
    for (int i = 0; i < N; i++) {
        sum_lower -= m[i][i];
        sum_upper -= m[i][i];
    }
}

float closest_to_average(float m[N][N]) {
    float avg = avg_matrix(m);
    float closest = m[0][0];
    float min_diff = fabs(m[0][0] - avg);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float diff = fabs(m[i][j] - avg);
            if (diff < min_diff) {
                min_diff = diff;
                closest = m[i][j];
            }
        }
    }
    return closest;
}