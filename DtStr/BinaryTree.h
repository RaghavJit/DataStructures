#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>

namespace dtstr{

    template <typename DataType> class node{
        
        public:
            DataType data;
            node<DataType>* parent;
            node<DataType>* right;
            node<DataType>* left;

            node(DataType value, node* pnt=nullptr, node* rgt=nullptr, node* lft=nullptr);
    };

    template <typename DataType> class BinaryTree{
        
        protected:
            node<DataType>* root;
            int size;
            bool verbose;
        
        public:
            BinaryTree(bool ver=true);
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
            BinarySearchTree(bool ver=true);
            void insert(DataType value);
            DataType remove(string position);
            string search(DataType value);
            void balance(); 
    };

    template <typename DataType> class Heap : public BinaryTree{
        
        public:
            Heap(char type, bool ver=true);
            void insert(DataType value);
            DataType remove();
            DynamicStack<DataType>* sort();
    };
}

#endif