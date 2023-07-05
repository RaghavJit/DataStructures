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

    template <typename DataType> void BinaryTree<DataType>::setChild(node<DataType>* prntNode, node<DataType>* chldNode, char child){
        if(child == 'l'){
            prntNode->left = chldNode;
        }
        if(child == 'r'){
            prntNode->right = chldNode;
        }
        if(chldNode != nullptr){
            chldNode->parent = prntNode;
        }
    }

    template <typename DataType> node<DataType>* BinaryTree<DataType>::getParent(string position, char stop){
        node<DataType>* pos = root;
        bool breakLoop = false;
        int end = position.length()-1;
        if(stop == 'p'){ // default case
            end = end - 1;
        }
        for(char ch : position.substr(1, end)){
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

    template <typename DataType> char BinaryTree<DataType>::sibChar(char child){
        if(child == 'r'){
            return 'l';
        }
        else if(child == 'l'){
            return 'r';
        }
        return child;
    }

    template <typename DataType> void BinaryTree<DataType>::insert(DataType value, string position, char child){
        
        node<DataType>* newNode = new node(value);
        
        if(position == "x"){
            setChild(newNode, root, child);
            root = newNode;
            return;
        }

        node<DataType>* parent = getParent(position);
        node<DataType>* target = getChild(parent, position.back());
        
        setChild(parent, newNode, position.back());
        setChild(newNode, target, child);
        
        if(target != nullptr){ 
            target->parent = newNode;
        }
    }

    template <typename DataType> DataType BinaryTree<DataType>::remove(string position, char child){

        char sib =  sibChar(child);

        node<DataType>* parent = getParent(position);
        node<DataType>* target = getChild(parent, position.back());
        
        node<DataType>* backup = getChild(target, sib);
        node<DataType>* pos = getChild(target, child);

        setChild(parent, pos, position.back());

        while(true){
            node<DataType>* temp = getChild(pos, sib);
            setChild(pos, backup, sib);
            if(temp == nullptr){
                break;
            }
            backup = temp;
            pos = getChild(pos, child);
            if(pos == nullptr){
                setChild(pos, backup, child);
            }
        }

        return target->data;
    }

    template <typename DataType> void BinaryTree<DataType>::replace(string position, DataType value){
        node<DataType>* target = getParent(position, 't');
        target->data = value;
    }

    template <typename DataType> DataType BinaryTree<DataType>::get(string position){
        node<DataType>* target = getParent(position, 't');
        return target->data;
    }

    template <typename DataType> void BinaryTree<DataType>::preOrder(node<DataType>* head){

        if(head == nullptr){
            return;
        }
        cout<<head->data;
        this->preOrder(head->left);
        this->preOrder(head->right);
    }

    template <typename DataType> void BinaryTree<DataType>::inOrder(node<DataType>* head){

        if(head == nullptr){
            return;
        }
        this->inOrder(head->left);
        cout<<head->data;
        this->inOrder(head->right);
    }

    template <typename DataType> void BinaryTree<DataType>::postOrder(node<DataType>* head){

        if(head == nullptr){
            return;
        }
        this->postOrder(head->left);
        this->postOrder(head->right);
        cout<<head->data;
    }
}