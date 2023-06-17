#ifndef ARRAY_H
#define ARRAY_H

namespace dtstr{

    template <typename DataType> class Array{
        
        private:
            int length;
            DataType* ptr;
            bool verbose;
            char sorted;
        
            char check(int indx, char arng);
        
        public:
            Array(int size, DataType value, bool ver=true);
            void insert(int index, DataType value);
            DataType get(int index);
            void display();

            // void bubbleSort(char arng);
            // void insertionSort();
            // void selectionSort();
            DataType linerSearch(DataType value);
            // DataType binarySearch(DataType value); 

            void message(bool ver);
            char isSorted();

    };
}

#endif