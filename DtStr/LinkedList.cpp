#include <iostream>
using namespace std;

#include "LinkedList.h"

namespace dtstr{
    
    template class node_1<bool>;
    template class node_1<char>;
    template class node_1<int>;
    template class node_1<float>;
    template class node_1<double>;
    template class node_1<long>;

    template <typename DataType> node_1<DataType>::node_1(DataType value){
        data = value;
        next = nullptr;
    }

    template class node_2<bool>;
    template class node_2<char>;
    template class node_2<int>;
    template class node_2<float>;
    template class node_2<double>;
    template class node_2<long>;

    template <typename DataType> node_2<DataType>::node_2(DataType value, node_2* pre){
        data = value;
        next = nullptr;
        prev = pre;
    }

    template class SinglyLinkedList<bool>;
    template class SinglyLinkedList<char>;
    template class SinglyLinkedList<int>;
    template class SinglyLinkedList<float>;
    template class SinglyLinkedList<double>;
    template class SinglyLinkedList<long>;

    template <typename DataType> SinglyLinkedList<DataType>::SinglyLinkedList(bool ver){
        verbose = ver;
        start = nullptr;
        length = 0;

        if(verbose){
            cout<<"Singly Linked List created"<<endl;
        }
    }

    template <typename DataType> void SinglyLinkedList<DataType>::insert(int index, DataType value){
        
        node_1<DataType>* newNode = new node_1(value);

        if(index == 0){
            newNode->next = start;
            start = newNode;
            length++;
        }
        else if((index <= length) && (index > 0)){
            node_1<DataType>* iter = start;

            for(int indx=0; indx < index-1; iter=iter->next, indx++){}

            newNode->next = iter->next;
            iter->next = newNode;
            length++;
        }
        else if(verbose){
            cout<<"dtstr >> Error: Invalid Index"<<endl;
        }
    }

    template <typename DataType> DataType SinglyLinkedList<DataType>::get(int index){

        node_1<DataType>* iter = start;

        if(length == 0){
            if(verbose){
                cout<<"dtstr >> List is empty"<<endl;
            }
            return (DataType)-1;
        }

        for(int indx=0; indx < index; iter=iter->next, indx++){}

        return (iter->data);
    }

    template <typename DataType> DataType SinglyLinkedList<DataType>::remove(int index){
        
        DataType temp;

        if(length == 0){
            if(verbose){
                cout<<"dtstr >> List is empty"<<endl;
            }
            return (DataType)-1;
        }

        if((index == 0)){
            temp = (start->data);
            start = start->next;
            length--;
            return temp;
        }
        else if((index <= length) && (index > 0)){
            node_1<DataType>* iter = start;

            for(int indx=0; indx < index-2; iter=iter->next, indx++){}
            temp = ((iter->next)->data);
            iter->next = (iter->next)->next;
            length--;
            return temp;
        }
        else if(verbose){
            cout<<"dtstr >> Error: Invalid Index"<<endl;
        }
        return (DataType)-1;
    }

    template <typename DataType> void SinglyLinkedList<DataType>::display(){
        
        if(length != 0){
            cout<<"[";
            for(node_1<DataType>* iter = start; iter != nullptr; iter=iter->next){
                cout<<(iter->data)<<", ";
            }
            cout<<"\b\b]"<<endl;
            return;
        }
        if(verbose){
            cout<<"dtstr >> List is empty"<<endl;
        }
    }


}