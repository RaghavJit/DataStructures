# LinkedList

Template Classes for different types of [linked lists](https://www.geeksforgeeks.org/data-structures/linked-list/).

Avalible data types for LinkedList:
1. bool
1. char
1. int
1. float
1. long
1. double

## SinglyLinkedList

Is template class for simple singly linked list which makes use of node_1 type of nodes (node_1 have only foward linking)

---------------------------------------------------
Function | Arguments | Return Value | Description |
---------|-----------|--------------|-------------|
SinglyLinkedList | bool ver | - | Initializes a singly linked list with a null pointer
insert | int index, DataType value | void | inserts a node_1 object with 'data'=value at specifed index in list
get | int index | DataType | returns data stored at node with specified index in list 
remove | int index | DataType | removes a node form the list and returns the data of removed node
display | - | void | print data of all the nodes in linked list to the console in cronological order

## DoubleLinkedList

Is template class for simple double linked list which makes use of node_2 type of nodes (node_2 have both foward and reverse linking)

---------------------------------------------------
Function | Arguments | Return Value | Description |
---------|-----------|--------------|-------------|
DoubleLinkedList | bool ver | - | Initializes a double linked list with a null pointer
insert | int index, DataType value | void | inserts a node_2 object with 'data'=value at specifed index in list
get | int index | DataType | returns data stored at node with specified index in list 
remove | int index | DataType | removes a node form the list and returns the data of removed node
display | - | void | print data of all the nodes in linked list to the console in cronological order

