#include "Table.hpp"
#include <iostream>

int checkEngKey(char& letter) {
    if (((letter >= 'A') && (letter <= 'Z')) || ((letter >= 'a') && (letter <= 'z'))) {
        return 0;
    } else {
        std::cout << "Неверный литерный ключ, вводите литеру A-Z или a-z." << std::endl;
        return 1;
    }
}

int main() {
    Table table;
    int numElements;
    std::cout << "Введите количество элементов в таблице (8-12): ";
    std::cin >> numElements;

    std::cout << "Введите элементы таблицы (ключ и текст записи):\n";
    for (int i = 0; i < numElements; i++) {
        int integerKey;
        char letterKey;
        std::string text;

        std::cout << "Элемент " << (i + 1) << ":\n";
        std::cin >> integerKey >> letterKey;

        switch (checkEngKey(letterKey)) {
            case 0:
                break;
            case 1:
                exit(0);
            default:
                exit(0);
        }

        std::cin.ignore();
        std::getline(std::cin, text);
        TableEntry entry(integerKey, letterKey, text);
        table.entries.push_back(entry);
    }

    std::cout << "\nИсходное состояние таблицы:\n";
    table.printTable();

    std::cout << "Результат сортировки методом простого двухпоточного слияния:\n";
    table.mergeSortParallel(0, table.entries.size() - 1);
    table.printTable();

    int numKeys;
    std::cout << "Введите количество ключей для поиска: ";
    std::cin >> numKeys;

    std::cout << "Введите ключи для поиска (целое + литера):\n";
    for (int i = 0; i < numKeys; i++) {
        int integerKey;
        char letterKey;
        std::cin >> integerKey >> letterKey;

        std::cout << "Поиск по ключу " << integerKey << letterKey << ": ";

        if (table.binarySearch(integerKey, letterKey)) {
            table.getResultsNotEmpty(integerKey, letterKey);
        } else {
            std::cout << "Элемент не найден\n";
        }
    }

    return 0;
}