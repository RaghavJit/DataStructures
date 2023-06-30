#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>
#include "Stack.h"

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
            node<DataType>* getChild(node<DataType>* target, char child);
            node<DataType>* getParent(std::string position);

        public:
            BinaryTree(bool ver=true);
            void insert(DataType value ,std::string position="x", char child='l');
            DataType remove(std::string position);
            DataType replace(std::string position);
            DataType get(std::string position);
            DynamicStack<DataType>* preOrder();
            DynamicStack<DataType>* inOrder();
            DynamicStack<DataType>* postOrder();
    };

    template <typename DataType> class BinarySearchTree : public BinaryTree<DataType>{
        
        public:
            BinarySearchTree(bool ver=true);
            void insert(DataType value);
            DataType remove(std::string position);
            std::string search(DataType value);
            void balance(); 
    };

    template <typename DataType> class Heap : public BinaryTree<DataType>{
        
        public:
            Heap(char type, bool ver=true);
            void insert(DataType value);
            DataType remove();
            DynamicStack<DataType>* sort();
    };
}

#endif