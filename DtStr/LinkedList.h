#ifndef LINKEDLIST_H
#define LINKEDLIST_H

namespace dtstr{

    template <typename DataType> class node_1{
        
        public:
            DataType data;
            node_1<DataType>* next;

            node_1(DataType value);
    };

    template <typename DataType> class iterSL{
        public:
            node_1<DataType>* nodeptr;

            iterSL(node_1<DataType>* node);
            iterSL<DataType> operator++(int);
            node_1<DataType>* operator->();
            node_1<DataType> operator*();
    };

    template <typename DataType> class node_2{
        
        public:
            DataType data;
            node_2<DataType>* next;
            node_2<DataType>* prev;

            node_2(DataType value, node_2* pre=nullptr);
    };

    template <typename DataType> class iterDL{
        public:
            node_2<DataType>* nodeptr;

            iterDL(node_2<DataType>* node);
            iterDL<DataType> operator++(int);
            iterDL<DataType> operator--(int);
            node_2<DataType>* operator->();
            node_2<DataType> operator*();
    };


    template <typename DataType> class SinglyLinkedList{

        private:
            node_1<DataType>* start;
            int length;
            bool verbose;

        public:

            SinglyLinkedList(bool ver=true);
            void insert(int index, DataType value);
            void replace(int index, DataType value);
            DataType get(int index);
            DataType remove(int index);
            void display();

            void message(bool ver);
            bool isEmpty();

            DataType* operator[](int index);
    };

    template <typename DataType> class DoubleLinkedList{

        protected:
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

            void message(bool ver);
            bool isEmpty();            

            DataType* operator[](int index);

    };

    template <typename DataType> class CircularLinkedList : public DoubleLinkedList<DataType> {

        public:
            CircularLinkedList(bool ver=true);
            void insert(int index, DataType value);
    };
}

#endif