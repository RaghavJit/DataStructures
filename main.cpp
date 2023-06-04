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
    return 0;
}