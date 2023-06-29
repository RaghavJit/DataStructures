#include <iostream>
using namespace std;

#include "BinaryTree.h"

namespace dtstr{

    template class node<bool>;
    template class node<char>;
    template class node<int>;
    template class node<float>;
    template class node<double>;
    template class node<long>;

    template <typename DataType> node<DataType>::node(DataType value, node* pnt=nullptr, node* rgt=nullptr, node* lft=nullptr){
        data = value;
        parent = pnt;
        right = rgt;
        left = lft;
    }

    template <typename DataType> BinaryTree<DataType>::BinaryTree(bool ver){
        root = nullptr;
        verbose = ver;

        if(verbose){
            cout<<"Tree created"<<endl;
        }
    }

    template <typename DataType> void BinaryTree<DataType>::insert(string position, DataType value){

        node<DataType>* pos = root;
        bool breakLoop = false;

        for(char ch : position){
            switch (ch){
            case 'l':
                pos = pos->left;
                break;
            case 'r':
                pos = pos->right;
                break;
            default:
                breakLoop = true;
                break;
            }

            if(breakLoop || pos == nullptr){
                break;
            }
        }

        pos
        node<DataType>* newNode = new node(value, pos, pos->right, pos->left);

    }
}