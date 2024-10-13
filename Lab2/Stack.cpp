#include "Stack.h"
#include <iostream>
#include "Stack.h"

Stack::Stack(int capacity) {
    this->top = -1;                // ���������� ������ ������� �� -1 (���� �������)
    this->capacity = capacity;           // ������������ ������ �����
    this->elements = new int[this->capacity];  // �������� ���'��� ��� ������ ��������
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
    return -1;  // ���� ���� �������
}

bool Stack::is_empty() const {
    return top == -1;
}
