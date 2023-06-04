#ifndef ARRAY_H
#define ARRAY_H

namespace dtstr{

    class Array{
        
        private:
            int length;
            int* ptr;
            bool verbose;
        
        public:
            Array(int size, int value=0, bool ver=true);
            void insert(int index, int value);
            int get(int index);
            void display();
    };
}

#endif