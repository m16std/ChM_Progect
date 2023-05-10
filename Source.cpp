#include "Header.h"

double funck(std::vector <double> x) //����������� �������
{
	return (pow(x[0] - 4, 4) + pow(x[1] + 6, 3) + pow(x[2] - 10, 2)) + exp(x[3]);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::vector <double> grad;            //�������� �������
	std::vector <double> napr;           //�����������
	int n = 4;                            //���������� ���������� � �������
	double e = 0.0001;                   //�������� (����� � ������� ����������)
	double Y = 10000;                   //����� (������ ������� ����� ��� ���������� ���������)
	double** H = new double* [n];         //������� �����
	std::vector <double> x;              //��������� ����� (���� �� ����� �������� ����� ��������)
	fori x.push_back(1);                //���������� ��������� ����� (��� ��������)
	double temp;                         //��� ������ �������� ������� ��� ��������� �������� �� � ����� ������
	int MaxIter = 100;                  //���������� ���������� ��������
	int CurrentIter = 0;               //������� ���������� ��������

	while (1)
	{
		grad = Gradient(x, n);                    // ���������� ���������
		H = Hessian(x, n);                       // ���������� ���������
		napr = Direction(H, Y, grad, n);        // ���������� �����������
		temp = funck(x);                          // ��������� �������� ������� �� ������
		Log_out(x, napr, temp, n, e);            // ���������� ���� � �������
		fori x[i] += napr[i];                   // �������� x 
		funck(x) < temp ? Y /= 2 : Y *= 2;     // ���� �������� ������� �����������, �� ��������� �����, ����� �����������
		CurrentIter++;
		if (CurrentIter > MaxIter || abs(Norm(grad)) < e)  // ������� �� ����� ���� ������� ����� �������� ��� ����� ������ ��� ��������
			break;
	}

	Finished_log_out(x, CurrentIter, temp, n, e); // �������� �������� ���� � ������� (��� �����������)
	return 0;
}