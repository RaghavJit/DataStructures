# Stack 

Template class for [stack](https://www.javatpoint.com/data-structure-stack) data structure. Template class of Stack uses an object pointer of 'Array' class along with control functions to impliment stack data structure.

Types of Stack template classes:
1. Stack (implimented using array)
1. LinkedListStack (implimented using linked list)

Avalible data types for Stack:
1. bool
1. char
1. int
1. float
1. long
1. double

---------------------------------------------------
Function | Arguments | Return Value | Description |
---------|-----------|--------------|-------------|
Stack | int size, DataType value, bool ver | - | Constructor for Stack takes, size of stack, default value (to populate the stack with) and verbose (to turn on/off errors and messages)
push | int value | void | pushes a value at the top of stack
pop | - | DataType | pops and returns a element on the top of stack
display | - | void | prints the Stack to the console
message | bool ver | void | takes bool value as argument and sets verbose equal to it.
getLength | - | int | returns the length of Stack
isEmpty | - | bool | returns true if Stack is empty otherwise false
isFull | - | bool | returns true if Stack if full otherwise false

Features with * are yet to be implimented
