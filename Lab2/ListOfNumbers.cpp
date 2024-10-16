#include "ListOfNumbers.h"
#include <iostream>

using namespace std;

ListOfNumbers::ListOfNumbers(int capacity) {
    this->size = 0;                             // Ініціалізуємо розмір списку
    this->capacity = capacity;                  // Встановлюємо ємність списку
    this->history = new Stack(this->capacity);  // Ініціалізуємо стек динамічно
    this->numbers = new int[this->capacity];    // Динамічно виділяємо пам'ять для масиву
}

ListOfNumbers::~ListOfNumbers() {
    delete[] numbers;     // Звільняємо пам'ять для масиву чисел
    delete history;       // Звільняємо пам'ять для історії (стека)
}

void ListOfNumbers::add_number(int num) {
    if (size < capacity) {
        numbers[size++] = num;
        history->push(num);  // Зберігаємо в історії
        cout << "Число " << num << " додано у список.\n";
    }
    else {
        cout << "Список заповнений. Не можна додати нове число.\n";
    }
}

void ListOfNumbers::delete_last() {
    if (size > 0) {
        int removed = numbers[--size];
        history->push(removed);  // Зберігаємо видалене число
        cout << "Число " << removed << " видалено зі списку.\n";
    }
    else {
        cout << "Список порожній. Немає що видаляти.\n";
    }
}

void ListOfNumbers::delete_first() {
    if (size > 0) {
        int first_removed = numbers[0];
        history->push(first_removed);

        // Зміщуємо всі елементи вліво
        for (int i = 1; i < size; ++i) {
            numbers[i - 1] = numbers[i];
        }

        --size;
        cout << "Число " << first_removed << " видалено зі списку.\n";
    }
    else {
        cout << "Список порожній. Немає що видаляти.\n";
    }
}


void ListOfNumbers::show_last() const {
    if (size > 0) {
        cout << "Останній елемент: " << numbers[size - 1] << endl;
    }
    else {
        cout << "Список порожній.\n";
    }
}

void ListOfNumbers::show_all() const {
    cout << "Елементи списку:\n";
    for (int i = 0; i < size; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

void ListOfNumbers::undo_last_change() {
    if (!history->is_empty()) {
        int restored = history->pop();
        if (size < capacity) {
            numbers[size++] = restored;
            cout << "Відновлено число: " << restored << endl;
        }
        else {
            cout << "Немає місця для відновлення числа.\n";
        }
    }
    else {
        cout << "Немає елементів для відновлення.\n";
    }
}