#include <iostream>
using namespace std;

#include "Array.h"

namespace dtstr{

    template class Array<bool>;
    template class Array<char>;
    template class Array<int>;
    template class Array<float>;
    template class Array<double>;
    template class Array<long>;

    template <typename DataType> Array<DataType>::Array(int size, DataType value, bool ver){
        verbose = ver;
        length = size;
        ptr = (DataType*)malloc(length*sizeof(DataType));

        for(DataType* temp=ptr; temp<(ptr+length); temp++){
            (*temp) = value; 
        }

        if(verbose){
            cout<<"dtstr >> Array created!"<<endl;
        }
    }

    template <typename DataType> void Array<DataType>::insert(int index, DataType value){
        if((index < length) && (index >= 0)){
            DataType* temp = ptr + index;
            (*temp) = value;
            return;
        }
        if(verbose){
            cout<<"dtstr >> Error: Invalid Index"<<endl;
        }
    }

    template <typename DataType> DataType Array<DataType>::get(int index){
        if((index < length) && (index >= 0)){
            DataType* temp = ptr + index;
            return (*temp);
        }
        if(verbose){
            cout<<"dtstr >> Error: Invalid Index"<<endl;
        }
        return -1;
    }

    template <typename DataType> void Array<DataType>::display(){
        if(length != 0){
            cout<<"[";
            for(DataType* temp=ptr; temp<(ptr+length); temp++){
                cout<<(*temp)<<", ";
            }
            cout<<"\b\b]"<<endl;
            return;
        }
        if(verbose){
            cout<<"dtstr >> Array is empty"<<endl;
        }
    }
    
}