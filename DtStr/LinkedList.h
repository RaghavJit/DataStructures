#ifndef LINKEDLIST_H
#define LINKEDLIST_H

namespace dtstr{

    class node_1{
        
        public:
            int data;
            node_1* next;

            node_1(int value);
    };

    class node_2{
        
        public:
            int data;
            node_2* next;
            node_2* prev;

            node_2(int value);
    };

    class SinglyLinkedList{
        
        private:
            node_1* head;
            
            SinglyLinkedList()
    };
}

#endif
