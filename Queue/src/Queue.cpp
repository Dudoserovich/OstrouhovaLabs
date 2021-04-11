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
        if (head == tail)
            vector[head] = a;
        else
            vector[tail] = a;
        tail++;
        return true;
    } else {
        cout << "Очередь заполнена" << endl;
        return false;
    }
}

// true - вытаскивает значение, false - не вытаскивает
int Queue::del(bool check) {
    //если хвост указывает не на последний эл-т + 1, то удаляем
    if (((tail - 1) < max_size) && (GetN() != 0)) {
        if (head == tail)
            tail = tail;
        else if (check) {
            tail--;
            return 1;
        } else return (tail - 1);
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
Queue &Queue::operator=(const Queue &obj) {
    int *vector2; // указатель на дополнительную память

    try {
        // попытка выделить новый участок памяти для vector2
        vector2 = new int[obj.max_size];

        //сохраняем значения массива, которые могут быть дополнительно занесены
        // спроси у Остр нужно ли это, если нет, то просто закоменьть 109, 110, 130-136
        int *help_vector = new int[tail];
        int help_tail = tail;
        for (int i = 0; i < help_tail; ++i) {
            help_vector[i] = vector[i];
        }

        // если память выделена успешно,
        // можно освобождать предварительно выделенную память для vector
        if (GetN() > 0)
            delete[] vector;

        // скопировать obj в текущий объект
        vector = vector2; // перенаправить vector на vector2
        max_size = obj.max_size;
        tail = obj.tail;
        head = obj.head;

        // заполнить значениями
        for (int i = 0; i < obj.tail; i++)
            vector[i] = obj.vector[i];
        // добавление не заменённых элементов из vector (того, чему присваиваем)
        if ((obj.tail < help_tail) && (tail != max_size)) { //&& (help_tail < max_size)) {
            // если количество элементов из очереди,
            // которой присваивают превышает размер очереди, которую присваивают,
            // добавлять столько элементов из очер., кот. присв., сколько возможно
            if ((help_tail > max_size))
                help_tail = max_size;
            for (int i = obj.tail; i < help_tail; ++i) {
                vector[i] = help_vector[i];
            }
            tail = help_tail;
        }
        delete[] help_vector;

    }
    catch (bad_alloc e) {
        // если память не выделилась, то вывести соответствующее сообщение
        cout << e.what() << endl;
    }
    return *this; // вернуть текущий объект
}