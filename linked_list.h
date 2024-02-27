
#ifndef TRE_DEV_LINKED_LIST_H
#define TRE_DEV_LINKED_LIST_H

#include <iostream>

class LinkedList {
public:
    LinkedList() = default;

    void InsertBeg(int num);

    void Insert(int num, int position);

    void InsertEnd(int num);

    void DeleteBeg();

    void Delete(int position);

    void DeleteEnd();

    void Merge(const LinkedList& other);

    int Search(int element);

    void Output();

private:
    struct Node;
    Node* head{};
};

#endif //TRE_DEV_LINKED_LIST_H
