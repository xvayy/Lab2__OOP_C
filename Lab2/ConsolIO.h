#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

class ConsolIO {
public:
    // Метод для зчитування числа з консолі
    static double GetValue(istream& is) {
        setlocale(LC_ALL, "Ukrainian");
        double value;
        while (true) {
            is >> value;
            if (is.peek() == '\n') {
                is.get();
                break;
            }
            else {
                cout << "\n\tНЕКОРЕКТНИЙ ВВIД! Очiкується дiйсне число.\nПовторiть: ";
                is.clear();
                while (is.get() != '\n') {};
            }
        }
        return value;
    }

    // Метод для зчитування текстової інформації з консолі
    static char* GetText(istream& is) {
        char* buffer = new char[255];
        while (true) {
            setlocale(LC_ALL, "Ukrainian");
            SetConsoleCP(1251);  // Установлення кодування Windows-1251
            is.getline(buffer, 255, '\n');
            SetConsoleCP(866);  // Повернення до кодування CP866
            if (strlen(buffer) > 0) {
                int emptyChar = 0;
                for (int i = 0; i < strlen(buffer); i++) {
                    if (buffer[i] == ' ') emptyChar++;
                }
                if (emptyChar != strlen(buffer)) break;
            }
            cout << "\n\tНЕКОРЕКТНИЙ ВВIД! Очiкується текстова iнформацiя.\nПовторiть ввiд: " << endl;
        }
        is.clear();
        return buffer;
    }
};
