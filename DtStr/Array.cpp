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

    template <typename DataType> void Array<DataType>::bubbleSort(char arng){        
        
        if((arng == 'n' || arng == 'e') && verbose){
            cout<<"dtstr >> Invalid sorting flag "<<arng<<" was given"<<endl;
            return;
        }

        int swaps;
        do{
            swaps=0;
            for(DataType* iter = ptr; iter < (ptr+length-1); iter++){
                if((*iter > *(iter+1) && arng == 'a') || (*iter < *(iter+1) && arng == 'd')){
                    DataType temp = *iter;
                    *iter = *(iter+1);
                    *(iter+1) = temp;

                    swaps = swaps+1;
                }
            }
        }while(swaps != 0);
    }

    template <typename DataType> void Array<DataType>::insertionSort(char arng){

        if((arng == 'n' || arng == 'e') && verbose){
            cout<<"dtstr >> Invalid sorting flag "<<arng<<" was given"<<endl;
            return;
        }

        for(DataType* limit = ptr+1; limit <= (ptr+length-1); limit++){
            for(DataType* iter = limit; iter > ptr; iter--){
                
                if((*iter > *(iter-1) && (arng == 'd')) || (*iter < *(iter-1) && (arng == 'a'))){
                    DataType temp = *iter;
                    *iter = *(iter-1);
                    *(iter-1) = temp;
                }

            }
        }
    }

    template <typename DataType> void Array<DataType>::selectionSort(char arng){
        
        if((arng == 'n' || arng == 'e') && verbose){
            cout<<"dtstr >> Invalid sorting flag "<<arng<<" was given"<<endl;
            return;
        }

        for(DataType* limit = ptr; limit <= (ptr+length-1); limit++){
            DataType* largest = limit;
            for(DataType* iter = limit+1; iter <= (ptr+length-1); iter++){

                if((*largest < *iter && arng == 'd') || (*largest > *iter && arng == 'a')){
                    largest = iter;
                }
            }
            DataType temp = *largest;
            *largest = *limit;
            *limit = temp;
        }
    }

    template <typename DataType> int Array<DataType>::linerSearch(DataType value){
        for(DataType* iter = ptr; iter < (ptr + length); iter++){
            if(*iter == value){
                return (iter-ptr);
            }
        }
        return 
        -1;
    }

    template <typename DataType> int Array<DataType>::binarySearch(DataType value){
        
        int start = 0;
        int end = length-1;
        int mid;

        char arng = this->isSorted();

        if((arng == 'n' || arng == 'e') && verbose){
            cout<<"dtstr >> Array can't be searched"<<endl;
            return -1;
        }

        while(start <= end){
            
            mid = (start + end)/2;
            DataType center = this->get(mid);

            if(center == value){
                return mid;
            }
            else if(center > value){
                if(arng == 'a'){
                    end = mid-1; //asc
                }
                else if(arng == 'd'){
                    start = mid+1; //des
                }
            }
            else if(center < value){
                if(arng == 'a'){
                    start = mid+1; //asc
                }
                else if(arng == 'd'){
                end = mid-1; //des
                }
            }
        }

        return -1;
    }

    template <typename DataType> void Array<DataType>::reverse(){
                
        DataType* start = ptr;
        DataType* end = ptr+length-1;
        
        for(int indx=0; indx<length/2; indx++){

            DataType temp = *start;
            *start = *end;
            *end =  temp;

            start++;
            end--;
        }
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

    template <typename DataType> int Array<DataType>::getLength(){   
        return length;
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

    template <typename DataType> DataType* Array<DataType>::operator[](int index){
        if((index < 0) && (index >= length)){
           cout<<"dtstr >> Invalid Index"<<endl;
            return nullptr; 
        }   
        return (ptr+index);
    }
}       