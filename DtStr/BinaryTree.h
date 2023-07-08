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
            int size;
            bool verbose;
            node<DataType>* getChild(node<DataType>* target, char child);
            void setChild(node<DataType>* prntNode, node<DataType>* chldNode, char child);
            node<DataType>* getParent(std::string position, char stop='p');
            char sibChar(char child);

        public:
            node<DataType>* root;
            
            BinaryTree(bool ver=true);
            void insert(DataType value ,std::string position="x", char child='l');
            DataType remove(std::string position, char child='l');
            void replace(std::string position, DataType value);
            DataType get(std::string position);
            void preOrder(node<DataType>* head);
            void inOrder(node<DataType>* head);
            void postOrder(node<DataType>* head);
    };

    template <typename DataType> class BinarySearchTree : public BinaryTree<DataType>{
        
        protected:
            char treeBias;
            char treeOrder;

        public:
            node<DataType>* root;

            BinarySearchTree(bool ver=true, char bias='r', char order='r');
            void insert(DataType value);
            DataType remove(std::string position);
            std::string search(DataType value);
            void balance(); 
    };

    template <typename DataType> class Heap : public BinaryTree<DataType>{
        
        public:
            Heap(char type, bool ver=true);
            void insert(DataType value);
            DataType remove(std::string position);
            void sort();
    };
            
}

#endif