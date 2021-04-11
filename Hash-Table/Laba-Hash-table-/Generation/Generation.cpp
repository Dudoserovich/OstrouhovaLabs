#include "../ClassHashTable/HashTable.h"
#include <iostream>
#include <ctime>
#include <cmath>

void generationRecords(HashTable &ht, int count) {
    char ch[27] = "qwertyuiopasdfghjklzxcvbnm";
    char numb[11] = "0123456789";
    srand(time(nullptr));

    //генерация записей
    for (int i = 0; i < count; ++i) {
        student pupil;

        //генерация фамилий
        pupil.FIO = "";
        for (int j = 0; j < 10; ++j) {
            if ((j == 6) || (j == 8)) {
                pupil.FIO += ' ';
                j++;
            }
            if ((j == 0) || (j == 7) || (j == 9))
                pupil.FIO += ch[rand() % 26] - 32;
            else
                pupil.FIO += ch[rand() % 26];
        }
        pupil.FIO[10] = '\0';

        //генерация номеров общежитий
        pupil.hostel = "";
        for (int j = 0; j < 3; ++j) {
            if (j == 1) {
                pupil.hostel += '.';
                j++;
            }
            pupil.hostel += numb[rand() % 9 + 1];
        }
        pupil.hostel += '\0';

        //генерация номеров комнат (int)
        int rank = 10;
        pupil.roomNumber = 0;
        for (int j = 0; j < 3; ++j) {
            pupil.roomNumber += (rand() % 3 + j) * pow(rank, j);
        }

        //генерация паспортов
        pupil.passport = "";
        for (int j = 0; j < 10; ++j) {
            pupil.passport += numb[rand() % 9 + 1];
        }
        pupil.hostel += '\0';
        ht.Add(pupil);
        //cout << ht.Add(pupil) << endl;
    }
    //cout << ht;
}