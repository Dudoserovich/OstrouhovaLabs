#include <iostream>
#include "Queue.h"

using namespace std;
/*
 * Очередь не кольцевая
 * Хвост на первую свободную
 */

int main() {
    Queue q(9);
 //   Queue q1(5);
    Queue q2(5);
    q2=q;
   for (int i = 1; i < 8; i++)
       q.add(i);
   //q2.add(1);
    cout << q.GetN()<<"Q: " << q << endl;
    cout <<q2.GetN()<< "Q2: " << q2 << endl;

    for (int i = 1; i < 5; i++) {
        q.del(true);
        q2.del(true);
    }

    q.GetN();
    cout << q.GetN()<<"Q: " << q << endl;
    cout <<q2.GetN()<< "Q2: " << q2 << endl;


    for (int i = 1; i < 3; ++i) {
        q.add(i*10);
    }
    cout << q.GetN()<<"Q: " << q << endl;
    cout << q.del(false) << q << endl;
    cout <<q2.GetN()<< "Q2: " << q2 << endl;

   /* Queue q(5);
    q.add(1);
    q.add(2);
    q.add(3);
    Queue q1(8);
    q1.add(0);
    q1.add(0);
    q1.add(3);
    q1.add(2);

    Queue q2(6);
    q2.add(4);
    q2.add(4);
    q2.add(3);
    q2.add(-1);
    q2.add(-2);
    q2.add(-3);
    q2 = q1 = q;
    cout << q << endl;
    cout << q1 << endl;
    cout << q2 << endl;
    //cout << q.del(false) << endl;
/*    Queue q1(10);
    //Queue qq(0);
    //cout << qq << '\n' << qq.length() << endl;
    for (int i = 0; i < 8; ++i) {
        q.add(5);
    }
    cout << q << endl;
    for (int i = 0; i < 4; ++i) {
        q1.add(2);
    }
    cout << q1 << endl;
    //Queue qq = Queue(q);
    //cout << qq;
    // true - вытаскивает значение, false - не вытаскивает
    cout << q.del(false) << endl;
    cout << q.del(true) << endl;
    cout << q << endl;
    q1 = q;
    cout << q1 << endl;
    q.clear();
    q.clear();
    q1 = q;
    cout << q1 << endl;
    //q1.clear();
    //cout << q1 << endl;*/
    return 0;
}
