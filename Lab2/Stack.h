#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int* elements;  // ����� ��� ��������� �������� �����
    int top;        // ������ ��������� ��������
    int capacity;   // ������ �����

public:
    Stack(int capacity);  // �����������
    ~Stack();             // ����������

    void push(int value);  // ������ ������� � ����
    int pop();             // �������� ������ �������
    bool is_empty() const; // ��������, �� ���� �������
};

#endif  // STACK_H
