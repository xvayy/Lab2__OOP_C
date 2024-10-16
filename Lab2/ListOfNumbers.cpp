#include "ListOfNumbers.h"
#include <iostream>

using namespace std;

ListOfNumbers::ListOfNumbers(int capacity) {
    this->size = 0;                             // ���������� ����� ������
    this->capacity = capacity;                  // ������������ ������ ������
    this->history = new Stack(this->capacity);  // ���������� ���� ��������
    this->numbers = new int[this->capacity];    // �������� �������� ���'��� ��� ������
}

ListOfNumbers::~ListOfNumbers() {
    delete[] numbers;     // ��������� ���'��� ��� ������ �����
    delete history;       // ��������� ���'��� ��� ����� (�����)
}

void ListOfNumbers::add_number(int num) {
    if (size < capacity) {
        numbers[size++] = num;
        history->push(num);  // �������� � �����
        cout << "����� " << num << " ������ � ������.\n";
    }
    else {
        cout << "������ ����������. �� ����� ������ ���� �����.\n";
    }
}

void ListOfNumbers::delete_last() {
    if (size > 0) {
        int removed = numbers[--size];
        history->push(removed);  // �������� �������� �����
        cout << "����� " << removed << " �������� � ������.\n";
    }
    else {
        cout << "������ �������. ���� �� ��������.\n";
    }
}

void ListOfNumbers::delete_first() {
    if (size > 0) {
        int first_removed = numbers[0];
        history->push(first_removed);

        // ������ �� �������� ����
        for (int i = 1; i < size; ++i) {
            numbers[i - 1] = numbers[i];
        }

        --size;
        cout << "����� " << first_removed << " �������� � ������.\n";
    }
    else {
        cout << "������ �������. ���� �� ��������.\n";
    }
}


void ListOfNumbers::show_last() const {
    if (size > 0) {
        cout << "������� �������: " << numbers[size - 1] << endl;
    }
    else {
        cout << "������ �������.\n";
    }
}

void ListOfNumbers::show_all() const {
    cout << "�������� ������:\n";
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
            cout << "³�������� �����: " << restored << endl;
        }
        else {
            cout << "���� ���� ��� ���������� �����.\n";
        }
    }
    else {
        cout << "���� �������� ��� ����������.\n";
    }
}