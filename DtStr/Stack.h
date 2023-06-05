#ifndef STACK_H
#define STACK_H

#include "Array.h"

namespace dtstr{
    
    class Stack{
        
        private:
            int length, top=0;
            bool verbose;
            Array* array;
        
        public:
            Stack(int size, int value=0, bool ver=true);
            void push(int value);
            int pop();
            void display();
    };
}

#endif