#ifndef QUEUE_H
#define QUEUE_H

#include "Array.h"

namespace dtstr{
    
    class Queue{
    
        protected:
            int length;
            int head, tail;
            bool verbose;
            Array* array;
        
        public:
            Queue(int size, int value=0, bool ver=true);
            void enqueue_r(int value);
            int dequeue_f();
            void display();
    };

    class DoubleEndedQueue : public Queue {

        public:
            DoubleEndedQueue(int size, int value=0, bool ver=true);
            void enqueue_f(int value);
            int dequeue_r();
    };

    class CircularQueue {
        
        protected:
            int length;
            int head, tail;
            bool verbose;
            Array* array;
        
        public:
            CircularQueue(int size, int value=0, bool ver=true);
            void enqueue(int value);
            int dequeue();
            void display();
    };
}

#endif
