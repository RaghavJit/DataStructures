#include "dtstr.h"

int main(){
    dtstr::Array arr1(5, 1);

    arr1.insert(0, 7);
    arr1.display();

    dtstr::Stack sta1(4, 1);
    sta1.push(1);
    sta1.push(2);
    sta1.push(3);
    sta1.pop();
    sta1.pop();
    sta1.pop();
    sta1.pop();
    sta1.display();

    dtstr::DoubleEndedQueue dque(5, 0);
    dque.enqueue_r(19);
    dque.enqueue_r(33);
    dque.dequeue_r();
    dque.display();

    dtstr::CircularQueue cque(5, 2);
    cque.enqueue(1);
    cque.enqueue(17);
    cque.dequeue();
    cque.dequeue();
    cque.display();
    return 0;
}