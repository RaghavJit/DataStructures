#include <iostream>
using namespace std;

#include "Queue.h"

namespace dtstr{

    template class Queue<bool>;
    template class Queue<char>;
    template class Queue<int>;
    template class Queue<float>;
    template class Queue<double>;
    template class Queue<long>;

    template <typename DataType> Queue<DataType>::Queue(int size, DataType value, bool ver){
        verbose = ver;
        length = size;
        head=0;
        tail=0;

        array = new Array<DataType>(size, value, ver=false);

        if(verbose){
            cout<<"dtstr >> Queue created"<<endl; 
        }
    }

    template <typename DataType> void Queue<DataType>::enqueue_r(DataType value){
        if(tail < length){
            array->insert(tail, value);
            tail = tail+1;
            return;
        }
        if(verbose){
            cout<<"dtstr >> Error: Queue OverFlow"<<endl;
        }
    }
    
    template <typename DataType> DataType Queue<DataType>::dequeue_f(){
        if(head < tail){
            head = head+1;
            return array->get(head-1);
        }
        if(verbose){
            cout<<"dtstr >> Error: Queue UnderFlow"<<endl;
        }
        return -1;
    }

    template <typename DataType> void Queue<DataType>::display(){
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

    template class DoubleEndedQueue<bool>;
    template class DoubleEndedQueue<char>;
    template class DoubleEndedQueue<int>;
    template class DoubleEndedQueue<float>;
    template class DoubleEndedQueue<double>;
    template class DoubleEndedQueue<long>;

    template <typename DataType> DoubleEndedQueue<DataType>::DoubleEndedQueue(int size, DataType value, bool ver) : Queue<DataType>(size, value, ver){}

    template <typename DataType> void DoubleEndedQueue<DataType>::enqueue_f(DataType value){

        if(Queue<DataType>::head > 0){
            Queue<DataType>::head = Queue<DataType>::head-1;
            Queue<DataType>::array->insert(Queue<DataType>::head, value);
            return;
        }
        if(Queue<DataType>::verbose){
            cout<<"dtstr >> Error: Queue OverFlow"<<endl;
        }
    }

    template <typename DataType> DataType DoubleEndedQueue<DataType>::dequeue_r(){
        
        if(Queue<DataType>::head < Queue<DataType>::tail){
            Queue<DataType>::tail =  Queue<DataType>::tail-1;
            return Queue<DataType>::array->get(Queue<DataType>::tail-1);
        }
        if(Queue<DataType>::verbose){
            cout<<"dtstr >> Error: Queue UnderFlow"<<endl;
        }
        return -1;
    }

    template class CircularQueue<bool>;
    template class CircularQueue<char>;
    template class CircularQueue<int>;
    template class CircularQueue<float>;
    template class CircularQueue<double>;
    template class CircularQueue<long>;

    template <typename DataType> CircularQueue<DataType>::CircularQueue(int size, DataType value, bool ver){
        length = size;
        head=0;
        tail=0;
        verbose = ver;

        array = new Array<DataType>(size, value, ver=false);

        if(verbose){
            cout<<"dtstr >> Queue is created"<<endl;
        }
    }

    template <typename DataType> void CircularQueue<DataType>::enqueue(DataType value){
        if(head >= tail){
            array->insert(tail, value);
            tail = (tail+1)%length;
        }
    }

    template <typename DataType> DataType CircularQueue<DataType>::dequeue(){
        if(head > tail){
            head = (head+1)%length;
            return array->get(head-1);
        }
        if(verbose){
            cout<<"dtstr >> Error: Queue UnderFlow"<<endl;
        }
        return -1;
    }

    template <typename DataType> void CircularQueue<DataType>::display(){
        if(head != tail){
            cout<<"[";
            for(int indx=head; indx!=tail; indx=(indx+1)%length){
                cout<<array->get(indx)<<", ";
            }
            cout<<"\b\b]"<<endl;
            return;
        }
        if(verbose){
            cout<<"dtstr >> Queue is empty"<<endl;  
        }
    }
}