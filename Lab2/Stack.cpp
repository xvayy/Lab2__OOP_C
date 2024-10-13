#include "Stack.h"
#include <iostream>
#include "Stack.h"

Stack::Stack(int capacity) {
    this->top = -1;                // Ініціалізуємо верхній елемент як -1 (стек порожній)
    this->capacity = capacity;           // Встановлюємо ємність стека
    this->elements = new int[this->capacity];  // Виділяємо пам'ять для масиву елементів
}


Stack::~Stack() {
    delete[] elements;
}

void Stack::push(int value) {
    if (top < capacity - 1) {
        elements[++top] = value;
    }
}

int Stack::pop() {
    if (top >= 0) {
        return elements[top--];
    }
    return -1;  // Якщо стек порожній
}

bool Stack::is_empty() const {
    return top == -1;
}
