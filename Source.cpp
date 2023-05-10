#include "Header.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout.precision(4);
	std::vector <double> x = { 20,30,40 };   //����������
	std::vector <double> grad;              //�������� �������
	std::vector <double> napr;             //�����������
	int n = 3;
	double e = 0.001;               //��������
	double Y = 10000;              //����������� ��������
	double** H = new double* [n]; //������� �����
	double temp;
	int MaxIter = 200;       //���������� ���������� ��������
	int CurrentIter = 0;    //������� ����������

	while (1)
	{
		grad = Gradient(x, n);
		H = Hessian(x, n);
		napr = Direction(H, Y, grad, n);        // �������� � �������� ����� ���� �������� ����� � ���� ������ ��� ���. ����������
		temp = funck(x);                       // ��������� �������� ������� �� ������
		Log_out(x, napr, temp, n);            // �������� ���� � �������
		fori x[i] += napr[i];                // �������� x 
		funck(x) < temp ? Y /= 2: Y *= 2;   // ���� �������� �����������, �� ��������� �����, ����� �����������
		CurrentIter++;
		if (CurrentIter > MaxIter || abs(Norm(grad)) < e)  // ������ �� ����� ���� ������� ����� �������� ��� ����� ������ ��� ��������
			break;
	}

	std::cout << "\n�����:\n�����:";
	fori
		std::cout << x[i] << "\t";
	std::cout << std::endl;
	std::cout << "��������: ";
	std::cout << temp;
	std::cout << std::endl;
	std::cout << "���������� ��������: " << CurrentIter << std::endl;
	return 0;
}