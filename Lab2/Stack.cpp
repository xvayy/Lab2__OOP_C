#include "Stack.h"

Stack::Stack(int capacity) {
    this->top = -1;                // Ініціалізуємо верхній елемент (стек порожній)
    this->capacity = capacity;           // Встановлюємо ємність стека
    this->elements = new int[this->capacity];  // Динамічно виділяємо пам'ять для масиву елементів
}

Stack::~Stack() {
    delete[] elements;  // Звільняємо пам'ять для масиву стека
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
