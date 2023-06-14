#ifndef LINKEDLIST_H
#define LINKEDLIST_H

namespace dtstr{

    template <typename DataType> class node_1{
        
        public:
            DataType data;
            node_1* next;

            node_1(DataType value);
    };

    template <typename DataType> class node_2{
        
        public:
            DataType data;
            node_2* next;
            node_2* prev;

            node_2(DataType value, node_2* pre=nullptr);
    };

    template <typename DataType> class SinglyLinkedList{

        private:
            node_1<DataType>* start;
            int length;
            bool verbose;

        public:
            SinglyLinkedList(bool ver=true);
            void insert(int index, DataType value);
            DataType remove(int index);
            void display();
    };
}

#endif