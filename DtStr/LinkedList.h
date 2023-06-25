#ifndef LINKEDLIST_H
#define LINKEDLIST_H

namespace dtstr{

    template <typename DataType> class node_1{
        
        public:
            DataType data;
            node_1<DataType>* next;

            node_1(DataType value);
            node_1(node_1<DataType>* n);
            node_1<DataType>& operator++(int);
    };

    template <typename DataType> class node_2{
        
        public:
            DataType data;
            node_2<DataType>* next;
            node_2<DataType>* prev;

            node_2(DataType value, node_2* pre=nullptr);
    };

    template <typename DataType> class iter{
        public:
            node_1<DataType>* nodeptr;

            iter(node_1<DataType>* node);
            iter<DataType> operator++(int);
            node_1<DataType>* operator->();
            node_1<DataType> operator*();
    };

    template <typename DataType> class SinglyLinkedList{

        private:
            int length;
            bool verbose;

        public:
            node_1<DataType>* start;

            SinglyLinkedList(bool ver=true);
            void insert(int index, DataType value);
            void replace(int index, DataType value);
            DataType get(int index);
            DataType remove(int index);
            void display();

            DataType* operator[](int index);
    };

    template <typename DataType> class DoubleLinkedList : public SinglyLinkedList<DataType>{

        private:
            node_2<DataType>* start;
            node_2<DataType>* end;
            int length;
            bool verbose;

        public:
            DoubleLinkedList(bool ver=true);
            void insert(int index, DataType value);
            void replace(int index, DataType value);
            DataType get(int index);
            DataType remove(int index);
            void display();
            void reverse(); 
    };
}

#endif