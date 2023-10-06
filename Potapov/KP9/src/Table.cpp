#include "../include/Table.hpp"
#include <iomanip>

template <typename T>
Vector<RowTable<T>>& Table<T>::get_rows(){
    return this->rows;
}

template <typename T>
void Table<T>::insert(const T& key, const std::string& data){
    this->rows.push_back(RowTable<T>(key, data));
}

template <typename T>
RowTable<T>& Table<T>::search(const T& key){
    this->shell_sort();

    size_t left = 0, right = this->rows.size();
    while (left < right){
        size_t middle = (left + right) / 2;
        if (this->rows[middle] < key){
            left = middle + 1;
        } else if (this->rows[middle] > key){
            right = middle;
        } else{
            return this->rows[middle];
        }
    }

    if (this->rows[left] == key){
        return this->rows[left];
    }
    return "";
}

template <typename T>
void Table<T>::swap(size_t index1, size_t index2) {
    RowTable<T> tmp;
    tmp = this->rows[index2];
    this->rows[index2] = this->rows[index1];
    this->rows[index1] = tmp;
}

template <typename T>
void Table<T>::sort(){
    const double factor = 1.247;
    double step = this->rows.size() - 1;

    while (step >= 1) {
        for (size_t i = 0; i + step < rows.size(); ++i) {
            if (this->rows[i + step] < this->rows[i]) {
                swap(i, i + step);
            }
        }
        step /= factor;
    }
}

template <typename T>
void Table<T>::print() const{
    std::cout << "  | " << "       key      " << " | " << "      data      |\n";
    std::cout << "--+-" << "----------------" << "-+-" << "----------------+\n";

    for (size_t i = 0; i != this->rows.size(); ++i){
        std::cout << i + 1 << " | " << std::setw(16) << std::left << this->rows[i].get_key() << " | " <<
                     std::setw(15) << std::left << this->rows[i].get_data() << " |\n";
        std::cout << "--+-" << "----------------" << "-+-" << "----------------+\n";
    }
}