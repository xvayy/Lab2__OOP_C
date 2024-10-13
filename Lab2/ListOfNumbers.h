#ifndef LISTOFNUMBERS_H
#define LISTOFNUMBERS_H

#include "Stack.h"

class ListOfNumbers {
private:
    int* numbers;     // Масив чисел
    int size;         // Поточний розмір списку
    int capacity;     // Максимальна кількість елементів

    Stack history;    // Стек для зберігання історії змін

public:
    ListOfNumbers(int capacity);   // Конструктор
    ~ListOfNumbers();              // Деструктор

    void add_number(int num);      // Додавання числа
    void delete_last();            // Видалення останнього числа
    void show_last() const;        // Показати останній елемент
    void show_all() const;         // Показати всі елементи
    void undo_last_change();       // Відновити останню зміну
};

#endif  // LISTOFNUMBERS_H
