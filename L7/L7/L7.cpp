#include <iostream>
#include <string>

using namespace std;

int reserch(int *m, int j, int n, int count) {
    cout << "Введите " << j << " число: ";
    cin >> *m;
    string z = to_string(*m);
    for (int i = 0; i < z.length(); i++) {
        if (z[i] == '7') {
            count++;
            break; 
        }
    }

    if (j >= n)    {
        cout << endl << "Чисел, где есть '7': " << count << " штук";
        return 0;
    }

    j++;    m++;
    reserch(m, j, n, count);
    return 0; 
}

int main() {
    setlocale(LC_ALL, "RU");
    int n = 0;
    cout << "Введите размер массива: ";
    cin >> n;
    int* m = new int[n];
    reserch(m, 1, n, 0);
    delete[] m;
    return 0;
}