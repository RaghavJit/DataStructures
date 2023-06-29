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

    template class iterSL<bool>;
    template class iterSL<char>;
    template class iterSL<int>;
    template class iterSL<float>;
    template class iterSL<double>;
    template class iterSL<long>;

    template <typename DataType> iterSL<DataType>::iterSL(node_1<DataType>* node){
        nodeptr = node;
    }

    template <typename DataType> iterSL<DataType> iterSL<DataType>::operator++(int){
        nodeptr = nodeptr->next;
        return *this;
    }

    template <typename DataType> node_1<DataType>* iterSL<DataType>::operator->(){
        return nodeptr;
    }
    
    template <typename DataType> node_1<DataType> iterSL<DataType>::operator*(){
        return *nodeptr;
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

    template class iterDL<bool>;
    template class iterDL<char>;
    template class iterDL<int>;
    template class iterDL<float>;
    template class iterDL<double>;
    template class iterDL<long>;

    template <typename DataType> iterDL<DataType>::iterDL(node_2<DataType>* node){
        nodeptr = node;
    }

    template <typename DataType> iterDL<DataType> iterDL<DataType>::operator++(int){
        nodeptr = nodeptr->next;
        return *this;
    }

    template <typename DataType> iterDL<DataType> iterDL<DataType>::operator--(int){
        nodeptr = nodeptr->prev;
        return *this;
    }

    template <typename DataType> node_2<DataType>* iterDL<DataType>::operator->(){
        return nodeptr;
    }
    
    template <typename DataType> node_2<DataType> iterDL<DataType>::operator*(){
        return *nodeptr;
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
            cout<<"Linked List created"<<endl;
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

    template <typename DataType> void SinglyLinkedList<DataType>::replace(int index, DataType value){
        node_1<DataType>* iter = start;
        for(int indx = 0; indx < index; iter=iter->next, indx++){}
        iter->data = value;
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

    template <typename DataType> void SinglyLinkedList<DataType>::message(bool ver){
        verbose = ver;
    }

    template <typename DataType> bool SinglyLinkedList<DataType>::isEmpty(){
        if(length == 0){
            return true;
        }
        return false;
    }

    template <typename DataType> DataType* SinglyLinkedList<DataType>::operator[](int index){
        node_1<DataType>* iter = start;
        for(int indx=0; indx < index; iter=iter->next, indx++){}
        DataType* temp = &(iter->data);
        return temp;
    }

    template class DoubleLinkedList<bool>;
    template class DoubleLinkedList<char>;
    template class DoubleLinkedList<int>;
    template class DoubleLinkedList<float>;
    template class DoubleLinkedList<double>;
    template class DoubleLinkedList<long>;

    template <typename DataType> DoubleLinkedList<DataType>::DoubleLinkedList(bool ver){
        verbose = ver;
        start = nullptr;
        end = nullptr;
        length = 0;

        if(verbose){
            cout<<"Linked List created"<<endl;
        }
    }

    template <typename DataType> void DoubleLinkedList<DataType>::insert(int index, DataType value){

        node_2<DataType>* newNode = new node_2(value);

        if(index==0 || index==length){
            if(index == 0){
                newNode->next = start;
                start = newNode;
                if(start->next != nullptr){ // reverse linking if list not empty
                (start->next)->prev = start;
                }
            }
            if(index == length){
                newNode->prev = end;
                end = newNode;
                if(end->prev != nullptr){ // forward linking if list not empty
                    (end->prev)->next = end;
                }
            }
            length++;
        }
        else if((index < length) && (index > 0)){

            node_2<DataType>* iter = start;

            for(int indx=0; indx < index-1; iter=iter->next, indx++){}

            newNode->next = iter->next; //forward linking
            (iter->next)->prev = newNode; //reverse linking

            iter->next = newNode;
            newNode->prev = iter;

            length++;
        }
        else if(verbose){
            cout<<"dtstr >> Error: Invalid Index"<<endl;
        }
    }

    template <typename DataType> void DoubleLinkedList<DataType>::replace(int index, DataType value){
        node_2<DataType>* iter = start;
        for(int indx = 0; indx < index; iter=iter->next, indx++){}
        iter->data = value;
    }

    template <typename DataType> DataType DoubleLinkedList<DataType>::get(int index){

        node_2<DataType>* iter = start;

        if(length == 0){
            if(verbose){
                cout<<"dtstr >> List is empty"<<endl;
            }
            return (DataType)-1;
        }

        for(int indx=0; indx < index; iter=iter->next, indx++){}

        return (iter->data);
    }

    template <typename DataType> void DoubleLinkedList<DataType>::display(){
        
        if(length != 0){
            cout<<"[";
            node_2<DataType>* iter = start;

            for(int indx = 0; indx < length; iter=iter->next, indx++){
                cout<<(iter->data)<<", ";
            }
            cout<<"\b\b]"<<endl;
            return;
        }
        if(verbose){
            cout<<"dtstr >> List is empty"<<endl;
        }

    }

    template <typename DataType> void DoubleLinkedList<DataType>::reverse(){
        
        node_2<DataType>* temp = start;
        start = end;
        end = temp;

    }

    template <typename DataType> DataType DoubleLinkedList<DataType>::remove(int index){

        node_2<DataType>* iter = start;
        DataType result;

        if(length == 0){
            if(verbose){
                cout<<"dtstr >> List is empty"<<endl;
            }
            return (DataType)-1;
        }
        
        if(index == 0){
            result = start->data;
            start = start->next;
            delete start->prev;
            return result;
        }

        for(int indx = 0; indx < index-1; iter=iter->next, indx++){}
        
        result = iter->next->data;
        iter->next = iter->next->next;
        (iter->next->next)->prev->prev = iter;
        return result;
    }

    template <typename DataType> void DoubleLinkedList<DataType>::message(bool ver){
        verbose = ver;
    }

    template <typename DataType> bool DoubleLinkedList<DataType>::isEmpty(){
        if(length == 0){
            return true;
        }
        return false;
    }

    template <typename DataType> DataType* DoubleLinkedList<DataType>::operator[](int index){
        node_2<DataType>* iter = start;
        for(int indx=0; indx < index; iter=iter->next, indx++){}
        DataType* temp = &(iter->data);
        return temp;
    }

    template class CircularLinkedList<bool>;
    template class CircularLinkedList<char>;
    template class CircularLinkedList<int>;
    template class CircularLinkedList<float>;
    template class CircularLinkedList<double>;
    template class CircularLinkedList<long>;    

    template <typename DataType> CircularLinkedList<DataType>::CircularLinkedList(bool ver) : DoubleLinkedList<DataType>(ver){}

    template <typename DataType> void CircularLinkedList<DataType>::insert(int index, DataType value){
        
        node_2<DataType>* newNode = new node_2<DataType>(value);

        if(DoubleLinkedList<DataType>::length == 0 || index%DoubleLinkedList<DataType>::length == 0){

            if(DoubleLinkedList<DataType>::length == 0){
                DoubleLinkedList<DataType>::start = newNode;
                newNode->next = newNode;
                newNode->prev = newNode;
            }

            if(DoubleLinkedList<DataType>::length != 0 && index%DoubleLinkedList<DataType>::length == 0){
                newNode->next = DoubleLinkedList<DataType>::start;
                (DoubleLinkedList<DataType>::start->prev)->next = newNode;   
                newNode->prev = DoubleLinkedList<DataType>::start->prev;
                DoubleLinkedList<DataType>::start->prev = newNode;

                if(index == 0){
                    DoubleLinkedList<DataType>::start = newNode;
                }

            }

            DoubleLinkedList<DataType>::length++;

            return;
        }

        node_2<DataType>* iter = DoubleLinkedList<DataType>::start;

        for(int indx=0; indx < (index%DoubleLinkedList<DataType>::length)-1; iter=iter->next, indx++){}

        newNode->next = iter->next; //forward linking
        (iter->next)->prev = newNode; //reverse linking

        iter->next = newNode;
        newNode->prev = iter;

        DoubleLinkedList<DataType>::length++;
    }
}