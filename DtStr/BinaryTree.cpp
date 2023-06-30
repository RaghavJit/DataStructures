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

    template <typename DataType> node<DataType>::node(DataType value, node* pnt, node* rgt, node* lft){
        data = value;
        parent = pnt;
        right = rgt;
        left = lft;
    }

    template class BinaryTree<bool>;
    template class BinaryTree<char>;
    template class BinaryTree<int>;
    template class BinaryTree<float>;
    template class BinaryTree<double>;
    template class BinaryTree<long>;

    template <typename DataType> BinaryTree<DataType>::BinaryTree(bool ver){
        root = nullptr;
        verbose = ver;
        size = 0;

        if(verbose){
            cout<<"Tree created"<<endl;
        }
    }

    template <typename DataType> node<DataType>* BinaryTree<DataType>::getChild(node<DataType>* target, char child){
        if(child == 'l'){
            return target->left;
        }
        else if(child == 'r'){
            return target->right;
        }
        return target;
    }    

    template <typename DataType> node<DataType>* BinaryTree<DataType>::getParent(string position){
        node<DataType>* pos = root;
        bool breakLoop = false;
        for(char ch : position.substr(1, position.length()-2)){
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
            if(breakLoop){
                if(verbose){
                    cout<<"dtstr >> Error: Invalid position string"<<endl;
                }
                return pos;
            }
        }
        return pos;
    }

    template <typename DataType> void BinaryTree<DataType>::insert(DataType value, string position, char child){
        
        node<DataType>* newNode = new node(value);
        node<DataType>* temp = getChild(newNode, child); 
        
        if(position == "x"){
            temp = root;
            root = newNode;
            return;
        }

        node<DataType>* parent = getParent(position);
        node<DataType>* target = getChild(parent, position.back());
        
        newNode->parent = parent;
        
        temp = target;
        if(target != nullptr){ 
            target->parent = newNode;
        }
    }
}