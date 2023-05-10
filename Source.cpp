#include "Header.h"

double funck(std::vector <double> x) //исследуемая функция
{
	return (pow(x[0] - 4, 4) + pow(x[1] + 6, 3) + pow(x[2] - 10, 2)) + exp(x[3]);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::vector <double> grad;            //Градиент функции
	std::vector <double> napr;           //Направление
	int n = 4;                            //Количество переменных в функции
	double e = 0.0001;                   //Точность (лучше с запасом выставлять)
	double Y = 10000;                   //Лямда (просто большое число для сходимости алгоритма)
	double** H = new double* [n];         //Матрица Гессе
	std::vector <double> x;              //Начальная точка (сюда же будет записана точка минимума)
	fori x.push_back(1);                //Записываем начальную точку (все единички)
	double temp;                         //Тут храним значение функции для сравнения значений до и после сдвига
	int MaxIter = 100;                  //Допустимое количество итераций
	int CurrentIter = 0;               //Текущее количество итераций

	while (1)
	{
		grad = Gradient(x, n);                    // Вычисление Градиента
		H = Hessian(x, n);                       // Вычисление Гесссиана
		napr = Direction(H, Y, grad, n);        // Вычисление направления
		temp = funck(x);                          // Фиксируем значение функции до сдвига
		Log_out(x, napr, temp, n, e);            // Отправляем инфу в консоль
		fori x[i] += napr[i];                   // Сдвигаем x 
		funck(x) < temp ? Y /= 2 : Y *= 2;     // Если значение функции уменьшилось, то уменьшаем лямду, иначе увеличиваем
		CurrentIter++;
		if (CurrentIter > MaxIter || abs(Norm(grad)) < e)  // Выходим из цикла если слишком много итераций или сдвиг меньше чем точность
			break;
	}

	Finished_log_out(x, CurrentIter, temp, n, e); // Отправка финишной инфы в консоль (без направления)
	return 0;
}