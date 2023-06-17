# Queue

Queue template class is impliment using Array template class, and control functions mentioned below. Queue.h has template classes for the following data structures:
1. [Queue](https://www.javatpoint.com/data-structure-queue)
1. DoubleEndedQueue
1. CircularQueue

Avalible data types for Queue:
1. bool
1. char
1. int
1. float
1. long
1. double


## Queue

Is the basic queue with enqueue and dequeue functions:

---------------------------------------------------
Function | Arguments | Return Value | Description |
---------|-----------|--------------|-------------|
Queue  | int size, DataType value, bool ver | - | Is the default constructor for Queue tempalte class. Takes size of Queue, default value (to populate the Queue with) and verbose (to turn on/off errors and messages).
enqueue_r | DataType value | void | enqueue a value of 'DataType' in the rear of queue
dequeue_f | - | DataType | removes and returns the element in the front of the queue
display | - | void | prints the Queue to the console
message | bool ver | void | takes bool value as argument and sets verbose equal to it.
getLength | - | int | returns the length of Queue
isEmpty | - | bool | returns true if Queue is empty otherwise false
isFull | - | bool | returns true if Queue if full otherwise false
---------------------------------------------------


## DoubleEndedQueue

Derived from Queue is template class for double ended queue. enqueue and dequeue operations can be performed on both front and end of this queue. All the functions of Queue class can be used in DoubleEndedQueue

---------------------------------------------------
Function | Arguments | Return Value | Description |
---------|-----------|--------------|-------------|
enqueue_f | DataType value | void | enqueue a value of 'DataType' in the front of queue
dequeue_r | - | DataType | removes and returns the element in the rear of the queue
---------------------------------------------------


## CircularQueue

Overcomes the short comings of queue datastructure, NOT derived from any base class.

---------------------------------------------------
Function | Arguments | Return Value | Description |
---------|-----------|--------------|-------------|
CiruclarQueue  | int size, DataType value, bool ver | - | Is the default constructor for Queue tempalte class. Takes size of Queue, default value (to populate the Queue with) and verbose (to turn on/off errors and messages).
enqueue | DataType value | void | enqueue a value of 'DataType' at tail position
dequeue | - | DataType | removes and returns the element at head position
display | - | void | prints the Queue to the console
message | bool ver | void | takes bool value as argument and sets verbose equal to it.
isEmpty | - | bool | returns true if Queue is empty otherwise false
---------------------------------------------------

