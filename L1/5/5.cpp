#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int A, B, C;
    cout << "Введите три целых числа." << endl;
    cin >> A >> B >> C;

    cout << "Утверждение что (B - A) * (B - C) <= 0 является: " <<((B - A) * (B - C) <= 0) << endl;

    return 0;
}

