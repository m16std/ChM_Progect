#pragma once
#include <vector>
#include <iostream>
#include <math.h>
#include <cmath>

#define fori for (int i = 0; i < n; i++) //не бейте пж
#define forj for (int j = 0; j < n; j++)
#define fork for (int k = 0; k < n; k++)

double funck(std::vector <double> x) //исследуемая функция
{
	return pow(x[0] + 2, 2) + pow(x[1] - 5, 2) + pow(x[2] + 10, 2);
}

double Der(std::vector <double> x, int k) //вычисление производной
{
	double y1, y0;
	x[k] += 0.000001;
	y1 = funck(x);
	x[k] -= 0.000002;
	y0 = funck(x);
	x[k] += 0.000001;
	return((y1 - y0) / 0.000002);
}

double Sec_Der(std::vector <double> x, int k1, int k2) //вычисление второй производной
{
	double der1, der0;
	x[k2] += 0.000001;
	der1 = Der(x, k1);
	x[k2] -= 0.000002;
	der0 = Der(x, k1);
	x[k2] += 0.000001;
	return((der1 - der0) / 0.000002);
}

std::vector <double> Gradient(std::vector <double> x, int n) //вычисление градиента
{
	std::vector <double> grad;

	fori grad.push_back(Der(x, i));

	return grad;
}

double Norm(std::vector<double> grad) //вычисление длины вектора (градиента)
{
	double sum = 0;
	int n = grad.size();

	fori sum += pow(grad[i],2);

	return sqrt(sum);
}

double** Hessian(std::vector <double> x, int n) //вычисление матрицы вторых производных (Гессиана функции)
{
	double** Hess = new double* [n];
	fori Hess[i] = new double[n];

	fori
		forj
		Hess[i][j] = Sec_Der(x, i, j);

	return Hess;
}

void Set_E(double** E, int n) //создание единичной матрицы
{
	fori
		E[i] = new double[n];

	fori
		forj
		if (i == j)
			E[i][j] = 1;
		else
			E[i][j] = 0;
}

double** Inversion(double** A, int n) //нахождение братной матрицы
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
	double** invMatrix; //обратная Т матрица
	double** E = new double* [n]; //единичная матрица
	Set_E(E, n);
	double sum = 0;
	std::vector <double> s(n);//направление

	fori
		forj
			E[i][j] *= Y;                     //умножаем единичную матрицу на лямду
	
	fori
		forj
			Hess[i][j] += E[i][j];            //складывам гессиам и единичную матрицу

	invMatrix = Inversion(Hess, n);           //находим обратную

	fori
		forj
		invMatrix[i][j] *= -1;                //умножаем её на -1

	fori
	{
		forj
			sum += invMatrix[i][j] * grad[j]; //умножаем её на градиент

		s[i] = sum;
		sum = 0;
	}

	return s;
}

void Log_out(std::vector <double> x, std::vector <double> naprl, double temp, int n)
{
	std::cout.precision(4);
	std::cout << "Точка: ";
	fori
		std::cout << x[i] << "\t";
	std::cout << std::endl;

	std::cout << "Направление: ";
	fori
		std::cout << naprl[i] << "\t";
	std::cout << std::endl;

	std::cout << "Значение: ";
	std::cout << temp;
	std::cout << std::endl;
	std::cout << std::endl;
}

void Finished_log_out(std::vector <double> x, int CurrentIter, double temp, int n)
{
	std::cout.precision(4);
	std::cout << "\n\t///Ответ///\nТочка:";
	fori
		std::cout << x[i] << " ";
	std::cout << std::endl;
	std::cout << "Значение: ";
	std::cout << temp;
	std::cout << std::endl;
	std::cout << "Количество итераций: " << CurrentIter << std::endl;
}