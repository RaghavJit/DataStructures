#ifndef STACK_H
#define STACK_H

#include "Array.h"
#include "LinkedList.h"

namespace dtstr{
    
    template <typename DataType> class Stack{
        
        private:
            int length, top=0;
            bool verbose;
            Array<DataType>* array;
        
        public:
            Stack(int size, DataType value, bool ver=true);
            void push(DataType value);
            DataType pop();
            void display();

            void message(bool ver);
            bool isEmpty();
            bool isFull();
            int getLength();
    };

    template <typename DataType> class DynamicStack{

        private:
            int length;
            bool verbose;
            DoubleLinkedList<DataType>* llist;

        public:
            DynamicStack(bool ver=true);
            void push(DataType value);
            DataType pop();
            void display();
    };
}

#endif