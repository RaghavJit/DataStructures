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
        node<DataType>* pos = this->root;
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

        size++;
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

        size--;

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

    template class BinarySearchTree<bool>;
    template class BinarySearchTree<char>;
    template class BinarySearchTree<int>;
    template class BinarySearchTree<float>;
    template class BinarySearchTree<double>;
    template class BinarySearchTree<long>;

    template <typename DataType> BinarySearchTree<DataType>::BinarySearchTree(bool ver, char bias, char order) : BinaryTree<DataType>(false){
        if(bias != 'r' && bias != 'l'){
            cout<<"dtstr >> Error : Invalid bias"<<endl;
            delete this;
        }
        if(order != 'r' && order != 'l'){
            cout<<"dtstr >> Error : Invalid order"<<endl;
            delete this;
        }
        BinaryTree<DataType>::verbose = ver;
        treeOrder = order;
        treeBias = bias;
        BinaryTree<DataType>::root = nullptr;
        if(BinaryTree<DataType>::verbose){
            cout<<"Tree created"<<endl;
        }
    }

    template <typename DataType> void BinarySearchTree<DataType>::insert(DataType value){
        node<DataType>* newNode = new node(value);

        if(BinaryTree<DataType>::root == nullptr){
            BinaryTree<DataType>::root = newNode;
            return;
        }

        node<DataType>* pos = BinaryTree<DataType>::root;

        while(true){    
            if((treeOrder == 'r' && pos->data > value) || (treeOrder == 'l' && pos->data < value)){
                if(pos->left == nullptr){
                    pos->left = newNode;
                    BinarySearchTree::size++;
                    break;
                }
                pos = pos->left;
            }
            else if((treeOrder == 'r' && pos->data < value) || (treeOrder == 'l' && pos->data > value)){
                if(pos->right == nullptr){
                    pos->right = newNode;
                    BinarySearchTree::size++;
                    break;
                }
                pos = pos->right;
            }
            else if(pos->data == value){
                node<DataType>* temp = BinaryTree<DataType>::getChild(pos, treeBias);
                BinaryTree<DataType>::setChild(pos, newNode, treeBias);
                BinaryTree<DataType>::setChild(newNode, temp, treeBias);
                BinarySearchTree::size++;
                break;
            }
        }
    }
    
    template <typename DataType> node<DataType>* BinarySearchTree<DataType>::getXtrm(node<DataType>* target, char side){
        char sib = BinaryTree<DataType>::sibChar(side);
        node<DataType>* pos = BinaryTree<DataType>::getChild(target, side);
    
        if(pos == nullptr){
            return BinaryTree<DataType>::getChild(target, sib);
        }

        while(BinaryTree<DataType>::getChild(pos, sib) != nullptr){ 
            pos = BinaryTree<DataType>::getChild(pos, sib);    
        }
        
        node<DataType>* temp = BinaryTree<DataType>::getChild(pos, side); 
        
        if(temp != nullptr){
            BinaryTree<DataType>::setChild(pos->parent, temp, sib);
        }
        std::cout << pos->data << std::endl;

        return pos;
    }

    template <typename DataType> DataType BinarySearchTree<DataType>::remove(string position){
        node<DataType>* target = BinaryTree<DataType>::getParent(position, 't');
        node<DataType>* rplcNode = getXtrm(target, treeBias);
        
        BinaryTree<DataType>::setChild(target->parent, rplcNode, position.back());
        BinaryTree<DataType>::setChild(rplcNode, target->left, 'l');
        BinaryTree<DataType>::setChild(rplcNode, target->right, 'r');

        return target->data;
    }
    
    template <typename DataType> string BinarySearchTree<DataType>::search(DataType value){
        node<DataType>* pos = this->root;
        string path = "x";
        
        while(pos->data != value){
            if((pos->data > value && treeOrder == 'r') || (pos->data < value && treeOrder == 'l')){
                if(pos->left == nullptr){
                     return "-";
                }
                pos = pos->left;
                path = path + "l";
            }    
            else if((pos->data < value && treeOrder == 'r') || (pos->data > value && treeOrder == 'l')){
                if(pos->right == nullptr){
                     return "-";
                }
                pos = pos->right;    
                path = path + "r";
            }    
        }

        return path;
    }
}
