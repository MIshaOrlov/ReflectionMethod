//
//  main.cpp
//  somecode6.1
//
//  Created by Михаил on 27.09.2023.
//

#include <iostream>
#include "MatrixHandlers.h"
#include "ReflectionMethod.h"

using namespace std;

int main(int argc, char* argv[]) {
    int res;
    if (argc < 4) {
            cout << "Недостаточно аргументов командной строки." << endl;
            return 1;
        }

    int n = atoi(argv[1]); // Размерность матрицы
    int m = atoi(argv[2]); // Количество выводимых значений
    int k = atoi(argv[3]); // Номер формулы для инициализации матрицы
    const char* filename = nullptr;
    
    if (k == 0) {
        if (argc != 5) {
            cout << "Недостаточно аргументов командной строки для k=0." << endl;
            return 1;
        }
        filename = argv[4]; // Имя файла для чтения матрицы
    } else {
        if (argc != 4) {
            cout << "Недостаточно аргументов командной строки для k!=0." << endl;
            return 1;
        }
    }
    double* matrix = new double[n*n];
    double* adjoint = new double[n*n];
    double* temp = new double[n*n];
    
    
    if (k == 0) {
        res = inputMatrix(matrix, n, filename);
        switch (res) {
            case 1:
                break;
            case -1:
                cout << "Ошибка: Матрица в файле имеет неправильный формат." <<endl;
                return -1;
                break;
            case -2:
                cout << "Ошибка: Размер матрицы в файле не соответствует указанному размеру." << endl;
                return -1;
                break;
            case -3:
                cout << "Ошибка открытия файла." << endl;
                return -1;
                break;
            
            default:
                cout << "Неизвестная ошибка." << endl;
                return -1;
                break;
        }
        } else if (k > 0 && k < 5) {
            CreateMatrix(matrix, n,k);
        } else {
            cout << "Неподдерживаемый номер формулы k." << endl;
            return 1;
        }

    for (int i = 0; i < n*n; i++) {
        temp[i] = matrix[i];
    }

    printMatrix(temp, n, m );
    clock_t t;
    t = clock();
     res = ReflectionInverse(n,temp,adjoint);
    if (res == -1){
        std::cout<<"Не существует обратной матрицы"<<std::endl;
    } else {
        t = clock() - t;
        cout<<"Время работы алогиртма в секундах t : "<< t * 1.0/ CLOCKS_PER_SEC<<endl;
        printMatrix(adjoint, n,m );
        cout<<"Норма невязки ||A*Aˆ(-1)-E|| : "<< ResidualCalc(matrix,adjoint,temp,n) <<endl;
        
    }

   
    cout << "⠄⠄⠄⠄⢀⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄" << endl;
    cout << "⠄⠄⠘⠿⣿⣿⠄⠄⠄⠄⠄⠄⠄⠄⠄" << endl;
    cout << "⠄⠄⠄⠄⣿⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄" << endl;
    cout << "⠄⠄⠄⣀⣿⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄" << endl;
    cout << "⠄⠄⠄⡏⣿⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄" << endl;
    cout << "⠄⠄⢀⣀⣀⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄" << endl;
    cout << "⠄⠄⢸⣿⣿⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄" << endl;
    cout << "⠄⠄⣸⣿⣿⣷⠄⠄⠄⠄⠄⠄⠄⠄⠄" << endl;
    cout << "⠄⠄⣿⣿⣿⣿⠄⠄⠄⠄⠄⣤⣄⠄⠄" << endl;
    cout << "⠄⢀⣈⣉⣉⠉⠄⠄⣀⣴⣾⣿⣿⡿⠂" << endl;
    cout << "⠄⢸⣿⣿⣿⡇⢰⣿⣿⣿⣿⡿⠋⠄⠄" << endl;
    cout << "⠄⠸⣿⣿⣿⡇⢸⠿⠟⠋⠁⠄⠄⠄⠄" << endl;
    cout << "⠄⠄⣿⣿⣿⣤⣄⠄⠄⠄⠄⠄⠄⠄⠄" << endl;
    cout << "⠄⠄⣿⣿⣿⡏⢹⠄⠄⠄⠄⠄⠄⠄⠄" << endl;
    cout << "⠄⠄⣿⣿⣿⣷⣾⡀⠄⠄⠄⠄⠄⠄⠄" << endl;
    cout << "⠄⠄⠻⣿⣿⡿⢿⣿⣷⣦⠄⠄⠄⠄⠄" << endl;
    cout << "⠄⠄⠄⣤⣤⣤⠄⠉⠻⠋⠄⠄⠄⠄⠄" << endl;
    cout << "⠄⠄⠄⣿⣿⣿⡆⠄⠄⠄⠄⠄⠄⠄⠄" << endl;
    cout << "⠄⠄⠄⣿⣿⣿⣿⡀⠄⠄⠄⠄⠄⠄⠄" << endl;
    cout << "⠄⠄⠄⣿⣿⣿⣿⣧⠄⠄⠄⠄⠄⠄⠄" << endl;
    cout << "⠄⠄⠄⣿⣿⣿⣿⣿⡆⠄⠄⠄⠄⠄⠄" << endl;
    cout << "⠄⠄⠄⠻⠿⠿⠿⠿⠿⠄⠄⠄⠄⠄⠄" << endl;
    cout << "⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄" << endl;
    
    deleteMatrix(matrix);
    deleteMatrix(temp);
    deleteMatrix(adjoint);
//    сделать мейкфалов Сделано.
//    добавить вывод 4 на 4 Сделано.
//    убрать выводыя Сделано.
//   добавить исключения Сделано.
//    ускорить работу 
    return 0;
}
