#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    float I, R, U;
    cout << "Введите сопротивление." << endl;
    cin >> R;
    cout << "Введите нарпяжение." << endl;
    cin >> U;
    I = (U / R);
    cout << "Сила тока I = " << I;
}

