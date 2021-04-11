#include <iostream>
#include "ClassHashTable/HashTable.h"
#include "Generation/Generation.h"

using namespace std;

int main() {
    HashTable h(10, 80);

    //рандомная генерация
    //generationRecords (h, 50);
    //h.WriteHashTable ();
    //cout << h;

    // 10 записей для тестов:
    student student0 = {"Savorov A T", "0000 000000", "6.1", 123};
    student student1 = {"Ivanov A T", "1000 000000", "6.1", 342};
    student student2 = {"Savorov A T", "1300 000000", "6.1", 234};
    student student3 = {"Petrov A T", "3000 000000", "6.1", 104};
    student student4 = {"Savorov A T", "4000 000000", "6.1", 432};
    student student5 = {"Petrov A T", "6000 000000", "6.1", 231};
    student student6 = {"Sorokin A T", "5000 000000", "6.1", 231};
    student student7 = {"Vishniakov A T", "1200 000000", "6.1", 345};
    // колизия с student7 и student1
    student student8 = {"Lasarenko A T", "1100 000000", "6.1", 132};
    // паспорт совпал с student1
    student student9 = {"Kosicina A T", "1000 000000", "6.1", 235};

    h.WriteHashTable();
    h.Add(student0);
    h.Add(student1);
    h.Add(student2);
    h.Add(student7);
    h.Add(student9);
    h.Add(student3);
    h.Add(student4);
    h.Add(student5);
    h.Add(student6);
    //h.Add(student7);
    h.Add(student8);
    //h.Add(student9);
    //cout << (int)'0' << endl;
    h.WriteHashTable();

    h.Del(student8);
    h.Del(student5);
    h.Del(student6);
    //h.Del(student1);
    h.WriteHashTable();
    cout << h.Search(student6) << endl;
/*
    student a,b;
    string p = "A000 000000";
    string p1 = "E000 000000";
    a = {"Savorov A T", p, "6.1", 1000};
    b= {"Ivanov  A T", p1, "8.1", 2000};

    // добавляем 10 записей в таблицу с разными фамилиями и паспортами
    for (int i = 0; i < 6; ++i) {
    //   cout << a.FIO << endl;
      //  cout << b.FIO << endl;
        Количество ячеек: 10;
        h.Add(b);
        //cout << h.Search(a) << endl;
        a.passport[0] += 5;
        b.passport[0] -= 5;
        a.roomNumber += 5;
        b.roomNumber -= 5;
        //   a.FIO[0] -= 1;
        // a.FIO[1] += 1;
    }

    h.WriteHashTable();

    */
/* занесение одинаковых записей
    for (int i = 0; i < 10; ++i) {
        cout << a.FIO << endl;
        h.Add(a);
        //a.passport[0] += 2;
        a.FIO[0] -= 1;
        a.FIO[1] += 1;
    }
    h.WriteHashTable (); *//*

    //cout << h;
    //попытка удалить записи с не совпадающими с таблицей паспортами
    student aa = {"Savorov A T", p, "6.1", 1000};
    student bb = {"Ivanov  A T", p1, "8.1", 2000};
    for (int i = 0; i < 5; ++i) {
        aa.passport[0] += 10;
        bb.passport[0] -= 10;
        aa.roomNumber += 10;
        bb.roomNumber -= 10;
     //   cout << a.FIO << ' ' << a.passport << endl;
        h.Del(a);
        h.Del(b);
      //  h.WriteHashTable();
    }

    h.WriteHashTable();
    //cout << h;

    // нельзя добавить в таблицу двух людей с одинаковыми ФИО,
    // поэтому появится одно предупреждение, что студент и эта запись не добавится
    // остальные спокойно добавятся
    for (int i = 0; i < 10; ++i) {
        cout << a.FIO <<" "<<a.passport<<" "<< a.roomNumber<<endl;
        h.Add(a);
        h.Add(b);
        a.passport[0] -= 5;
        b.passport[0] += 5;
        a.roomNumber -= 5;
        b.roomNumber += 5;
    }

    h.WriteHashTable();
    //cout << h;
*/

    return 0;
}

