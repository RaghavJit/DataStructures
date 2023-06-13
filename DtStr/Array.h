#ifndef ARRAY_H
#define ARRAY_H

namespace dtstr{

    template <typename DataType> class Array{
        
        private:
            int length;
            DataType* ptr;
            bool verbose;
        
        public:
            Array(int size, DataType value, bool ver=true);
            void insert(int index, DataType value);
            DataType get(int index);
            void display();
    };
}

#endif