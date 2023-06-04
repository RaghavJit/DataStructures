#include "dtstr.h"

int main(){
    dtstr::Array arr1(5, 1);

    arr1.insert(0, 7);
    arr1.display();

    return 0;
}