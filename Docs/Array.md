# Array

Template class for array data structure.

Avalible data types for Array:
1. bool
1. char
1. int
1. float
1. long
1. double

---------------------------------------------------
Function | Arguments | Return Value | Description |
---------|-----------|--------------|-------------|
Array |int size, DataType value, bool ver | - | Constructor for Stack takes, size of array, default value (to populate the array with) and verbose (to turn on/off errors and messages)
insert | int index, DataType value | void | inserts the given value on the specified index
get | int index | DataType | returns the value at specified index
display | - | void | prints the array to console
linearSearch | DataType value | int | returns the index of the specified value (impliments linera search)
binarySearch* | DataType value | int | returns the index of the specified value usig binary search
message | bool ver | void | takes bool value as argument and sets verbose equal to it.
isSorted | - | char | returns 'a' if array is sorted in ascending order, 'd' for descending, 'n' for not sorted and 'e' if all elements are equal
bubbleSort* | char arng | void | sorts the array using [bubble sort](https://www.geeksforgeeks.org/bubble-sort/) according to the given flag ('a' for ascending and 'd' for descending)
insertionSort* | char arng | void | sorts the array using [insertion sort](https://www.geeksforgeeks.org/insertion-sort/) ('a' for ascending and 'd' for descending)
selectionSort* | char arng | void | sorts the array using [selection sort](https://www.geeksforgeeks.org/selection-sort/) ('a' for ascending and 'd' for descending)

Features with * are yet to be implimented 

## Usage

### Indexing
Array values can be acessed using **[]** operator. Using [] with object of Array class will return a pointer pointing to the location of specified index.
```
arr[0]; // is a pointer to first element of the array 'arr'
*arr[0]; // will return the value stored at the index '0'
```
### Iterating
A simple way to iterate through all the values of arr.
```
for(int i=0; i<arr.getLength(); i++){
    cout<<*arr[i];
}
```
### Assingment
During assingment the type of data that is being assinged must be compaitable with Array object.
```
*arr[0] = 3; // will set the value of first element or arr equal to 3
```