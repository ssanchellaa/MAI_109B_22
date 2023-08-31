#include "../include/Table.hpp"

int main()
{
    Table t;
    t.AddEntry(std::pair<int32_t, std::string>(2, "A"));
    t.AddEntry(std::pair<int32_t, std::string>(4, "B"));
    t.AddEntry(std::pair<int32_t, std::string>(5, "C"));
    t.AddEntry(std::pair<int32_t, std::string>(1, "D"));
    t.AddEntry(std::pair<int32_t, std::string>(9, "E"));
    t.AddEntry(std::pair<int32_t, std::string>(6, "F"));
    t.AddEntry(std::pair<int32_t, std::string>(3, "G"));

    std::cout << t << "---------------" << std::endl;
    t.TournamentSort();
    std::cout << t;
    std::pair<int32_t, std::string> p = t.BinarySearch(3);
    std::cout << "---------------" << std::endl;
    std::cout << p.first << " " << p.second;
    return 0;
}