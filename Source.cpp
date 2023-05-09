#include "Header.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	std::vector <double> x = { 0,0,0 };    //результаты
	std::vector <double> grad;           //градиент функции
	std::vector <double> naprl;          //направление
	int n = 3;
	double number, e = 0.0001;
	double Y = 10000;             //минимальное значение
	double** H = new double* [n]; //матрица Гессе
	double** I = new double* [n]; //единичная матрица
	bool flag = true;
	int iter = 50;       //допустимое количество итераций
	int currentIter = 0; //текущее количество

	I = Set_E(I, n);
	/*
	fori
	{
		forj
		std::cout << I[i][j] << "\t";
		std::cout << std::endl;
	}
	*/

		

	while (currentIter < iter && Norm(grad) > e && !flag)
	{
		grad = Gradient(x, n);
		H = Hessian(x, n);
		naprl = Sk(H, Y, I, grad, n);

		std::cout << "Точка:";
		fori
			std::cout << x[i] << "\t";

		std::cout << "\nНаправление: ";
		fori
			std::cout << naprl[i] << "\t";

		std::cout << std::endl;

		double temp = funck(x);
		fori
			x[i] += naprl[i];

		if (funck(x) < temp)
		{
			flag = true;
			Y /= 2;
			currentIter++;
		}
		else
		{
			flag = false;
			Y *= 2;
		}
	}

	std::cout << "Точка:";
	fori
		std::cout << x[i] << "\t";
	std::cout << std::endl;
	std::cout << "Количество итераций: " << currentIter << std::endl;
	return 0;
}