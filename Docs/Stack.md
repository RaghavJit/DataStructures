# Stack 

Template class for [stack](https://www.javatpoint.com/data-structure-stack) data structure.

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