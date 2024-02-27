#include <iostream>
#include "linked_list.h"

int main() {
    LinkedList list1;
    LinkedList list2;

    list1.InsertBeg(2);
    list1.InsertBeg(7);
    list1.InsertBeg(8);
    list1.InsertBeg(9);
    list1.Insert(3, 1);
    list1.InsertEnd(4);


    list2.InsertBeg(5);
    list2.Insert(6, 2);
    list2.InsertEnd(7);
    list2.Delete(3);

    list1.Merge(list2);

    list1.Output();


}








