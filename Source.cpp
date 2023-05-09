#include "Header.h"

#include <vector>
int main()
{
	setlocale(LC_ALL, "Russian");
	std::vector <double> x = {0,0,0};    //результаты
	std::vector <double> grad;           //градиент функции
	std::vector <double> naprl;          //направление
	int i, n = 3;
	double number, e;
	double Y = 10000;             //лямбда
	double** H = new double* [n]; //матрица Гессе
	double** I = new double* [n]; //единичная матрица
	bool flag = true;
	int iter = 50;       //допустимое количество итераций
	int currenttime = 0; //текущее количество

	for (i = 0; i < n; i++)
	{
		I[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				I[i][i] = 1;
			else
				I[i][i] = 0;
		}
	}
		return 0;
}