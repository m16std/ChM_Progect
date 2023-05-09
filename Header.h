#pragma once
#include <vector>
#include <iostream>
#include <math.h>
#include <cmath>

#define fori for (int i = 0; i < n; i++) //не бейте пж
#define forj for (int j = 0; j < n; j++)
#define fork for (int k = 0; k < n; k++)

double funck(std::vector <double> x)
{
	return pow(x[0] - 5, 3) - pow(x[1] - 4, 3) - pow(x[2] - 3, 3);
}

double Der(std::vector <double> x, int k)
{
	double y1, y0;
	x[k] += 0.0000001;
	y1 = funck(x);
	x[k] -= 0.0000002;
	y0 = funck(x);
	return((y1 - y0) / 0.0000001);
}

double Sec_Der(std::vector <double> x, int k1, int k2)
{
	double der1, der0;
	x[k2] += 0.0000001;
	der1 = Der(x, k1);
	x[k2] -= 0.0000002;
	der0 = Der(x, k1);
	return((der1 - der0) / 0.0000001);
}

std::vector <double> Gradient(std::vector <double> x, int n)
{
	std::vector <double> grad;

	fori Der(x, i);

	return grad;
}

double Norm(std::vector<double> grad)
{
	double sum = 0;
	int n = grad.size();

	fori sum += grad[i] * grad[i];

	return sqrt(sum);
}

double** Hessian(std::vector <double> x, int n)
{
	double** Hess = new double* [n];

	fori
		forj
		Hess[i][j] = Sec_Der(x, i, j);

	return Hess;
}

double** Set_E(double** E, int n)
{
	fori
	{
		E[i] = new double[n];
		forj
		{
			if (i == j)
				E[i][j] = 1;
			else
				E[i][j] = 0;
		}
	}
	return E;
}

double** Inversion(double** A, int n)
{
	double temp;

	double** E = new double* [n];

	fori
	{
			E[i] = new double[n];
	}
	

	fori
	{
		forj
		{
			E[i][j] = 0.0;
			if (i == j)
				E[i][j] = 1.0;
		}
	}

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

	return A;
}

//Нахождение направления
std::vector <double> Sk(double** Hess, double Y, double** I, std::vector <double> grad, int n)
{
	int i, j;
	double** invMatrix; //обратная Т матрица
	double sum = 0;
	std::vector <double> s(n);//направление
	fori
	{
		forj
		{
			if (i == j)
			{
				I[i][i] *= Y;
			}
		}
	}

		fori
		{
			forj
			{
				Hess[i][i] += I[i][i];

				if (i == j)
				{
					I[i][i] = 1;
				}
				else
				{
					I[i][i] = 0;
				}

			}
		}
		invMatrix = Inversion(Hess, n);

		fori
		{
			forj
			{
				invMatrix[i][j] *= -1;
			}
		}

			fori
			{
				forj
				{
					sum += invMatrix[i][j] * grad[j];
				}

			s[i] = sum;
			sum = 0;
			}


			return s;
}

