#include "HashTable.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int max_size, unsigned int ResizeUpper_occupancy) {
    this->max_size = max_size;
    if (max_size < 10) this->max_size = 10;
    table = new student[this->max_size];
    if (ResizeUpper_occupancy < 40)
        this->ResizeUpper_occupancy = 40;
    else
        this->ResizeUpper_occupancy = ResizeUpper_occupancy;
    occupancy = 0;

    status = new int[this->max_size];
    initStatus();
}

void HashTable::initStatus() {
    for (int i = 0; i < this->max_size; i++) {
        status[i] = 0;
    }
}

HashTable::~HashTable() {
    delete[] table;
    delete[] status;
}

ostream &operator<<(ostream &out, student record) {
    out << record.FIO << ", паспорт: ";
    for (int i = 0; i < 10; ++i) {
        if (i == 4)
            out << ' ';
        out << record.passport[i];
    }
    out << ", общежитие: " << record.hostel
        << ", комната: " << record.roomNumber;
    return out;
}

void HashTable::WriteHashTable () {
    int memento;
    cout << "\t\t\t\t\t\t\tHASH TABLE" << endl;
    //проверка на пустоту таблицы
    for (int i = 0; i < max_size; ++i) {
        memento = i;
        if (status[i] == 1) {
            break;
        }
    }
    if (memento == max_size - 1)
        cout << "Таблица пуста!" << endl;
    else {
        for (int i = 0; i < max_size; i++) {
            cout << i << ")\t";
            if (status[i] == 1) {
                cout << table[i] << endl;
            } else if (status[i] == 0) {
                cout << "NULL" << endl;
            }
        }
        cout << endl;
    }
}

int HashTable::HashF1(string key) const {
    return key[0] % max_size;
}

int HashTable::HashF2(int h1, int n = 0) const {
    return (h1 + n) % max_size;
}

int HashTable::Add(student pupil) {
    int count = 0;
    int h1;
    if (HashF1(pupil.passport) == max_size - 1)
        h1 = 0;
    else
        h1 = HashF1(pupil.passport);
    int h2 = HashF2(h1, count);

    while (status[h2] == 1) { // посмотрели на наличие этого студента в таблице
        if (status[h2] == 1 && pupil.passport == table[h2].passport) {
            cout << "Студент с таким пасспортом уже добавлен: " << endl;
            cout << pupil << endl;
            return 0;
        }
        count++;             //с каждым разом увеличивается место,
                             // поэтому мы каждый раз передаём на +1 большее число в HashF2
        h2 = HashF2(h1, count);
    }

    if (((float) occupancy / (float) max_size) * 100 >= (float) ResizeUpper_occupancy) {
        Resize(false); // расширение
        Add(pupil);          // повторное добавление после расширения
    } else {
        occupancy++;         // считаем добавление;
        status[h2] = 1;
        table[h2] = pupil;
        return 1;
    }
}

int HashTable::Del(student pupil) {
    int count = 0;
    int h1;
    if (HashF1(pupil.passport) == max_size - 1)
        h1 = 0;
    else
        h1 = HashF1(pupil.passport);
    int h2 = HashF2(h1, count);

    while (status[h2] != 0) {
        if (status[h2] == 1
            && pupil.FIO == table[h2].FIO
            && pupil.passport == table[h2].passport
            && pupil.hostel == table[h2].hostel
            && pupil.roomNumber == table[h2].roomNumber) {

            occupancy--;
            status[h2] = 0;
            if (status[HashF2(h1, count + 1)]) {
                Resize(true); // сужение
                //ResizeLower(); // сужение
            }
            return 1; // найдено, удалено (состоние 0)
        }
        count++;
        h2 = HashF2(h1, count);
    }
    return 0; // не найдено
}

bool HashTable::Search(student pupil) {
    int count = 0;
    int h1;
    if (HashF1(pupil.passport) == max_size - 1)
        h1 = 0;
    else
        h1 = HashF1(pupil.passport);
    int h2 = HashF2(h1, count);
    while (status[h2] != 0) {

        if (pupil.FIO == table[h2].FIO
            && pupil.passport == table[h2].passport
            && pupil.hostel == table[h2].hostel
            && pupil.roomNumber == table[h2].roomNumber) {

            return true; // найдено
        }
        count++;
        h2 = HashF2(h1, count);
    }
    //cout << h2 << endl;
    return false; // не найдено
}

void HashTable::Resize(bool check) {
    this->occupancy = 0;

    student *new_table = table; // запомнили текущую таблицу
    int *new_status = status;

    int new_max_size = max_size;
    if (check)
        this->max_size /= 2;
    else
        this->max_size *= 2;
    if (this->max_size < 10) this->max_size = 10;

    this->status = new int[max_size];
    this->table = new student[max_size];

    initStatus(); // инициализация массива статусов

    //добавление в таблицу нового размера
    for (int i = 0; i < new_max_size; i++) {
        if (new_status[i] == 1) {
            Add(new_table[i]);
        }
    }

    // удаление прошлых массивов
    delete[] new_status;
    delete[] new_table;
}