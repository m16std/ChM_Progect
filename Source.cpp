#include "Header.h"

#include <vector>
int main()
{
	setlocale(LC_ALL, "Russian");
	std::vector <double> x = {0,0,0};    //����������
	std::vector <double> grad;           //�������� �������
	std::vector <double> naprl;          //�����������
	int i, n = 3;
	double number, e;
	double Y = 10000;             //������
	double** H = new double* [n]; //������� �����
	double** I = new double* [n]; //��������� �������
	bool flag = true;
	int iter = 50;       //���������� ���������� ��������
	int currenttime = 0; //������� ����������

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