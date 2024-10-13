#include <iostream>
#include "ListOfNumbers.h"
#include "ConsolIO.h"

using namespace std;

const int MAX_LISTS = 10;  // Максимальна кількість списків
ListOfNumbers* lists[MAX_LISTS];  // Масив вказівників на об'єкти ListOfNumbers
int list_count = 0;  // Лічильник створених списків

void menu();
void list_menu(ListOfNumbers* list);

int main() {
    setlocale(LC_ALL, "Ukrainian");

    bool running = true;

    while (running) {
        menu();
        int choice = ConsolIO::GetValue(cin);

        switch (choice) {
        case 1: {  // Створити новий список
            if (list_count < MAX_LISTS) {
                lists[list_count] = new ListOfNumbers();
                ++list_count;
                cout << "Новий список створено!\n";
            }
            else {
                cout << "Досягнуто максимальну кількість списків.\n";
            }
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
        cout << "5. Повернутися до головного меню\n";

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
