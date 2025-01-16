﻿#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	cout << "Введите размер массива ";
	int n = 1, min = 999;
	cin >> n;
	int *m = new int[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Введи эллемент " << i + 1 << " таблицы: ";
		cin >> m[i];
		if (abs(m[i]) < min)
		{
			min = abs(m[i]);
		}
	}

	int k = min * min;
	cout << endl << "Наименьшее: " << min << endl << "Множитель: " << k << endl;

	for (int i = 0; i < n; i++)
	{
		m[i] *= k;
		m[i] *= k;
		cout << endl << m[i];
	}
	delete[] m;

	return 0;
}
