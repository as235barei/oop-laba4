#include <iostream>
#include <vector>

class SquareMatrix {
private:
	int size;
	std::vector<std::vector<double>> matrix;

public:
	// Конструктор за замовчуванням, який створює порожню квадратну матрицю заданого розміру зі значенням всіх елементів "0".
	SquareMatrix(int n) : size(n), matrix(std::vector<std::vector<double>>(n, std::vector<double>(n, 0))) {}

	// Метод для отримання розміру матриці
	int getSize() const {
		return size;
	}

	// Метод для отримання елементу матриці
	double getElement(int row, int col) const {
		return matrix[row][col];
	}

	// Метод для встановлення значення елемента матриці
	void setElement(int row, int col, double value) {
		matrix[row][col] = value;
	}

	// Метод для транспонування матриці
	SquareMatrix transpose() const {
		SquareMatrix result(size);
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				result.setElement(i, j, matrix[j][i]);
			}
		}
		return result;
	}

	// Перевизначення оператора '+' для складання матриць (Перегрузка оператора "+")
	SquareMatrix operator+(const SquareMatrix& other) const {
		SquareMatrix result(size);
		for (int i = 0; i < size; ++i) { // ітерується по рядках матриць
			for (int j = 0; j < size; ++j) { // ітерується по стовпцях матриць
				result.setElement(i, j, matrix[i][j] + other.getElement(i, j));
			}
		}
		return result;
	}

	// Виведення матриці на екран
	void print() const {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				std::cout << matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
};

int main() {
	// Cтворення квадратної матриці розміром 3x3
	SquareMatrix A(3);
	// ряд 1 
	A.setElement(0, 0, 1); //(рядок, стовпчик, значення)
	A.setElement(0, 1, 3);
	A.setElement(0, 2, 5);
	// ряд 2
	A.setElement(1, 0, 7);
	A.setElement(1, 1, 4);
	A.setElement(1, 2, 6);
	// ряд 3
	A.setElement(2, 0, 8);
	A.setElement(2, 1, 9);
	A.setElement(2, 2, 2);


	std::cout << "Matrix A:" << std::endl;
	A.print();

	std::cout << "\nTranspose of Matrix A:" << std::endl;
	SquareMatrix A_transpose = A.transpose();
	A_transpose.print();

	std::cout << "\nAgain Matrix A:" << std::endl;
	A.print();

	// Створення другої матриці
	SquareMatrix B(3);
	// ряд 1
	B.setElement(0, 0, 9);//(рядок, стовпчик, значення)
	B.setElement(0, 1, 8);
	B.setElement(0, 2, 7);
	// ряд 2
	B.setElement(1, 0, 6);
	B.setElement(1, 1, 5);
	B.setElement(1, 2, 4);
	// ряд 3
	B.setElement(2, 0, 3);
	B.setElement(2, 1, 2);
	B.setElement(2, 2, 1);

	std::cout << "\nMatrix B:" << std::endl;
	B.print();

	// Cкладання матриць
	std::cout << "\nMatrix A + Matrix B:" << std::endl;
	SquareMatrix S = A + B;
	S.print();


	// Створення третьої матриці розміром 2x2
	SquareMatrix C(2);
	// ряд 1
	C.setElement(0, 0, 1);//(рядок, стовпчик, значення)
	C.setElement(0, 1, 2);
	// ряд 2
	C.setElement(1, 0, 3);
	C.setElement(1, 1, 4);

	std::cout << "\nMatrix C:" << std::endl;
	C.print();

	// Створення четвертої матриці розміром 2x2
	SquareMatrix V(2);
	// ряд 1
	V.setElement(0, 0, 2);//(рядок, стовпчик, значення)
	V.setElement(0, 1, 3);
	// ряд 2
	V.setElement(1, 0, 4);
	V.setElement(1, 1, 5);

	std::cout << "\nMatrix V:" << std::endl;
	V.print();

	std::cout << "\nMatrix C + Matrix V:" << std::endl;
	SquareMatrix Y = C + V;
	Y.print();

	std::cout << "\nTranspose of Matrix Y:" << std::endl;
	SquareMatrix Y_transpose = Y.transpose();
	Y_transpose.print();


	return 0;
}
