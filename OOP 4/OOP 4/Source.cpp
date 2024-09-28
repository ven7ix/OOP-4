#include <vector>
#include <iostream>

template <typename Type>

class Matrix {

	std::vector<std::vector<Type>> _matrix;
	int _rows;
	int _columns;

public:
	Matrix(int rows, int columns) : _rows(rows), _columns(columns), _matrix(rows, std::vector<Type>(columns)) {}

	void matrixSetElement(Type element, int i, int j) {
		_matrix[i][j] = element;
	}

	Type matrixGetElement(int i, int j) {
		return _matrix[i][j];
	}

	void matrixPrint() {
		for (int i = 0; i < _rows; i++) {
			for (int j = 0; j < _columns; j++) {
				std::cout << _matrix[i][j] << " ";
			}
			std::cout << "\n";
		}
	}

	Matrix matrixTranspose() {
		Matrix transposedMatrix(_columns, _rows);
		for (int i = 0; i < _rows; i++) {
			for (int j = 0; j < _columns; j++) {
				transposedMatrix.matrixSetElement(_matrix[i][j], j, i);
			}
		}
		return transposedMatrix;
	}

	Matrix matrixSum(Matrix A, Matrix B) {
		Matrix resultMatrix(A._rows, A._columns);
		for (int i = 0; i < A._rows; i++) {
			for (int j = 0; j < A._columns; j++) {
				resultMatrix.matrixSetElement(A.matrixGetElement(i, j) + B.matrixGetElement(i, j), i, j);
			}
		}
		return resultMatrix;
	}

	Matrix matrixMultiply(Matrix A, Matrix B) {
		Matrix resultMatrix(A._rows, B._columns);
		for (int i = 0; i < A._rows; i++) {
			for (int j = 0; j < B._columns; j++) {
				int res = 0;
				for (int k = 0; k < A._columns; k++) {
					res += A.matrixGetElement(i, k) * B.matrixGetElement(k, j);
				}
				resultMatrix.matrixSetElement(res, i, j);
			}
		}
		return resultMatrix;
	}
};

int main() {
	int rows = 3, columns = 4;

	Matrix<int> A(rows, columns);
	Matrix<int> B(rows, columns);
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			B.matrixSetElement(i + j, i, j);
			A.matrixSetElement((j - i) * j, i, j);
		}
	}

	A.matrixSetElement(6, 1, 1);
	B.matrixSetElement(8, 1, 1);

	A.matrixPrint();
	B.matrixPrint();

	Matrix<int> C(3, 3);
	C = C.matrixSum(A, B);
	C.matrixPrint();
}