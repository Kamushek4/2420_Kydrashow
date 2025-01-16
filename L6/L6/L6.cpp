#include <iostream> 

using namespace std;

struct Discipline
{
    string name;
    int grade;
};

struct Student
{
    std::string FIO;
    Discipline *disc;
};


int main()
{
    setlocale(LC_ALL, "RU");
    int n_d, n_s, nerds = 0;
  
    cout << "Введите количество студентов : ";
    cin >> n_s;
    Student *ps = new Student[n_s];

    cout << "Введите количесво дисциплин : ";
    cin >> n_d;
    Discipline* pd = new Discipline[n_d];

    for (int i = 0; i < n_d; i++)
    {
        cout << "Введите название дисциплыны " << i + 1 << " : ";
        cin >> pd[i].name;
    }

    for (int i = 0; i < n_s; i++)
    {
        cout << endl << "Введите ФИО студента " << i << " : ";
        cin >> ps[i].FIO;
        ps[i].disc = pd;

        bool cur_nerd = true;
        for (int j = 0; j < n_d; j++)
        {
            cout << "Оценка по предмету '" << ps->disc[j].name << "' : ";
            cin >> ps->disc[j].grade;
            if (ps->disc[j].grade < 4)
            {
                cur_nerd = false;
            }
        }
        if (cur_nerd)
        {
            nerds++;
        }
    }

    delete[] ps;
    delete[] pd;

    cout << endl << "Количество студентов без задолжностей : " << " "<< nerds << ".";
    return 0;
}