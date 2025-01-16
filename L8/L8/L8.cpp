#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void reserch(char* pts) {
    printf("Введите максимальное количество букв, которое могут содержать слова первого предложения.\n");
    int k, count = 0;
    char t[128] = { 0 };
    char t_t[16] = { 0 };
    int t_index = 0;

    cin >> k;

    while (*pts && *pts != '.' && *pts != '?' && *pts != '!') {
        if (*pts != ' ' && *pts != ',' && *pts && *pts != '.' && *pts != '?' && *pts != '!') {
            t_t[count++] = *pts;
        }
        else {
            t_t[count] = '\0';
            if (count <= k) {
                if (t_index > 0) {
                    //t[t_index++] = ',';
                    t[t_index++] = ' ';
                }
                for (int i = 0; i < count; i++) {
                    t[t_index++] = t_t[i];
                }
            }
            count = 0;
            memset(t_t, 0, sizeof(t_t));
        }
        pts++;
    }

    t[t_index] = '\0';

    printf("\nИсправленое предложение :");
    puts(t);
}



void punctuation(char* pts, char* e_pts) {
    while (pts < e_pts){
        pts++;
        if (*pts == ',' or *pts == ':' or *pts == ';' or *pts == '-') {
            printf("\033[1;31m%c",*pts);
        }  
    }
}

void sentence(char* pts, char* pts_0) {
    if (*pts == '\0')
    {
        reserch(pts_0);
        return;
    }

    char *pts_1 = pts;
    printf("\033[1;31m%c", *pts);

    while (*pts != '.' and *pts != '?' and *pts != '!' and *pts != '\0')
    {
        pts++;
        printf("\033[1;31m%c", *pts);
        
    }
    printf("\n");
    punctuation(pts_1, pts);

    printf("\033[0m");
    printf("\n Нажми Enter чтоб продолжить.");
    cin.get();
    sentence(++pts, pts_0);
}

int main() {
    setlocale(LC_ALL, "RU");

    char* text = new char[256];

    printf("Введите текст! \n");
    fgets(text, 256, stdin);
    char* pts = text;

    text[strlen(text) -1] = '\0';

    sentence(pts, pts);

    delete[] text;
    return 0;
}