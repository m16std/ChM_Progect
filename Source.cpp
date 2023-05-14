#include "Header.h"

double funck(std::vector <double> x) //����������� �������
{
	return cos(x[0])*pow(x[1]-20,2)+ pow(x[3] - 20, 2);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::vector <double> grad;            // �������� �������
	std::vector <double> trend;          // �����������
	int n = 3;                            // ���������� ���������� � �������
	double e = 0.00001;                  // �������� (����� � ������� ����������)
	double Y = 10000;                   // ������ (������ ������� ����� ��� ���������� ���������)
	double** H = new double* [n];         // ������� �����
	std::vector <double> x;              // ��������� ����� (���� �� ����� �������� ����� ��������)
	fori x.push_back(1);                // ���������� ��������� ����� (��� ��������)
	double temp;                         // ��� ������ �������� ������� ��� ��������� �������� �� � ����� ������
	int MaxIter = 100;                  // ���������� ���������� ��������
	int CurrentIter = 0;               // ������� ���������� ��������

	while (1)
	{
		grad = Gradient(x, n);                     // ���������� ���������
		H = Hessian(x, n);                        // ���������� ���������
		trend = Direction(H, Y, grad, n);        // ���������� �����������
		temp = funck(x);                          // ��������� �������� ������� �� ������
		Log_out(x, trend, temp, n, e);           // ���������� ���� � �������
		fori x[i] += trend[i];                  // �������� x 
		funck(x) < temp ? Y /= 2 : Y *= 2;     // ���� �������� ������� �����������, �� ��������� ������, ����� �����������
		CurrentIter++;
		if (CurrentIter > MaxIter || abs(Norm(grad)) < e)  // ������� �� ����� ���� ������� ����� �������� ��� ����� ������ ��� ��������
			break;
	}

	Finished_log_out(x, CurrentIter, temp, n, e); // �������� �������� ���� � ������� (��� �����������)
	return 0;
}