#include <iostream>
#include "dtstr.h"

int main(){
    // dtstr::Array<int> arr1(5, 1);

    // arr1.insert(4, 82);
    // arr1.insert(3, 10);
    // arr1.insert(2, 9);
    // arr1.insert(1, 7);
    // arr1.insert(0, 3);
    // arr1.display();
    // arr1.message(false);
    // arr1.reverse();
    // *arr1[0] = 88;
    // arr1.selectionSort('a');
    // arr1.display();

    // std::cout<<arr1[0];
    // std::cout<<arr1.linerSearch(100);
    // std::cout<<arr1.isSorted();
    // std::cout<<arr1.binarySearch(7);

    
    // dtstr::Stack<int> sta1(4, 1);
    // sta1.push(1);
    // sta1.push(2);
    // sta1.push(3);
    // sta1.pop();
    // sta1.pop();
    // sta1.pop();
    // sta1.pop();
    // sta1.display();

    // dtstr::DoubleEndedQueue<int> dque(5, 0);
    // dque.enqueue_r(19);
    // dque.enqueue_r(33);
    // dque.dequeue_r();
    // dque.display();

    // dtstr::CircularQueue<int> cque(5, 2);
    // cque.enqueue(1);
    // cque.enqueue(17);
    // cque.dequeue();
    // cque.dequeue();
    // cque.display();
    
    // dtstr::SinglyLinkedList<int> llist;
    // llist.insert(0, 6);
    // llist.insert(1, 8);
    // llist.insert(5, 2);
    // llist.insert(0, 5);
    // llist.remove(2);
    // dtstr::node_1<int>* ptr = new dtstr::node_1<int>(5);
    // dtstr::node_1<int> mynode(5);
    // dtstr::node1ptr<int> head;
    // dtstr::iterSL<int> head(llist.start);
    // head++;   
    // std::cout<<head->data; 
    // (*head).data;   

    // dtstr::CircularLinkedList<int> llist;
    // llist.insert(0, 5);
    // llist.insert(1, 4);
    // llist.insert(5, 7);
    // llist.insert(0, 9);
    // llist.insert(0, 3);
    // llist.insert(1, 0);

    dtstr::BinaryTree<int> btree;
    btree.insert(6);
    btree.insert(2, "xl");
    btree.insert(1, "xll");
    btree.insert(4, "xlr");
    btree.insert(3, "xlrl");
    btree.insert(5, "xlrr");
    btree.insert(8, "xr");
    btree.insert(7, "xrl");
    btree.insert(9, "xrr");

    std::cout<<"deleted: "<<btree.remove("xl", 'r')<<std::endl;



    btree.preOrder(btree.root);
    std::cout<<std::endl;
    btree.inOrder(btree.root);
    std::cout<<std::endl;
    btree.postOrder(btree.root);
    std::cout<<std::endl;

    
    return 0;
}