
#include <iostream>

#include <math.h>

#include <conio.h>

using namespace std;

class matrix {

	float** a;

	int size;

public:

	matrix(int n = 0); // конструктор присваивания

	matrix(const matrix& t); // конструктор копирования

	~matrix(); // деструктор

	void input(int n); //Операция ввода данных с консоли

	void output();

	friend ostream& operator << (ostream& out, matrix& t);

	matrix operator + (const matrix& c); // сложение матриц

	matrix operator * (matrix& t); // произведение матрицы на матрицу

	matrix operator* (int k); // умножение матрицы на число

};

matrix::matrix(int n) {

	size = n;

	a = new float* [size];

	for (int i = 0; i < size; i++)

		a[i] = new float[size];

}

matrix::matrix(const matrix& t) {

	size = t.size;

	a = new float* [size];

	for (int i = 0; i < size; i++)

	{

		a[i] = new float[size];

	}

	for (int i = 0; i < size; i++)

	{

		for (int j = 0; j < size; j++)

		{

			a[i][j] = t.a[i][j];

		}

	}

}

matrix::~matrix()

{

	delete[]a;

}

matrix matrix :: operator + (const matrix& c)

{

	matrix t;

	t.size = size;

	t.a = new float* [size];

	for (int i = 0; i < size; i++) {

		t.a[i] = new float[size];

	}

	for (int i = 0; i < size; i++)

	{

		for (int j = 0; j < size; j++)

		{

			t.a[i][j] = a[i][j] + c.a[i][j];

		}

	}

	return t;

}

matrix matrix:: operator * (int n)

{

	matrix t;

	t.size = size;

	t.a = new float* [size];

	for (int i = 0; i < size; i++) {

		t.a[i] = new float[size];

	}

	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size; j++) {

			{

				t.a[i][j] = a[i][j] * n;

			}

		}

	}

	return t;

}

matrix matrix::operator * (matrix& t)

{

	matrix d;

	d.size = size;

	d.a = new float* [size];

	for (int i = 0; i < size; i++) {

		d.a[i] = new float[size];

	}

	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size; j++) {

			d.a[i][j] = 0;

			for (int k = 0; k < size; k++)

				d.a[i][j] += a[i][k] * t.a[k][j];

		}

	}

	return d;

};

void matrix::input(int n) //Операция ввода данных с консоли

{

	size = n;

	a = new float* [size];

	for (int i = 0; i < size; i++)

		a[i] = new float[size];

	cout << "Введите значения вектора: " << endl;

	for (int i = 0; i < size; i++)

	{

		for (int j = 0; j < size; j++)

		{

			cin >> a[i][j];

		}

	}

};

ostream& operator << (ostream& out, matrix& t)

{

	out << t.size << endl;

	for (int i = 0; i < t.size; i++)

	{

		for (int j = 0; j < t.size; j++)

		{

			out << t.a[i][j] << " ";

		}

		cout << endl;

	}

	return out;

};

void matrix::output() //Операция вывода в консоль

{

	cout << size << " на " << size << endl;

	for (int i = 0; i < size; i++)

	{

		for (int j = 0; j < size; j++)

		{

			cout << a[i][j] << " ";

		}

		cout << endl;

	}

}

int main()

{

	setlocale(LC_ALL, "Russian");

	int n, k = 0;

	cout << "Матрицы размером "; cin >> n; cout << n << " на " << n << endl;

	matrix z;

	matrix x;

	x.matrix::matrix(n);

	x.input(n);

	cout << endl;

	cout << x << endl;

	z.matrix::matrix(n);

	z.input(n);

	cout << endl;

	cout << z << endl;

	cout << "Сумма двух матриц: " << endl;

	x.operator+(z).output();

	cout << "Введите число n на которое необходимо умножить матрицу: ";

	cin >> k;

	x.operator*(k).output();

	cout << endl;

	cout << "Результат умножения матрица А на матрицу B: " << endl;

	x.operator*(z).output();

}