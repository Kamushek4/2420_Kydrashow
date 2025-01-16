#include <iostream>
#include <cmath>

using namespace std;

int calculation(double result, int i, int n) {
    if (i >= n)    {
        cout << "Результат: " << result;
        return 0;
    }
    result = sqrt(result + sqrt(i));
    i++;
    return (calculation(result, i, n));
}

int main() {
    setlocale(LC_ALL, "RU");
    int n = 0;
    cout << "Введите длинну функции: y = √(1+√(2+...+√(n))) " << endl;
    cin >> n;
    calculation(1, 1, n);
    return 0;
}