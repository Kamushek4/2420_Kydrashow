#include <iostream>
using namespace std;

int main() {

    setlocale(LC_ALL, "RU");
    int n;
    cout << "Введите трехзначное число: ";
    cin >> n;

    int a = n / 100;          
    int b = (n / 10) % 10;          
    int c = n % 10;                

    cout << "Число, где десятки и единицы поменялись местами: " << (a * 100 + c * 10 + b) << endl;

    return 0;
}

