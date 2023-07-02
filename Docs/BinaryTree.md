# BinaryTree

Template classes for binary tree and alike data structures. Binary search tree and Heap are derived from the BinaryTree template class. BinaryTree.h has the following classes.
1. [BinaryTree]()
1. [BinarySearchTree]() 
1. [Heap]()

Avalible data types for Array:
1. bool
1. char
1. int
1. float
1. long
1. double

## BinaryTree

---------------------------------------------------
Function | Arguments | Return Value | Description |
---------|-----------|--------------|-------------|
BinaryTree | bool verbose | - | default constructor for BinaryTree class initialzes a empty binary tree with a node pointer
insert | DataType value, string position, char child | void | inserts the given data at the specifed position in tree. Position string "xlr" will insert node at root->left->right position (default position is root). Child character specifies where the child of target will attach if exists, child 'l' will append child of "xlr" to left of new node (default is left).
remove | string position | DataType | removes the node at given position
replace | string position, DataType vale | DataType | replaces the node at given position with specified data
remove | string position | DataType | gets the data at the specified node
preOrder | node* | void | takes a root node as parameter and prints [pre-order]() treversal of the tree to console, reletive to root node.
inOrder | node* | void | takes a root node as parameter and prints [in-order]() treversal of the tree to console, reletive to root node.
postOrder | node* | void | takes a root node as parameter and prints [post-order]() treversal of the tree to console, reletive to root node.
---------------------------------------------------


