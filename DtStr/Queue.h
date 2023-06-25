#ifndef QUEUE_H
#define QUEUE_H

#include "Array.h"
#include "LinkedList.h"

namespace dtstr{
    
    template <typename DataType> class Queue{
    
        protected:
            int length;
            int head, tail;
            bool verbose;
            Array<DataType>* array;
        
        public:
            Queue(int size, DataType value, bool ver=true);
            void enqueue_r(DataType value);
            DataType dequeue_f();
            void display();

            void message(bool ver);
            bool isEmpty();
            bool isFull();
            int getLength();
    };

    template <typename DataType> class DoubleEndedQueue : public Queue<DataType> {

        public:
            DoubleEndedQueue(int size, DataType value, bool ver=true);
            void enqueue_f(DataType value);
            DataType dequeue_r();
    };

    template <typename DataType> class CircularQueue {
        
        protected:
            int length;
            int head, tail;
            bool verbose;
            Array<DataType>* array;
        
        public:
            CircularQueue(int size, DataType value, bool ver=true);
            void enqueue(DataType value);
            DataType dequeue();
            void display();

            void message(bool ver);
            bool isEmpty();
            int getLength();
    };

    template <typename DataType> class DynamicQueue{

        private:
            int length;
            bool verbose;
            DoubleLinkedList<DataType>* llist;

        public:
            DynamicQueue(bool ver=true);
            void enqueue(DataType value);
            DataType dequeue();
            void display();
    };
}

#endif
