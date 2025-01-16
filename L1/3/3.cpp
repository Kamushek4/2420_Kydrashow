#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    float R1, R2, S1, S2, S3;
    cout << "Введите первый радиус" << endl;
    cin >> R1;
    cout << "Введите второй радиус (он меньше первого)" << endl;
    cin >> R2;
    S1 = 3.14 * R1 * R1;
    S2 = 3.14 * R2 * R2;
    S3 = S1 - S2;
    cout << "Площадь первого круга = " << S1 << endl;
    cout << "Площадь второго круга = " << S2 << endl;
    cout << "Площадь кольца = " << S3;
}

