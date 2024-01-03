#include <iostream>
#include "course.h"
void lab1() {
    setlocale(0, "");
    bool cycle = 1;
    char type, choice;
    while (cycle) {
        do {
            std::cout << "������� ��� �����, �������� ������������� �������� �����. 'i' ��� ���� int, 'f' ��� ���� float.\n"
                << "���� �� ������ ������� ������� ������ ��������� ��� ��������� ���� ������ - ������� 's'. \n����: ";
            std::cin >> type;
        } while (!type);
        if (type == 'i') {
            int number, copy;
            std::cout << "������� ����� �����: ";
            std::cin >> number;
            copy = number;
            int order = sizeof(int) * 8;
            int mask = 1 << (order - 1);
            std::cout << "�������� �������������: ";
            for (int i = 0; i < order; i++) {

                std::cout << ((number & mask) ? 1 : 0);

                number <<= 1;
                if (i == 0 || i % 8 == 7) {
                    std::cout << " ";
                }

            }
            std::cout << std::endl;

            //idz for int start
            std::cout << "\n�� ������ �������� ��� ����, ������ �������, ������?\n������� '1', ���� ��, ����� '0': ";
            std::cin >> choice;
            if (choice == '1') {
                copy >>= 1;
                std::cout << "\n����� ����� ��������: " << copy << "\n";
                for (int i = 0; i < order; i++) {
                    std::cout << ((copy & mask) ? 1 : 0);
                    copy <<= 1;
                    if (i == 0 || i % 8 == 7) {
                        std::cout << " ";
                    }
                }


            }//idz for int end
            std::cout << std::endl;
        }


        else if (type == 'f') {
            std::cout << "������� ������������ �����: ";
            union {
                int integerA;
                float floatB;
            };
            union {
                int copyA;
                float copyFloat;
            };

            std::cin >> floatB;
            copyA = integerA;
            int order = sizeof(int) * 8;
            int mask = 1 << (order - 1);
            std::cout << "�������� �������������: ";
            for (int i = 0; i < order; i++) {
                std::cout << ((integerA & mask) ? "1" : "0");
                integerA <<= 1;
                if (i == 0 || i == 8) {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;

            //idz for float start
            std::cout << "\n�� ������ �������� ��� ����, ������ �������, ������?\n������� '1', ���� ��, ����� '0': ";
            std::cin >> choice;
            if (choice == '1') {

                copyA >>= 1;
                std::cout << "\n����� ����� ��������: " << copyFloat << "\n";
                for (int i = 0; i < order; i++) {
                    std::cout << ((copyA & mask) ? 1 : 0);
                    copyA <<= 1;
                    if (i == 0 || i == 8) {
                        std::cout << " ";
                    }
                }

            }//idz for float end

            std::cout << std::endl;

        }
        else if (type == 's') {
            std::cout << "������ int: " << sizeof(int) << " �����" << std::endl;
            std::cout << "������ short int: " << sizeof(short int) << " �����" << std::endl;
            std::cout << "������ long int: " << sizeof(long int) << " �����" << std::endl;
            std::cout << "������ float: " << sizeof(float) << " �����" << std::endl;
            std::cout << "������ double: " << sizeof(double) << " ����" << std::endl;
            std::cout << "������ long double: " << sizeof(long double) << " ����" << std::endl;
            std::cout << "������ char: " << sizeof(char) << " ����" << std::endl;
            std::cout << "������ bool: " << sizeof(bool) << " ����" << std::endl << std::endl;
        }
        else {
            std::cout << "�������� ����";
        }
        std::cout << "\n\n�� ������ ���������? \n������� '1' ���� ��, ����� '0': ";
        std::cin >> cycle;
    }
    
}
