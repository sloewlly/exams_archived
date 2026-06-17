#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

template <typename T> class SquareMatrix {
    private:
    int size;
    std::vector<std::vector<T>> matrix;
    public:
    SquareMatrix(int n) : size(n), matrix(n, std::vector<T>(n)) {};
    int getSize() { return size; }
    void defaultMatrix() {
        for (int i = 0; i < size; i++) { 
            for (int j = 0; j < size; j ++) {
                matrix[i][j] = 0.0;
            }
        }
    }
    void Matrix(T value) {
        for (int i = 0; i < size; i++) { 
            for (int j = 0; j < size; j ++) {
                matrix[i][j] = value;
            }
        }
    }
    void overrideValue(int row, int col, T value) {
        if (row >= 0 && row < size && col >= 0 && col < size) {
        matrix[row][col] = value;
        } else {
        throw std::runtime_error("Invalid inputs!");
        }
    }
    void frobeniusNorm() {
        double sum = 0.0;
        for (int i = 0; i < size; i++) { 
            for (int j = 0; j < size; j ++) {
                sum += std::pow(std::abs(matrix[i][j]), 2);
            }
        }
        std::cout << "Frobenius Norm: " << sqrt(sum) << std::endl; 

    }
    void totalNorm() const {
        std::vector<T> absolute_matrix;
        for (size_t i = 0; i < size; i++){
            for (size_t j = 0; j < size; j++){
                absolute_matrix.push_back(size * (std::abs(matrix[i][j])));
            }
        }
        
        auto it = std::max_element(absolute_matrix.begin(), absolute_matrix.end());
        if (it != absolute_matrix.end()){
            std::cout << "Total Norm: " << *it << std::endl;
        }
    }
    void rowSumNorm() const {
        std::vector<double> rows_sum;
        for (size_t i = 0; i < size; i++){
            double sum = 0.0;
            for (size_t j = 0; j < size; j++){
                sum += std::abs(matrix[i][j]);
            }
            rows_sum.push_back(sum);
        }
        
        auto it = max_element(rows_sum.begin(), rows_sum.end());
        if (it != rows_sum.end()){
            std::cout << "Row Sum Norm: " << *it << std::endl;
        }
    }
    void display() {
        for (int i = 0; i < size; i++) { 
            for (int j = 0; j < size; j ++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    SquareMatrix<double> doubleMatrix(3);
    doubleMatrix.Matrix(9);
    
    std::cout << "Matrix:" << std::endl;
    doubleMatrix.display();
    std::cout << std::endl;
    
    doubleMatrix.overrideValue(1, 2, 5.9);
    doubleMatrix.frobeniusNorm();
    doubleMatrix.rowSumNorm();
    doubleMatrix.totalNorm();
    
    return 0;
}