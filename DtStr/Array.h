namespace dtstr{

    class Array{
        
        private:
            int length;
            int* ptr;
        
        public:
            Array(int size, int value=0);
            void insert(int index, int value);
            void display();
    };

}