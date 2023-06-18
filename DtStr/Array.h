#ifndef ARRAY_H
#define ARRAY_H

namespace dtstr{

    template <typename DataType> class Array{
        
        private:
            int length;
            DataType* ptr;
            bool verbose;
        
            char check(int indx, char arng);
        
        public:
            Array(int size, DataType value, bool ver=true);
            void insert(int index, DataType value);
            DataType get(int index);
            void display();

            void bubbleSort(char arng);
            void insertionSort(char arng);
            // void selectionSort(char arng);
            int linerSearch(DataType value);
            int binarySearch(DataType value);
            void reverse(); 

            void message(bool ver);
            int getLength();
            char isSorted();

            DataType* operator[](int index);
    };
    

}

#endif