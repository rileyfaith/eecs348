#include <iostream>
#include <fstream>
#include <iomanip>

const static int maxN = 100;
int N;
int matrixA[maxN][maxN], matrixB[maxN][maxN], resultMatrix[maxN][maxN];


void readM(const std::string& fileName) {
    
    std::ifstream file(fileName);

    if (!file) {
    std::cerr << "\nUnable to open file";
    return;
    }

    file >> N;

    for (int i=0; i < N; ++i) {
        for (int j=0; j < N; ++j) {
            file >> matrixA[i][j];
        }
    }
    for (int i=0; i < N; ++i) {
        for (int j=0; j < N; ++j) {
            file >> matrixB[i][j];
        }
    }

    file.close();
}

void printM(const int matrix[maxN][maxN]) {
    for (int i=0; i < N; ++i) {
        for (int j=0; j < N; ++j) {
            std::cout << std::setw(5) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

void addM(const int a[maxN][maxN], const int b[maxN][maxN], int result[maxN][maxN]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    std::cout << "\nResulting Matrix after Addition:\n";
    printM(result);
}

void multiplyM(const int a[maxN][maxN], const int b[maxN][maxN], int result[maxN][maxN]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    std::cout << "\nResulting Matrix after Multiplication:\n";
    printM(result);
}

void subtractM(const int a[maxN][maxN], const int b[maxN][maxN], int result[maxN][maxN]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
        std::cout << "\nResulting Matrix after Subtraction:\n";
    printM(result);
}

void updateElem(int matrix[maxN][maxN], int row, int col, int newValue) {
    if (row >= 0 && row < N && col >= 0 && col < N){
        matrix[row][col] = newValue;
        std::cout << "\nMatrix after element update:\n";
        printM(matrix);
    } else {
        std::cout << "\nInvalid row or column index.\n";
    }
}

void findMaxValue(const int matrix[maxN][maxN]) {
    int maxVal = matrix[0][0];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }
    std::cout << "\nMax Value in the Matrix: " << maxVal << "\n";
}

void transposeM(const int input[maxN][maxN], int result[maxN][maxN]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[j][i] = input[i][j];
        }
    }
    std::cout << "\nResulting Maxtrix after Transposition:\n";
    printM(result);
}

int main() {
    // std::string filename;
    int choice;
    // std::cout << "\nEnter File Name: ";
    // std::cin >> fileN;
    std::string fileN = "input.txt";
    readM(fileN);
    do {
        std::cout << "\nChoose an Operation:\n"
                  << "1. Print Matrices\n"
                  << "2. Add Matrices\n"
                  << "3. Multiply Matrices\n"
                  << "4. Subtract Matrices\n"
                  << "5. Update an Element from the first Matrix\n"
                  << "6. Get the Max Value of the first Matrix\n"
                  << "7. Transpose the first Matrix\n"
                  << "0. Exit\n"
                  << "Choice: ";
        std::cin >> choice;    
        std::cout << "\n";
        switch (choice) {
            case 1:
                std::cout << "\nFirst Matrix (A):\n";
                printM(matrixA);
                std::cout << "\nSecond Matrix (B):\n";
                printM(matrixB);
                break;
            case 2:
                addM(matrixA, matrixB, resultMatrix);
                break;
            case 3:
                multiplyM(matrixA, matrixB, resultMatrix);
                break;
            case 4:
                subtractM(matrixA, matrixB, resultMatrix);
                break;
            case 5: {
                    int row, col, newValue;
                    std::cout << "\nEnter row to update: ";
                    std::cin >> row;
                    std::cout << "\nEnter column to update: ";
                    std::cin >> col;
                    std::cout << "\nEnter new value: ";
                    std::cin >> newValue;
                    updateElem(matrixA, row, col, newValue);
                    break;
            }
            case 6:
                findMaxValue(matrixA);
                break;
            case 7:
                transposeM(matrixA, resultMatrix);
                break;
            case 0:
                break;
            default:
            std::cout << "Invalid choice. Please try again :( \n";
            break;
        }

    } while (choice != 0);

    return 0;

}
