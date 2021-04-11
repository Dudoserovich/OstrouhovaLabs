#pragma once

#include <string>

using namespace std;

struct student {
    string FIO;
    string passport;
    string hostel;
    unsigned int roomNumber;
};

class HashTable {
private:
    student *table;
    unsigned int ResizeUpper_occupancy; // в процентах от 0 до 100
    unsigned int occupancy;             // процент заполненности от 0 до 100

    // вектор состояний: 0/1
    int *status;
    int max_size;

    // 3) Hash_f1 (key) -> addr
    [[nodiscard]] int HashF1(string key) const;

    // 4) Hash_f2 (hash, n попытки) -> add
    [[nodiscard]] int HashF2(int h1, int n) const;

    // расширение/сужение
    void Resize(bool check);

public:

    // 1) Конструктор (N, % заполнияемости)
    HashTable(int max_size, unsigned int ResizeUpper_occupancy);

    // 2) Деструктор
    ~HashTable();

    // 5) Add (record) -> 1/0
    int Add(student pupil);

    // 6) Del (record) -> 1/0
    int Del(student pupil);

    // 7) Search (record) -> (true/false)
    bool Search(student pupil);

    // 8) Печать (перегрузка оператора вывода в поток <<)
    void WriteHashTable ();

    // собственные функции:

    // 1. инициализация массива статусов
    void initStatus();

};
