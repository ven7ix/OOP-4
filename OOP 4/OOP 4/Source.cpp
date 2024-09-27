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

	void matrixSum(Matrix A, Matrix B) {
		for (int i = 0; i < _rows; i++) {
			for (int j = 0; j < _columns; j++) {
				_matrix[i][j] = A.matrixGetElement(i, j) + B.matrixGetElement(i, j);
			}
		}
	}

	Matrix matrixTranspose(Matrix matrix) {
		Matrix transposedMatrix(_columns, _rows);
		for (int i = 0; i < _rows; i++) {
			for (int j = 0; j < _columns; j++) {
				transposedMatrix.matrixSetElement(matrix.matrixGetElement(i, j), j, i);
			}
		}
		return transposedMatrix;
	}

	Matrix matrixMultiply(Matrix A, Matrix B) {
		Matrix resultMatrix(A._rows, B._columns);
		int res = 0;
		for (int i = 0; i < A._rows; i++) {
			for (int j = 0; j < B._columns; j++) {
				for (int k = 0; k < _columns; k++) {
					res += A.matrixGetElement(i, k) * B.matrixGetElement(k, j);
				}
				resultMatrix.matrixSetElement(res, i, j);
			}
		}
		return resultMatrix;
	}
};

int main() {
	int rows = 2, columns = 3;

	Matrix<int> A(rows, columns);
	A.matrixSetElement(6, 1, 1);

	Matrix<int> B(rows, columns);
	B.matrixSetElement(8, 1, 1);

	Matrix<int> C(rows, columns);
	C = C.matrixMultiply(A, B.matrixTranspose(B));
	C.matrixPrint();
}