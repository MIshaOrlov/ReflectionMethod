//
//  MatrixHandlers.cpp
//  somecode6.2
//
//  Created by Михаил on 11.10.2023.
//

#include "MatrixHandlers.h"
#include <sstream>


// Функция для вычисления элемента матрицы по формуле
double calculateElement(int k, int n, int i, int j) {
    double result = 0.0;

    if (k == 1) {
        result = n - std::max(i, j) + 1;
    } else if (k == 2) {
        result = std::max(i, j);
    } else if (k == 3) {
        result = std::abs(i - j);
    } else if (k == 4) {
        result = 1.0 / (i + j - 1);
    } else {
        //std::cout<< "Недопустимый номер формулы." << std::endl;
        return -1;
    }

    return result;
}

// Функция для создания по формуле
void CreateMatrix(double* matrix, int n, int k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i * n + j] = calculateElement(k, n, i + 1, j + 1); // i и j начинаются с 1
        }
    }
}


// Функция для чтения из файла
int inputMatrix(double* matrix, int n, const std::string& filename) {
    std::ifstream in(filename);
    // Если матрица прошла проверку, считываем ее
    in.open(filename);
    if (!in.is_open()) {
        return -3;
    }
    
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            in >> matrix[i * n + j];
            count++;
        }
    }

    if(count != n*n){
        return -2;
    }
    
    in.close();
    return 1;
}



// Функция для освобождения памяти, выделенной для матрицы
void deleteMatrix(double* matrix) {
    delete[] matrix;
}

// Функция для вывода матрицы
void printMatrix(double* matrix, int n,int m) {
    if(m == 0){
        std::cout<<"Здесь ничего нет("<<std::endl;
        return;
    }
    std::cout << "Матрица:" << std::endl;

    // Найти максимальную длину элемента матрицы
    double maxElement = matrix[0];
    for (int i = 0; i < n * n; ++i) {
        if (matrix[i] > maxElement) {
            maxElement = matrix[i];
        }
    }
    size_t maxElementWidth = std::to_string(maxElement).length();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << std::setw(int(maxElementWidth)) << std::left << std::scientific << std::setprecision(3) << matrix[i * n + j] << " ";
        }
        std::cout << std::endl;
    }
}

// Функция для транспонирования матрицы
void transposeMatrix(double* matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // Меняем местами элементы [i][j] и [j][i]
            std::swap(matrix[i * n + j], matrix[j * n + i]);
        }
    }
}

// Функция для вычисления максимальной столбичной нормы матрицы
double calculateColumnNorm(double* matrix, int n) {
    double maxNorm = 0.0;
    
    for (int j = 0; j < n; ++j) {
        double columnSum = 0.0;
        for (int i = 0; i < n; ++i) {
            columnSum += std::abs(matrix[i * n + j]);
        }
        
        if (columnSum > maxNorm) {
            maxNorm = columnSum;
        }
    }
    
    return maxNorm;
}

// Функция для вычисления максимальной строчной нормы матрицы
double calculateRowNorm(double* matrix, int n) {
    double maxNorm = 0.0;
    
    for (int i = 0; i < n; ++i) {
        double rowSum = 0.0;
        for (int j = 0; j < n; ++j) {
            rowSum += std::abs(matrix[i * n + j]);
        }
        
        if (rowSum > maxNorm) {
            maxNorm = rowSum;
        }
    }
    
    return maxNorm;
}

