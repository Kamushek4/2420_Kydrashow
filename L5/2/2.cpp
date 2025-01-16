#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "RU");
	int n = 1, c, d, count = 0;
	cout << "Введите размер массива: ";
	cin >> n;
	int *m = new int[n];

	cout << endl << "Введите начало отрезка: ";
	cin >> c;
	cout << endl << "Введите конец отрезка: ";
	cin >> d;
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "Введи эллемент " << i + 1 << " : ";
		
		cin >> *(m + i);

		if ((*(m + i) <= c) or (*(m + i) >= d))
		{
			count += 1;
		}
	}
	delete[]m;

	cout << endl << "Количество элементов не пренадлежащих отрезку: " << count << ".";
}

