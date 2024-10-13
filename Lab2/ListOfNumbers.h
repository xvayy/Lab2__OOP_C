#ifndef LISTOFNUMBERS_H
#define LISTOFNUMBERS_H

#include "Stack.h"

class ListOfNumbers {
private:
    int* numbers;     // ����� �����
    int size;         // �������� ����� ������
    int capacity;     // ����������� ������� ��������

    Stack history;    // ���� ��� ��������� ����� ���

public:
    ListOfNumbers(int capacity);   // �����������
    ~ListOfNumbers();              // ����������

    void add_number(int num);      // ��������� �����
    void delete_last();            // ��������� ���������� �����
    void show_last() const;        // �������� ������� �������
    void show_all() const;         // �������� �� ��������
    void undo_last_change();       // ³������� ������� ����
};

#endif  // LISTOFNUMBERS_H
