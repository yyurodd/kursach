#include "course.h"
#include "Windows.h"
using namespace std;

int main() {
    setlocale(0, "");
    int choice;
    cout << "���� :                                           " << "\n";
    cout << "1) ������������ ������ 1 - ������ � �������                                      " << "\n";
    cout << "2) ������������ ������ 2 - ���������� ��������                                   " << "\n";
    cout << "3) ������������ ������ 3 - ������ � ���������� ���������                         " << "\n";
    cout << "4) ������������ ������ 4 - ������ �� ��������                                    " << "\n";
    


    while (true) {
        cin.clear();
        cin.sync();
        short int workPoint;

        cout << "�������� ������������ ������(������� ����� ������): ";
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
            cout << "\n" << "�� ����� �������� �����";
            break;
        }
        }

        cin.clear(); 
        cin.sync();

        char stopFlag;
        cout << "\n" << "���������� ���������� ���������? (Y-��/N-���)\n";
        cin >> stopFlag;

        if (stopFlag != 'Y' && stopFlag != 'y') {
            break;
        }
    }

    return 0;
}