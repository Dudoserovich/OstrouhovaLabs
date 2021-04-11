#pragma once

#include <new>
#include <iostream>

using namespace std;

class Queue {
private:
    int *vector;
    unsigned int max_size;
    int head;
    int tail;

    // свои методы:
    // количество элементов в очереди
    [[nodiscard]] int GetN() const {
        return (tail - head);
    }

public:

    // конструктор по умолчанию
    Queue();

    explicit Queue(unsigned int size);

    // конструктор копирования
    Queue(const Queue &obj);

    // перегруженное присваивание очередей
    Queue &operator=(const Queue &obj);

    // Операции над вектором:
    bool add(int a);

    // true - вытаскивает значение, false - не вытаскивает
    int del(bool check);

    // длина очереди
    [[nodiscard]] unsigned int length() const;

    // очистка очереди
    bool clear();

    // печать
    friend ostream &operator<<(ostream &out, Queue q) {
        cout << "размер очереди: " << q.length() << endl;
        if (q.tail == 0)
            cout << "Очередь пуста!" << endl;
        else {
            for (int i = 0; i < q.tail; i++)
                cout << q.vector[i] << "\t";
            cout << endl;
        }
            cout << "---------------------" << endl;
    }

    // деструктор
    ~Queue() {
        if (GetN() > 0) {
            delete[] vector;
        }
    }

};

