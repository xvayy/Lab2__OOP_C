#include <iostream>
#include "ListOfNumbers.h"
#include "ConsolIO.h"

using namespace std;

ListOfNumbers** lists = nullptr;  // Динамічний масив вказівників на списки
int list_count = 0;               // Лічильник створених списків
int list_capacity = 2;            // Початкова ємність для масиву списків

void menu();
void list_menu(ListOfNumbers* list);
void expand_list_capacity();  // Функція для розширення масиву списків

int main() {
    setlocale(LC_ALL, "Ukrainian");

    // Початково виділяємо пам'ять для масиву списків
    lists = new ListOfNumbers * [list_capacity];

    bool running = true;

    while (running) {
        menu();
        int choice = ConsolIO::GetValue(cin);

        switch (choice) {
        case 1: {  // Створити новий список
            if (list_count == list_capacity) {
                expand_list_capacity();  // Розширюємо масив при необхідності
            }
            lists[list_count] = new ListOfNumbers(10);
            ++list_count;
            cout << "Новий список створено!\n";
            break;
        }
        case 2: {  // Вибрати список для редагування
            if (list_count == 0) {
                cout << "Немає доступних списків. Спочатку створіть список.\n";
                break;
            }
            cout << "Доступні списки:\n";
            for (int i = 0; i < list_count; ++i) {
                cout << i + 1 << ". Список " << i + 1 << endl;
            }
            cout << "Виберіть список: ";
            int index = ConsolIO::GetValue(cin) - 1;

            if (index >= 0 && index < list_count) {
                list_menu(lists[index]);
            }
            else {
                cout << "Невірний вибір.\n";
            }
            break;
        }
        case 3: {  // Вийти
            running = false;
            break;
        }
        default: {
            cout << "Невірний вибір. Спробуйте ще раз.\n";
            break;
        }
        }
    }

    // Очищення пам'яті
    for (int i = 0; i < list_count; ++i) {
        delete lists[i];
    }
    delete[] lists;  // Очищуємо пам'ять для масиву списків

    cout << "Програма завершена.\n";
    return 0;
}

void menu() {
    cout << "\n===== ГОЛОВНЕ МЕНЮ =====\n";
    cout << "1. Створити новий список\n";
    cout << "2. Вибрати список для редагування\n";
    cout << "3. Вийти\n";
}

void list_menu(ListOfNumbers* list) {
    bool running = true;

    while (running) {
        cout << "\n=== МЕНЮ СПИСКУ ===\n";
        cout << "1. Додати число\n";
        cout << "2. Видалити останнє число\n";
        cout << "3. Показати всі елементи\n";
        cout << "4. Відновити останню зміну\n";
        cout << "5. Видалити перше число\n";
        cout << "6. Повернутися до головного меню\n";

        int choice = ConsolIO::GetValue(cin);

        switch (choice) {
        case 1: {
            cout << "Введіть число для додавання: ";
            int num = ConsolIO::GetValue(cin);
            list->add_number(num);
            break;
        }
        case 2: {
            list->delete_last();
            break;
        }
        case 3: {
            list->show_all();
            break;
        }
        case 4: {
            list->undo_last_change();
            break;
        }
        case 5: {
            list->delete_first();
            break;
        }
        case 6: {
            running = false;
            break;
        }
        default: {
            cout << "Невірний вибір. Спробуйте ще раз.\n";
            break;
        }
        }
    }
}

void expand_list_capacity() {
    // Подвоюємо ємність масиву списків
    list_capacity *= 2;
    ListOfNumbers** new_lists = new ListOfNumbers * [list_capacity];

    // Копіюємо старі списки у новий масив
    for (int i = 0; i < list_count; ++i) {
        new_lists[i] = lists[i];
    }

    // Очищуємо старий масив і замінюємо його новим
    delete[] lists;
    lists = new_lists;
}
