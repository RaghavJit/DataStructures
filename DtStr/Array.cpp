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
            for(DataType* iter=ptr; iter<(ptr+length); iter++){
                cout<<(*iter)<<", ";
            }
            cout<<"\b\b]"<<endl;
            return;
        }
        if(verbose){
            cout<<"dtstr >> Array is empty"<<endl;
        }
    }

    template <typename DataType> DataType Array<DataType>::linerSearch(DataType value){
        for(DataType* iter = ptr; iter < (ptr + length); iter++){
            if(*iter == value){
                return (iter-ptr);
            }
        }
        return (DataType)-1;
    }
    
    template <typename DataType> void Array<DataType>::message(bool ver){
        verbose = ver;
    }

    template <typename DataType> char Array<DataType>::check(int indx, char arng){
        for(int iter = indx; iter < length-1; iter++){
            if((*(ptr+iter) > *(ptr+iter+1)) && (arng == 'a')){
                return 'n';
            }
            else if((*(ptr+iter) < *(ptr+iter+1)) && (arng == 'd')){
                return 'n';
            }
        }
        return arng;
    }

    template <typename DataType> char Array<DataType>::isSorted(){   
        
        for(int indx = 0; indx < length-1; indx++){
            if(*(ptr+indx) < *(ptr+indx+1)){
                return check(indx, 'a');
            }
            else if(*(ptr+indx) > *(ptr+indx+1)){
                return check(indx, 'd');
            }
        }
        return 'e';
    }
}       