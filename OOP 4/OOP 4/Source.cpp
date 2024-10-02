#include <vector>
#include <iostream>

template <typename Type>

class Matrix {
public:
	std::vector<std::vector<Type>> _matrix;
	int _rows;
	int _columns;


	Matrix(int rows, int columns) : _rows(rows), _columns(columns), _matrix(rows, std::vector<Type>(columns)) {}

	std::vector<Type>& operator [] (int i) {
		return _matrix[i];
	}

	Matrix<Type> operator + (Matrix<Type>& other) {
		if (!(_rows == other._rows && _columns == other._columns)) {
			std::cout << "Matrices have different sizes";
			return Matrix<Type>(0, 0);
		}

		Matrix resultMatrix(_rows, other._columns);
		for (int i = 0; i < _rows; i++) {
			for (int j = 0; j < other._columns; j++) {
				resultMatrix[i][j] = _matrix[i][j] + other[i][j];
			}
		}
		return resultMatrix;
	}

	Matrix<Type> operator - (Matrix<Type>& other) {
		if (!(_rows == other._rows && _columns == other._columns)) {
			std::cout << "Matrices have different sizes";
			return Matrix<Type>(0, 0);
		}

		Matrix resultMatrix(_rows, other._columns);
		for (int i = 0; i < _rows; i++) {
			for (int j = 0; j < other._columns; j++) {
				resultMatrix[i][j] = _matrix[i][j] - other[i][j];
			}
		}
		return resultMatrix;
	}

	Matrix<Type> operator * (Matrix<Type>& other) {
		if (!(_rows == other._columns && _columns == other._rows)) {
			std::cout << "Matrices have different sizes";
			return Matrix<Type>(0, 0);
		}

		Matrix resultMatrix(_rows, other._columns);
		for (int i = 0; i < _rows; i++) {
			for (int j = 0; j < other._columns; j++) {
				for (int k = 0; k < _columns; k++) {
					resultMatrix[i][j] += _matrix[i][k] * other[k][j];
				}
			}
		}
		return resultMatrix;
	}

	void matrixPrint() {
		for (int i = 0; i < _rows; i++) {
			for (int j = 0; j < _columns; j++) {
				std::cout << _matrix[i][j] << " ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}

	Matrix<Type> matrixTranspose() {
		Matrix<Type> transposedMatrix(_columns, _rows);
		for (int i = 0; i < _columns; i++) {
			for (int j = 0; j < _rows; j++) {
				transposedMatrix[i][j] = _matrix[j][i];
			}
		}
		return transposedMatrix;
	}
};

int main() {
	int rows = 2, columns = 3;

	Matrix<int> A(rows, columns);
	Matrix<int> B(rows, columns);
	Matrix<int> C(rows, columns);
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			A[i][j] = (j - i) * j;
			B[i][j] = i + j;
		}
	}

	A[1][1] = 6;
	B[1][1] = 8;

	A.matrixPrint();
	B.matrixPrint();

	B = B.matrixTranspose();

	C = A * B;
	C.matrixPrint();

	B = B.matrixTranspose();

	C = A + B;
	C.matrixPrint();

	C = A - B;
	C.matrixPrint();
}