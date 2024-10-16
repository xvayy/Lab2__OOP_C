#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int* elements;  // Динамічний масив для зберігання елементів стека
    int top;        // Індекс верхнього елемента
    int capacity;   // Ємність стека

public:
    Stack(int capacity);
    ~Stack();

    void push(int value);  // Додати елемент у стек
    int pop();             // Вилучити верхній елемент
    bool is_empty() const; // Перевірка, чи стек порожній
};

#endif
