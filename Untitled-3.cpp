#include <iostream>
using namespace std;

template<typename T>
class Matrix {
private:
    int rows;
    int cols;
    T **data;
public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        data = new T*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
        }
    }

    Matrix(const Matrix& m) {
        rows = m.rows;
        cols = m.cols;
        data = new T*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = m.data[i][j];
            }
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    Matrix& operator=(const Matrix& m) {
        if (this == &m) {
            return *this;
        }
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
        rows = m.rows;
        cols = m.cols;
        data = new T*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = m.data[i][j];
            }
        }
        return *this;
    }

    T* operator[](int i) {
        return data[i];
    }

    Matrix operator+(const Matrix& m) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + m.data[i][j];
            }
        }
        return result;
    }

    Matrix& operator+=(const Matrix& m) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] += m.data[i][j];
            }
        }
        return *this;
    }

    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

template<typename T>
ostream& operator<<(ostream& os, const Matrix<T>& m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            os << m[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

int main() {
    Matrix<int> m1(2, 2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

  Matrix<int> m2(2, 2);
m2[0][0] = 5;
m2[0][1] = 6;
m2[1][0] = 7;
m2[1][1] = 8;

Matrix<int> m3 = m1 + m2;
m3 += m2;
cout << "Matrix m1:" << endl;
m1.print();
cout << "Matrix m2:" << endl;
m2.print();
cout << "Matrix m3:" << endl;
m3.print();

return 0;
}