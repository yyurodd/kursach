#include "course.h"
#include "Windows.h"
using namespace std;

int main() {
    setlocale(0, "");
    int choice;
    cout << "Меню :                                           " << "\n";
    cout << "1) Лабораторная работа 1 - Работа с памятью                                      " << "\n";
    cout << "2) Лабораторная работа 2 - Сортировки массивов                                   " << "\n";
    cout << "3) Лабораторная работа 3 - Работа с двумерными массивами                         " << "\n";
    cout << "4) Лабораторная работа 4 - Работа со строками                                    " << "\n";
    


    while (true) {
        cin.clear();
        cin.sync();
        short int workPoint;

        cout << "Выберите лабораторную работу(введите номер работы): ";
        cin >> workPoint;

        switch (workPoint)
        {
        case 1: {
            lab1();
            break;
        }
        case 2: {
            lab2();
            break;
        }
        case 3: {
            lab3();
            break;
        }
        case 4: {
            lab4();
            break;
        }
        default: {
            cout << "\n" << "Вы ввели неверный номер";
            break;
        }
        }

        cin.clear(); 
        cin.sync();

        char stopFlag;
        cout << "\n" << "Продолжить выполнение программы? (Y-да/N-нет)\n";
        cin >> stopFlag;

        if (stopFlag != 'Y' && stopFlag != 'y') {
            break;
        }
    }

    return 0;
}