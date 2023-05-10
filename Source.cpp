#include "Header.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	std::vector <double> x = { 1,1,1 };    //��������� ����� (���� �� ����� �������� ����� ��������)
	std::vector <double> grad;            //�������� �������
	std::vector <double> napr;           //�����������
	int n = 3;                            //���������� ���������� � �������
	double e = 0.0001;                   //��������
	double Y = 10000;                   //����� (������ ������� ����� ��� ���������� ���������)
	double** H = new double* [n];         //������� �����
	double temp;                         //��� ������ �������� ������� ��� ��������� �������� �� � ����� ������
	int MaxIter = 200;                  //���������� ���������� ��������
	int CurrentIter = 0;               //������� ����������

	while (1)
	{
		grad = Gradient(x, n);                    // ���������� ���������
		H = Hessian(x, n);                       // ���������� ���������
		napr = Direction(H, Y, grad, n);        // ���������� �����������
		temp = funck(x);                       // ��������� �������� ������� �� ������
		Log_out(x, napr, temp, n);            // �������� ���� � �������
		fori x[i] += napr[i];                // �������� x 
		funck(x) < temp ? Y /= 2 : Y *= 2;  // ���� �������� ������� �����������, �� ��������� �����, ����� �����������
		CurrentIter++;
		if (CurrentIter > MaxIter || abs(Norm(grad)) < e)  // ������� �� ����� ���� ������� ����� �������� ��� ����� ������ ��� ��������
			break;
	}

	Finished_log_out(x, CurrentIter, temp, n); // �������� �������� ���� � ������� (��� �����������)
	return 0;
}