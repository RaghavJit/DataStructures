#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>

namespace dtstr{

    template <typename DataType> class node{
        
        public:
            DataType data;
            node* parent;
            node* right;
            node* left;
    };

    template <typename DataType> class BinaryTree{
        
        protected:
            node* root;
            int size;
            bool verbose;
        
        public:
            BinaryTree();
            void insert(string position, DataType value);
            DataType remove(string position);
            DataType replace(string position);
            DataType get(string position);
            DynamicStack<DataType>* preOrder();
            DynamicStack<DataType>* inOrder();
            DynamicStack<DataType>* postOrder();
    };

    template <typename DataType> class BinarySearchTree : public BinaryTree{
        
        public:
            BinarySearchTree();
            void insert(DataType value);
            DataType remove(string position);
            string search(DataType value);
            void balance(); 
    };

    template <typename DataType> class Heap : public BinaryTree{
        
        public:
            Heap(char type);
            void insert(DataType value);
            DataType remove();
            DynamicStack<DataType>* sort();
    };
}

#endif