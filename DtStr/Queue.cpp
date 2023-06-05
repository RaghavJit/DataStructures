#include <iostream>
using namespace std;

#include "Queue.h"

namespace dtstr{
    Queue::Queue(int size, int value, bool ver){
        verbose = ver;
        length = size;
        head=0;
        tail=0;

        array = new Array(size, value, ver=false);

        if(verbose){
            cout<<"dtstr >> Queue created"<<endl; 
        }
    }

    void Queue::enqueue_r(int value){
        if(tail < length){
            array->insert(tail, value);
            tail = tail+1;
            return;
        }
        if(verbose){
            cout<<"dtstr >> Error: Queue OverFlow"<<endl;
        }
    }
    
    int Queue::dequeue_f(){
        if(head < tail){
            head = head+1;
            return array->get(head-1);
        }
        if(verbose){
            cout<<"dtstr >> Error: Queue UnderFlow"<<endl;
        }
        return -1;
    }

    void Queue::display(){
        if(head < tail){
            cout<<"[";
            for(int indx=head; indx<tail; indx++){
                cout<<array->get(indx)<<", ";
            }
            cout<<"\b\b]"<<endl;
            return;
        }
        if(verbose){
            cout<<"dtstr >> Queue is empty"<<endl;
        }
    }

    DoubleEndedQueue::DoubleEndedQueue(int size, int value, bool ver) : Queue (size, value, ver){
        verbose = ver;
        length = size;
        head=0;
        tail=0;

        array = new Array(size, value, ver=false);

        if(verbose){
            cout<<"dtstr >> Queue created"<<endl; 
        }
    }

    void DoubleEndedQueue::enqueue_f(int value){
        if(head > 0){
            head = head-1;
            array->insert(head, value);
            return;
        }
        if(verbose){
            cout<<"dtstr >> Error: Queue OverFlow"<<endl;
        }
    }

    int DoubleEndedQueue::dequeue_r(){
        if(head < tail){
            tail =  tail-1;
            return array->get(tail-1);
        }
        if(verbose){
            cout<<"dtstr >> Error: Queue UnderFlow"<<endl;
        }
        return -1;
    }
}