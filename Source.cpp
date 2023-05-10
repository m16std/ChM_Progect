#include "Header.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	std::vector <double> x = { 1,1,1 };    //Начальная точка (сюда же будет записана точка минимума)
	std::vector <double> grad;            //Градиент функции
	std::vector <double> napr;           //Направление
	int n = 3;                            //Количество переменных в функции
	double e = 0.0001;                   //Точность
	double Y = 10000;                   //Лямда (просто большое число для сходимости алгоритма)
	double** H = new double* [n];         //Матрица Гессе
	double temp;                         //Тут храним значение функции для сравнения значений до и после сдвига
	int MaxIter = 200;                  //Допустимое количество итераций
	int CurrentIter = 0;               //Текущее количество

	while (1)
	{
		grad = Gradient(x, n);                    // Вычисление Градиента
		H = Hessian(x, n);                       // Вычисление Гесссиана
		napr = Direction(H, Y, grad, n);        // Вычисление направления
		temp = funck(x);                       // Фиксируем значение функции до сдвига
		Log_out(x, napr, temp, n);            // Отправка инфы в консоль
		fori x[i] += napr[i];                // Сдвигаем x 
		funck(x) < temp ? Y /= 2 : Y *= 2;  // Если значение функции уменьшилось, то уменьшаем лямду, иначе увеличиваем
		CurrentIter++;
		if (CurrentIter > MaxIter || abs(Norm(grad)) < e)  // Выходим из цикла если слишком много итераций или сдвиг меньше чем точность
			break;
	}

	Finished_log_out(x, CurrentIter, temp, n); // Отправка финишноц инфы в консоль (без направления)
	return 0;
}