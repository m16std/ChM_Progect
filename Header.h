#pragma once
#include <vector>
#include <iostream>
#include <math.h>
#include <cmath>

#define fori for (int i = 0; i < n; i++) //�� ����� ��
#define forj for (int j = 0; j < n; j++)
#define fork for (int k = 0; k < n; k++)

double funck(std::vector <double> x) //����������� �������
{
	return pow(x[0] + 2, 2) + pow(x[1] - 5, 2) + pow(x[2] + 10, 2);
}

double Der(std::vector <double> x, int k) //���������� �����������
{
	double y1, y0;
	x[k] += 0.000001;
	y1 = funck(x);
	x[k] -= 0.000002;
	y0 = funck(x);
	x[k] += 0.000001;
	return((y1 - y0) / 0.000002);
}

double Sec_Der(std::vector <double> x, int k1, int k2) //���������� ������ �����������
{
	double der1, der0;
	x[k2] += 0.000001;
	der1 = Der(x, k1);
	x[k2] -= 0.000002;
	der0 = Der(x, k1);
	x[k2] += 0.000001;
	return((der1 - der0) / 0.000002);
}

std::vector <double> Gradient(std::vector <double> x, int n) //���������� ���������
{
	std::vector <double> grad;

	fori grad.push_back(Der(x, i));

	return grad;
}

double Norm(std::vector<double> grad) //���������� ����� ������� (���������)
{
	double sum = 0;
	int n = grad.size();

	fori sum += pow(grad[i],2);

	return sqrt(sum);
}

double** Hessian(std::vector <double> x, int n) //���������� ������� ������ ����������� (�������� �������)
{
	double** Hess = new double* [n];
	fori Hess[i] = new double[n];

	fori
		forj
		Hess[i][j] = Sec_Der(x, i, j);

	return Hess;
}

void Set_E(double** E, int n) //�������� ��������� �������
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

double** Inversion(double** A, int n) //���������� ������� �������
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


//���������� �����������
std::vector <double> Direction(double** Hess, double Y, std::vector <double> grad, int n)
{
	int i, j;
	double** invMatrix; //�������� � �������
	double** E = new double* [n]; //��������� �������
	Set_E(E, n);
	double sum = 0;
	std::vector <double> s(n);//�����������

	fori
		forj
			E[i][j] *= Y;                     //�������� ��������� ������� �� �����
	
	fori
		forj
			Hess[i][j] += E[i][j];            //��������� ������� � ��������� �������

	invMatrix = Inversion(Hess, n);           //������� ��������

	fori
		forj
		invMatrix[i][j] *= -1;                //�������� � �� -1

	fori
	{
		forj
			sum += invMatrix[i][j] * grad[j]; //�������� � �� ��������

		s[i] = sum;
		sum = 0;
	}

	return s;
}

void Log_out(std::vector <double> x, std::vector <double> naprl, double temp, int n)
{
	std::cout.precision(4);
	std::cout << "�����: ";
	fori
		std::cout << x[i] << "\t";
	std::cout << std::endl;

	std::cout << "�����������: ";
	fori
		std::cout << naprl[i] << "\t";
	std::cout << std::endl;

	std::cout << "��������: ";
	std::cout << temp;
	std::cout << std::endl;
	std::cout << std::endl;
}

void Finished_log_out(std::vector <double> x, int CurrentIter, double temp, int n)
{
	std::cout.precision(4);
	std::cout << "\n\t///�����///\n�����:";
	fori
		std::cout << x[i] << " ";
	std::cout << std::endl;
	std::cout << "��������: ";
	std::cout << temp;
	std::cout << std::endl;
	std::cout << "���������� ��������: " << CurrentIter << std::endl;
}