#ifndef TRIPLEHPP
#define TRIPLEHPP

class DataBase;

template <typename T, typename U, typename K>
class Triple{
    friend class DataBase;
private:
    T first;
    U second;
    K third;

public:
    Triple() = default;
    Triple(const T& first, const U& second, const K& third);
    ~Triple() = default;

    T& get_first();
    U& get_second();
    K& get_third();
    const T& get_first() const;
    const U& get_second() const;
    const K& get_third() const;
};

#include "../src/Triple.cpp"
#endif //TRIPLEHPP