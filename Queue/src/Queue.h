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

    // длина очереди
    [[nodiscard]] unsigned int length() const;

public:

    // конструктор по умолчанию
    Queue();

    explicit Queue(unsigned int size);

    // конструктор копирования
    Queue(const Queue &obj);

    // перегруженное присваивание очередей
    Queue &operator=(Queue &obj);

    // Операции над вектором:
    bool add(int a);

    // true - вытаскивает значение, false - не вытаскивает
    int del(bool check);

    // очистка очереди
    bool clear();

    // печать
    friend ostream &operator<<(ostream &out, Queue q) {
        cout << "очередь заполнена на " << q.GetN() << " из " << q.length() << endl;
        if (q.tail == 0)
            cout << "Очередь пуста!" << endl;
        else {
            for (int i = q.head; i < q.tail; i++)
                cout << q.vector[i] << "\t";
            cout << endl;
        }
            cout << "---------------------" << endl;
    }

    // количество элементов в очереди
    [[nodiscard]] int GetN() const {
        return (tail - head);
    }

    // деструктор
    ~Queue() {
        if (GetN() > 0) {
            delete[] vector;
        }
    }

};

