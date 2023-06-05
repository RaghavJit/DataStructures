#include <iostream>
using namespace std;

#include "Array.h"

namespace dtstr{

    Array::Array(int size, int value, bool ver){
        verbose = ver;
        length = size;
        ptr = (int*)malloc(length*sizeof(int));

        for(int* temp=ptr; temp<(ptr+length); temp++){
            (*temp) = value; 
        }

        if(verbose){
            cout<<"dtstr >> Array created!"<<endl;
        }
    }

    void Array::insert(int index, int value){
        if((index < length) && (index >= 0)){
            int* temp = ptr + index;
            (*temp) = value;
            return;
        }
        if(verbose){
            cout<<"dtstr >> Error: Invalid Index"<<endl;
        }
    }

    int Array::get(int index){
        if((index < length) && (index >= 0)){
            int* temp = ptr + index;
            return (*temp);
        }
        if(verbose){
            cout<<"dtstr >> Error: Invalid Index"<<endl;
        }
        return -1;
    }

    void Array::display(){
        if(length != 0){
            cout<<"[";
            for(int* temp=ptr; temp<(ptr+length); temp++){
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