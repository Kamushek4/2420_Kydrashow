#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    setlocale(LC_ALL, "ru");
    ofstream fout;
    fout.open("Avto.dat");

    if (!fout.is_open()) {
        printf("\n Не удалось открыть файл!");
        return 0;
    }

    const char* message[] = {
        "Расход топлива на трассу: ",
        "Расход топлива по городу: ",
        "Смешанный расход топлива: ",
        "Скорость автомабиля: ",
        "Мощность двигателя: "
    };

    for (int i = 0; i < sizeof(message) / sizeof(message[0]); i++) {
        printf("\033[0m");
        printf(message[i]);
        printf("\033[0;32m");
        double value;
        cin >> value;
        fout << "\n" << message[i] << value;
    }
    return 0;
}