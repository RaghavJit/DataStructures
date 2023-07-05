# LinkedList

Template Classes for different types of [linked lists](https://www.geeksforgeeks.org/data-structures/linked-list/).

Avalible data types for LinkedList:enhancement
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
insert | int index, DataType value | void | inserts a **new** node_1 object with 'data'=value at specifed index in list
replace | int index, DataType value | void | over-wirtes the value of node at specified index
get | int index | DataType | returns data stored at node with specified index in list 
remove | int index | DataType | removes a node form the list and returns the data of removed node
display | - | void | print data of all the nodes in linked list to the console in cronological order
message | bool ver | void | takes bool value as argument and sets verbose equal to it.
isEmpty | - | bool | returns true if list is empty otherwise false
---------------------------------------------------

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
message | bool ver | void | takes bool value as argument and sets verbose equal to it.
isEmpty | - | bool | returns true if list is empty otherwise false
---------------------------------------------------

## CircularLinkedList 
Is a implimentation of ciruclar double linked list, and is derived from DoubleLinkedList class. All the functions of DoubleLinkedList can be used in CirularLinkedList.
### Indexing
Nodes of linked list can be access by their index using **[]** operator. Using this pointer on linked list will return a pointer to the value stored at the index in linked list.
```
dtstr::SinglyLinkedList llist[0] // return pointer to 'data' of first node in linked list
```

### Iterating
To iterate the linked list respective type of iterator object can be used. To iterate singly linked list and double linked list **'iterSL'** and **'iterDL'** is used respectivly. 
```
dtstr::iterSL<DataType> head(llist.start); // constructor of iterSL 
```
The 'DataType' of iter must match the 'DataType' of linked list

```
head++; // incriments the iter to next node 
head--; // decriment the iter to next node but only in iterDL

head->data // data stored at iter can be accessed using -> pointer
```

### Assingment
```
*head // iter can be used to derefrenced, to access the node it's pointing to
```