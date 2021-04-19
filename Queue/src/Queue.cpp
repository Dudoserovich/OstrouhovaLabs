#pragma once

#include <iostream>
//#include <cmath>
using namespace std;

#include "Queue.h"

// конструктор по умолчанию
Queue::Queue() {
    this->max_size = 10;
    head = 0;
    tail = 0;
    vector = new int[max_size];
}

Queue::Queue(unsigned int size) {
    this->max_size = size;
    head = 0;
    tail = 0;
    vector = new int[size];
}

//конструктор копирования
Queue::Queue(const Queue &obj) {
    max_size = obj.max_size;
    // инициализация h и t
    // могут быть свои приколы, это пока не конечный вариант
    head = obj.head;
    tail = obj.tail;
    try {
        // попытка выделить память для vector
        vector = new int[max_size];
        // заполнить значениями
        for (int i = 0; i < max_size; i++)
            vector[i] = obj.vector[i];
    }
    catch (bad_alloc e) {
        // если память не выделена, то вывести текст ошибки
        cout << e.what() << endl;
        tail = 0; // создать пустую очередь
        head = 0;
    }
}

bool Queue::add(int a) {
    //если хвост указывает не на последний эл-т + 1, то добавляем
    if ((tail) < (int) max_size) {
        //if (head == tail)
        //    vector[head] = a;
        //else
            vector[tail] = a;
        tail++;
        return true;
    } else {
        // если tail дошёл до конца, а место в очереди ещё осталось
        if (head > 0) {
            int* new_vec = new int[max_size];
            int count = 0;
            for (int i = head; i < tail; ++i) {
                new_vec[count] = vector[i];
                count++;
            }
            head = 0;
            vector[count] = a;
            tail = count + 1;
        } else {
            cout << "Очередь заполнена" << endl;
            return false;
        }
    }
}

// true - вытаскивает значение, false - не вытаскивает
int Queue::del(bool check) {
    //если хвост указывает не на последний эл-т + 1, то удаляем
    if (((tail - 1) < max_size) && (GetN() != 0)) {
        if (head == tail)
            tail = tail;
        else if (check) {
            head++;
            return 1;
        } else return (head);
    } else {
        if (GetN() != 0)
            cout << "Очередь заполнена" << endl;
        return -1;
    }

}

unsigned int Queue::length() const {
    return max_size;
}

// очистка очереди
bool Queue::clear() {
    if (GetN() > 0) {
        delete[] vector;
        this->head = 0;
        this->tail = 0;
        return true;
    }
    cout << "Очередь уже пуста" << endl;
    return false;
}

// реализует присваивание объектов типа Queue
Queue &Queue::operator=(Queue &obj) {

    if (*obj.vector == *vector)
        return *this;

    // если память выделена успешно,
    // можно освобождать предварительно выделенную память для vector
    if (GetN() > 0)
        delete[] vector;

    // скопировать tail и head в текущий объект
    if (obj.tail > max_size)
        tail = max_size;
    else
        tail = obj.tail;
    head = obj.head;

    // заполнить значениями
    for (int i = 0; i < tail; i++)
        vector[i] = obj.vector[i];

    return *this; // вернуть текущий объект
}