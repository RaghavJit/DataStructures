#include <iostream>
using namespace std;

#include "Stack.h"

namespace dtstr{

    Stack::Stack(int size, int value, bool ver){
        length = size;
        verbose = ver;
        array = new Array(size, value, ver=false);

        if(verbose){
            cout<<"dtstr >> Stack created"<<endl;
        }
    }

    void Stack::push(int value){
        if(top < length){
            array->insert(top, value);
            top = top+1;
        }
        if(verbose){
            cout<<"dtstr >> Error: Stack OverFlow"<<endl;
        }
    }

    int Stack::pop(){
        if(top > 0){
            top = top-1;
            return array->get(top);
        }
        if(verbose){
            cout<<"dtstr >> Error: Stack UnderFlow"<<endl;
        }
        return -1;
    }

    void Stack::display(){  
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

}