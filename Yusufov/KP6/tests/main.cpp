#include "../include/Database.hpp"

int main() {
    Database db("applicants");

    Row r1(
            "Korovina",
            "I. A.",
            'F',
            988,
            false,
            86,
            79,
            79,
            true
    );

    Row r2(
            "Tretiakova",
            "L. P.",
            'F',
            2077,
            true,
            100,
            100,
            98,
            true
    );

    Row r3(
            "Kovalyov",
            "N. O.",
            'M',
            1242,
            true,
            95,
            70,
            70,
            true
    );

    Row r4(
            "Zubenko",
            "M. P.",
            'M',
            1976,
            false,
            81,
            62,
            63,
            true
    );

    Row r5(
            "Mironova",
            "E. S.",
            'F',
            2033,
            true,
            97,
            45,
            97,
            true
    );

    Row r6(
            "Sokolova",
            "R. B.",
            'F',
            1922,
            false,
            69,
            69,
            69,
            true
    );

    Row r7(
            "Yermakov",
            "F. D.",
            'M',
            146,
            true,
            1,
            2,
            3,
            true
    );

    Row r8(
            "Vinogradova",
            "A. S.",
            'F',
            359,
            true,
            19,
            84,
            46,
            true
    );

    db.add_row(r1);
    db.add_row(r2);
    db.add_row(r3);
    db.add_row(r4);
    db.add_row(r5);
    db.add_row(r6);
    db.add_row(r7);
    db.add_row(r8);

    db.print();
    db.lab_task();
    
    return 0;
}
