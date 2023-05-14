#pragma once
#include <vector>
#include <iostream>
#include <cmath>

#define fori for (int i = 0; i < n; i++) //не бейте пж
#define forj for (int j = 0; j < n; j++)
#define fork for (int k = 0; k < n; k++)

double funck(std::vector <double> x);

//Вычисление производной
double Der(std::vector <double> x, int k)
{
	double y1, y0;
	x[k] += 0.0000001;
	y1 = funck(x);
	x[k] -= 0.0000002;
	y0 = funck(x);
	x[k] += 0.0000001;
	return((y1 - y0) / 0.0000002);
}

//Вычисление второй производной
double Sec_Der(std::vector <double> x, int k1, int k2)
{
	double der1, der0;
	x[k2] += 0.0000001;
	der1 = Der(x, k1);
	x[k2] -= 0.0000002;
	der0 = Der(x, k1);
	x[k2] += 0.0000001;
	return((der1 - der0) / 0.0000002);
}

//Вычисление градиента
std::vector <double> Gradient(std::vector <double> x, int n)
{
	std::vector <double> grad;

	fori grad.push_back(Der(x, i));

	return grad;
}

//Вычисление длины вектора (градиента)
double Norm(std::vector<double> grad)
{
	double sum = 0;
	int n = grad.size();

	fori sum += pow(grad[i],2);

	return sqrt(sum);
}

//Вычисление матрицы вторых производных (Гессиана функции)
double** Hessian(std::vector <double> x, int n) 
{
	double** Hess = new double* [n];
	fori Hess[i] = new double[n];

	fori
		forj
		Hess[i][j] = Sec_Der(x, i, j);

	return Hess;
}

//Создание единичной матрицы
void Set_E(double** E, int n) 
{
	fori
		E[i] = new double[n];

	fori
		forj
		i == j ? E[i][j] = 1: E[i][j] = 0;
}

//Нахождение братной матрицы
double** Inversion(double** A, int n) 
{
	double temp;
	double** E = new double* [n];
	Set_E(E, n);

	fork
	{
		temp = A[k][k];

		forj
		{
			A[k][j] /= temp;
			E[k][j] /= temp;
		}

		for (int i = k + 1; i < n; i++)
		{
			temp = A[i][k];

			forj
			{
				A[i][j] -= A[k][j] * temp;
				E[i][j] -= E[k][j] * temp;
			}
		}
	}

	for (int k = n - 1; k > 0; k--)
	{
		for (int i = k - 1; i >= 0; i--)
		{
			temp = A[i][k];

			for (int j = 0; j < n; j++)
			{
				A[i][j] -= A[k][j] * temp;
				E[i][j] -= E[k][j] * temp;
			}
		}
	}

	return E;
}

//Нахождение направления
std::vector <double> Direction(double** Hess, double Y, std::vector <double> grad, int n)
{
	int i, j;
	double** invMatrix;           //Обратная Т матрица
	double** E = new double* [n]; //Единичная матрица
	Set_E(E, n);
	double sum = 0;
	std::vector <double> trend(n);//Направление

	fori
		forj
			E[i][j] *= Y;                     //Умножаем единичную матрицу на лямбду
	
	fori
		forj
			Hess[i][j] += E[i][j];            //Складывам гессиам и единичную матрицу

	invMatrix = Inversion(Hess, n);           //Находим обратную

	fori
		forj
		invMatrix[i][j] *= -1;                //Умножаем её на -1

	fori
	{
		forj
			sum += invMatrix[i][j] * grad[j]; //Умножаем её на градиент

		trend[i] = sum;
		sum = 0;
	}

	return trend;
}

//Вывод промежуточных точек
void Log_out(std::vector <double> x, std::vector <double> trend, double temp, int n, double e)
{
	std::cout.precision(log10(1 / e) + 2);
	std::cout << "Точка: ";
	fori
		std::cout << ((int)(x[i] / e)) * e << "\t";
	std::cout << std::endl;

	std::cout << "Направление: ";
	fori
		std::cout << ((int)(trend[i] / e)) * e << "\t";
	std::cout << std::endl;

	std::cout << "Значение: ";
	std::cout << temp;
	std::cout << std::endl;
	std::cout << std::endl;
}

//Вывод результата
void Finished_log_out(std::vector <double> x, int CurrentIter, double temp, int n, double e)
{
	std::cout << "\n\t///Ответ///\nТочка:";
	fori
		std::cout << ((int)(x[i] / e)) * e << " ";
	std::cout << std::endl;
	std::cout << "Значение: ";
	std::cout << ((int)(temp / e)) * e;
	std::cout << std::endl;
	std::cout << "Количество итераций: " << CurrentIter << std::endl;
}