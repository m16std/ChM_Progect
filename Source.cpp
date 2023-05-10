#include "Header.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout.precision(4);
	std::vector <double> x = { 20,30,40 };   //результаты
	std::vector <double> grad;              //градиент функции
	std::vector <double> napr;             //направление
	int n = 3;
	double e = 0.001;               //точность
	double Y = 10000;              //минимальное значение
	double** H = new double* [n]; //матрица Гессе
	double temp;
	int MaxIter = 200;       //допустимое количество итераций
	int CurrentIter = 0;    //текущее количество

	while (1)
	{
		grad = Gradient(x, n);
		H = Hessian(x, n);
		napr = Direction(H, Y, grad, n);        // градиент и Гесссиан можно было получать прямо в этой скобке без доп. переменных
		temp = funck(x);                       // фиксируем значение функции до сдвига
		Log_out(x, napr, temp, n);            // отправка инфы в консоль
		fori x[i] += napr[i];                // сдвигаем x 
		funck(x) < temp ? Y /= 2: Y *= 2;   // если значение уменьшилось, то уменьшаем лямду, иначе увеличиваем
		CurrentIter++;
		if (CurrentIter > MaxIter || abs(Norm(grad)) < e)  // выхдим из цикла если слишком много итераций или сдвиг меньше чем точность
			break;
	}

	std::cout << "\nОтвет:\nТочка:";
	fori
		std::cout << x[i] << "\t";
	std::cout << std::endl;
	std::cout << "Значение: ";
	std::cout << temp;
	std::cout << std::endl;
	std::cout << "Количество итераций: " << CurrentIter << std::endl;
	return 0;
}