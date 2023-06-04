#include <iostream>
using namespace std;

#include "Array.h"

namespace dtstr{

    Array::Array(int size, int value){
        length = size;
        ptr = (int*)malloc(length*sizeof(int));

        for(int* temp=ptr; temp<(ptr+length); temp++){
            (*temp) = value; 
        }

        cout<<"dtstr >> Array created!"<<endl;
    }

    void Array::insert(int index, int value){

        if((index > length) || (index < 0)){
            cout<<"dtstr >> Error: Invalid Index"<<endl;
            return;
        }

        int* temp = ptr + index;
        (*temp) = value;
    
    }

    void Array::display(){
        if(length == 0){
            return;
        }
        
        cout<<"[";
        for(int* temp=ptr; temp<(ptr+length); temp++){
            cout<<(*temp)<<", ";
        }
        cout<<"\b\b]"<<endl;
    }
    
}