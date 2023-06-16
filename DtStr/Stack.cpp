#include <iostream>
using namespace std;

#include "Stack.h"

namespace dtstr{

    template class Stack<bool>;
    template class Stack<char>;
    template class Stack<int>;
    template class Stack<float>;
    template class Stack<double>;
    template class Stack<long>;

    template <typename DataType> Stack<DataType>::Stack(int size, DataType value, bool ver){
        length = size;
        verbose = ver;
        array = new Array<DataType>(size, value, ver=false);

        if(verbose){
            cout<<"dtstr >> Stack created"<<endl;
        }
    }

    template <typename DataType> void Stack<DataType>::push(DataType value){
        if(top < length){
            array->insert(top, value);
            top = top+1;
        }
        if(verbose){
            cout<<"dtstr >> Error: Stack OverFlow"<<endl;
        }
    }

    template <typename DataType> DataType Stack<DataType>::pop(){
        if(top > 0){
            top = top-1;
            return array->get(top);
        }
        if(verbose){
            cout<<"dtstr >> Error: Stack UnderFlow"<<endl;
        }
        return -1;
    }

    template <typename DataType> void Stack<DataType>::display(){  
        if(top != 0){
            cout<<"[";
            for(int indx=0; indx<top; indx++){
                cout<<array->get(indx)<<", ";
            }
            cout<<"\b\b]"<<endl;
            return;
        }
        if(verbose){
            cout<<"dtstr >> Stack is empty"<<endl;
        }
    }

    template <typename DataType> void Stack<DataType>::message(bool ver){
        
        verbose = ver;
    
    }

    template <typename DataType> bool Stack<DataType>::isEmpty(){
       
        if(top == 0){
            return true;
        }
        return false;
    
    }

    template <typename DataType> bool Stack<DataType>::isFull(){
       
        if(top == length){
            return true;
        }
        return false;
    
    }
    template <typename DataType> int Stack<DataType>::getLength(){
        return length;
    }

}