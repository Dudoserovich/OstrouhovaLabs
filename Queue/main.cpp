#include <iostream>
#include "Queue.h"

using namespace std;
/*
 * Очередь не кольцевая
 * Хвост на первую свободную
 */

int main() {
/*    Queue q(8);
    cout << q.del(false) << endl;
    q.add(1);
    q.add(2);
    q.add(3);
    q.add(4);
    q.add(4);
    Queue q1(5);
    Queue q2(3);
    cout << q << endl;
    q2 = q = q1;
    q1.add(333);
    q2.add(555);

    cout << q << endl;
    cout << q1 << endl;
    cout << q2 << endl;*/

    Queue q(5);
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
