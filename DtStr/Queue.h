#ifndef QUEUE_H
#define QUEUE_H

#include "Array.h"

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
    };
}

#endif
