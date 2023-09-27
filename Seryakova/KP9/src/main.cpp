#include <iostream>

using namespace std;


#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>

// Структура для хранения записей таблицы
struct TableEntry {
    int integerKey;
    char letterKey;
    std::string text;
};

// Процедура для печати элементов таблицы
void printTable(const std::vector<TableEntry>& table) {
    for (const TableEntry& entry : table) { //проходимся по каждому элементу вектора  table и сохраняет каждый элемент в переменную entry типа TableEntry
        std::cout << "Ключ: " << entry.integerKey << entry.letterKey << ", Запись: " << entry.text << std::endl;
    }
    std::cout << std::endl;
}

// Функция для сортировки таблицы методом простого двухпоточного слияния
void mergeSort(std::vector<TableEntry>& table, int left, int right) { //функции, которая принимает в качестве
//аргументов вектор структур TableEntry по ссылке, а также индексы левой и правой границ отрезка таблицы,
// который нужно отсортировать.
    if (left >= right) {
        return;
    }//Если левая граница отрезка больше или равна правой, то отрезок содержит не более одного элемента
    //и его сортировать не нужно.

    int mid = left + (right - left) / 2;//вычисляем середину

    // Рекурсивно сортируем две половины таблицы
    mergeSort(table, left, mid);
    mergeSort(table, mid + 1, right);

    // Выполняем слияние отсортированных половин
    std::vector<TableEntry> temp(right - left + 1);
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (table[i].integerKey < table[j].integerKey ||
            (table[i].integerKey == table[j].integerKey && table[i].letterKey < table[j].letterKey)) {
            temp[k] = table[i];
            i++;
        } else {
            temp[k] = table[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = table[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = table[j];
        j++;
        k++;
    }

    for (int m = 0; m < k; m++) {
        table[left + m] = temp[m];
    }
}

// Процедура сортировки таблицы методом простого двухпоточного слияния
void mergeSortParallel(std::vector<TableEntry>& table, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    // Создаем два потока для сортировки каждой половины таблицы
    std::thread t1(mergeSort, std::ref(table), left, mid);
    std::thread t2(mergeSort, std::ref(table), mid + 1, right);

    // Ожидаем завершения обоих потоков
    t1.join();
    t2.join();

    // Выполняем слияние отсортированных половин
    std::vector<TableEntry> temp(right - left + 1);
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (table[i].integerKey < table[j].integerKey ||
            (table[i].integerKey == table[j].integerKey && table[i].letterKey < table[j].letterKey)) {
            temp[k] = table[i];
            i++;
        } else {
            temp[k] = table[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = table[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = table[j];
        j++;
        k++;
    }

    for (int m = 0; m < k; m++) {
        table[left + m] = temp[m];
    }
}

// Функция двоичного поиска по комбинированному ключу в упорядоченной таблице
bool binarySearch(const std::vector<TableEntry>& table, int integerKey, char letterKey) {
    int left = 0;
    int right = table.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (table[mid].integerKey == integerKey && table[mid].letterKey == letterKey) {
            return true;
        }

        if (table[mid].integerKey < integerKey ||
            (table[mid].integerKey == integerKey && table[mid].letterKey < letterKey)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
     
    }
    cout << endl;
    return false;
}

void getResaltNotEmpty(const std::vector<TableEntry>& table, int integerKey, char letterKey) {
    int left = 0;
    int right = table.size() - 1;
    cout<< "Результат:";
    while (left <= right) {
        int mid = left + (right - left) / 2 ;
        
        if (table[mid].integerKey == integerKey && table[mid].letterKey == letterKey) {
            cout<< table[mid].text<<" ";
            right=mid;

        }

        if (table[mid].integerKey < integerKey ||
            (table[mid].integerKey == integerKey && table[mid].letterKey < letterKey)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        
     
    }
    cout << endl;
    
}

int checkEngKey(char& letter){
    if (((letter >= 'A') && (letter<='Z')) || ((letter>='a') && (letter<='z'))){
        return 0;
    }else{
        cout<<"Неверный литерный ключ, вводите литеру A-Z или a-z."<<endl;
        return 1;
    }
}


int main() {
    std::vector<TableEntry> table;
    int numElements;
    std::cout << "Введите количество элементов в таблице (8-12): ";
    std::cin >> numElements;

    std::cout << "Введите элементы таблицы (ключ и текст записи):\n";
    for (int i = 0; i < numElements; i++) {
        TableEntry entry;
        std::cout << "Элемент " << (i + 1) << ":\n";
        
        std::cin >> entry.integerKey >> entry.letterKey;
        
        switch (checkEngKey(entry.letterKey)){
            case 0: break;
                
            
            case 1: exit(0);
             
            default: exit(0);
        }
        std::cin.ignore(); // Очистка буфера для ввода строки
        std::getline(std::cin, entry.text);
        table.push_back(entry);
    }

    // Печать исходного состояния таблицы
    std::cout << "\nИсходное состояние таблицы:\n";
    printTable(table);

    // Сортировка и печать результатов
    std::cout << "Результат сортировки методом простого двухпоточного слияния:\n";
    mergeSortParallel(table, 0, table.size() - 1);
    printTable(table);

    // Ввод ключей для поиска
    int numKeys;
    std::cout << "Введите количество ключей для поиска: ";
    std::cin >> numKeys;

    std::cout << "Введите ключи для поиска (целое + литера):\n";
    for (int i = 0; i < numKeys; i++) {
        int integerKey;
        char letterKey;
        
        std::cin >> integerKey >> letterKey;

        // Поиск и печать результатов
        std::cout << "Поиск по ключу " << integerKey << letterKey << ": ";

        if(binarySearch(table, integerKey, letterKey)){
            getResaltNotEmpty(table, integerKey, letterKey);
        }else{
            std::cout << "Элемент не найден\n";
        }
        
    }

    return 0;
}