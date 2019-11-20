#ifndef MATRIX_H
#include <iostream>
#include <exception>
#include <stdexcept>
template<typename T>
class Matrix
{
private:
	T** elements;
	int rowCount;
	int columnCount;
public:
	Matrix(int rowCount, int columnCount);
	Matrix(const Matrix<T>& matrixToCopy);
	~Matrix();
	void Set(int row, int column, T valueSet);
	void SetFrom(T* arrayUsed);
	T& GetElement(int row, int column);
	T* GetElement(int row, int column) const;
	template<typename R>
	Matrix<R> Cast() const;

	Matrix Transpose() const;
	Matrix Multiply(const Matrix& matrix);
	Matrix Multiply(T scalar);
	Matrix Add(const Matrix& matrix);
	Matrix Add(T scalar);

	bool Equals(const Matrix& matrix) const;
	void Print() const;
};


template<typename T>
inline Matrix<T>::Matrix(int rowCount, int columnCount)
{
	this->rowCount = rowCount;
	this->columnCount = columnCount;
	this->elements = new T* [rowCount];
	for (int i = 0; i < rowCount; ++i)
		this->elements[i] = new T[columnCount];

	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			this->elements[i][j] = T{};
		}
	}
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& matrixToCopy) {
	this->rowCount = matrixToCopy.rowCount;
	this->columnCount = matrixToCopy.columnCount;
	this->elements = new T * [rowCount];
	for (int i = 0; i < rowCount; ++i)
		this->elements[i] = new T[columnCount];

	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			this->elements[i][j] = T{};
		}
	}

	try {
		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < columnCount; j++)
			{
				this->elements[i][j] = *matrixToCopy.GetElement(i, j);
			}
		}
	}catch (std::exception & e) {
		e.what();
	}
}

template<typename T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < rowCount; i++)
	{
		delete[] elements[i];
	}
	delete[] elements;
}

template<typename T>
void Matrix<T>::Set(int row, int column, T valueSet)
{
	if (row >= rowCount || column >= columnCount || row < 0 || column < 0)
		throw std::out_of_range("Accessing out of bounds!");

	 this->elements[row][column] = valueSet;
}

template<typename T>
void Matrix<T>::SetFrom(T* arrayUsed)
{
	int line = 0;
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			this->Set(row, column, arrayUsed[row * 3 + column]);
		}
	}
}

template<typename T>
T& Matrix<T>::GetElement(int row, int column)
{
	if(row >= rowCount || column >= columnCount || row < 0 || column < 0)
		throw std::out_of_range("Accessing out of bounds!");
	return elements[row][column];
}

template<typename T>
T* Matrix<T>::GetElement(int row, int column) const
{
	return &elements[row][column];
}


template<typename T>
Matrix<T> Matrix<T>::Transpose() const
{
	Matrix<T> trans{ rowCount,columnCount };
	for (int i = 0; i < rowCount; ++i)
		for (int j = 0; j < columnCount; ++j)
		{
			trans.Set(j, i, elements[i][j]);
		}
	return trans;
}

template<typename T>
Matrix<T> Matrix<T>::Multiply(const Matrix& matrix)
{
	if (matrix.columnCount != rowCount && matrix.rowCount != columnCount)
		throw std::invalid_argument("Invalid operation");

	Matrix<T> mult{ rowCount,columnCount };
	auto temp = 0;
	for (int i = 0; i < rowCount; ++i)
		for (int j = 0; j < matrix.columnCount; ++j)
			for (int k = 0; k < columnCount; ++k) {
				mult.GetElement(i,j) += elements[i][k] * *matrix.GetElement(k,j);
			}
	return mult;
}

template<typename T>
Matrix<T> Matrix<T>::Multiply(T scalar)
{
	Matrix<T> scalarMultiplied{ rowCount,columnCount };
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			scalarMultiplied.Set(i, j, elements[i][j] * scalar);
		}
	}
	return scalarMultiplied;
}

template<typename T>
Matrix<T> Matrix<T>::Add(const Matrix& matrix)
{
	if (matrix.rowCount != rowCount && matrix.columnCount != columnCount)
		throw std::invalid_argument("Invalid operation");

	Matrix<T> sum{ rowCount,columnCount };
	for (int i = 0; i < rowCount; ++i)
		for (int j = 0; j < columnCount; ++j)
			sum.Set(i, j, elements[i][j] + *matrix.GetElement(i, j));
	return sum;
}

template<typename T>
Matrix<T> Matrix<T>::Add(T scalar)
{
	Matrix<T> scalarAdded{ rowCount,columnCount };
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			scalarAdded.Set(i, j, elements[i][j] + scalar);
		}
	}
}

template<typename T>
bool Matrix<T>::Equals(const Matrix& matrix) const
{
	bool trigger = true;
	for (int i = 0; i < rowCount; ++i)
	{
		for (int j = 0; j < rowCount; ++j)
		{
			auto jahoda = elements[i][j];
			auto nasersi = *matrix.GetElement(i, j);
			if (elements[i][j] != *matrix.GetElement(i, j))
				trigger = false;
		}
	}
	return trigger;
}

template<typename T>
void Matrix<T>::Print() const
{
	for (int i = 0; i < rowCount; ++i)
	{
		for (int j = 0; j < columnCount; ++j)
		{
			std::cout << "[" << elements[i][j] << "] ";
		}
		std::cout << std::endl;
	}
}

template<typename T>
template<typename R>
inline Matrix<R> Matrix<T>::Cast() const
{
	Matrix<R> casted{ rowCount, columnCount };
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			casted.Set(i, j, elements[i][j]);
		}
	}
	return casted;
}

#endif // !MATRIX_H