#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Table.hpp"

TEST_CASE("Test mergeSort") {
    Table table;
    // Заполните table.entries данными для тестирования
    // Например: table.entries = {TableEntry(3, 'A', "TextA"), TableEntry(1, 'B', "TextB"), ...};

    table.mergeSort(0, table.entries.size() - 1);

    // Проверьте, что table.entries отсортирован корректно
    REQUIRE(table.entries[0].integerKey == 1);
    REQUIRE(table.entries[0].letterKey == 'A');
    REQUIRE(table.entries[1].integerKey == 1);
    REQUIRE(table.entries[1].letterKey == 'B');
    // Продолжайте проверку для остальных элементов
}

TEST_CASE("Test mergeSortParallel") {
    Table table;
    // Заполните table.entries данными для тестирования

    table.mergeSortParallel(0, table.entries.size() - 1);

    // Проверьте, что table.entries отсортирован корректно
    REQUIRE(table.entries[0].integerKey == 1);
    REQUIRE(table.entries[0].letterKey == 'A');
    REQUIRE(table.entries[1].integerKey == 1);
    REQUIRE(table.entries[1].letterKey == 'B');
    // Продолжайте проверку для остальных элементов
}

TEST_CASE("Test binarySearch") {
    Table table;
    // Заполните table.entries данными для тестирования

    bool found = table.binarySearch(2, 'C');
    REQUIRE(found == true);

    bool notFound = table.binarySearch(4, 'D');
    REQUIRE(notFound == false);
}

TEST_CASE("Test getResultsNotEmpty") {
    Table table;
    // Заполните table.entries данными для тестирования

    std::ostringstream resultStream;
    std::streambuf* oldCout = std::cout.rdbuf(resultStream.rdbuf());

    table.getResultsNotEmpty(2, 'C');
    REQUIRE(resultStream.str() == "Результат: TextC ");

    std::cout.rdbuf(oldCout); // Восстанавливаем cout
}

TEST_CASE("Test checkEngKey") {
    char validLetter = 'A';
    int validResult = checkEngKey(validLetter);
    REQUIRE(validResult == 0);

    char invalidLetter = '1';
    int invalidResult = checkEngKey(invalidLetter);
    REQUIRE(invalidResult == 1);
}