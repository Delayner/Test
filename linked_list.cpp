#include <iostream>
#include "linked_list.h"

struct LinkedList::Node {
    int value{};
    Node *next{};

    Node() = default;

    Node(int num) : value(num), next(nullptr) {}
};

void LinkedList::InsertBeg(int num) {
    Node *newNode = new Node(num);
    newNode->next = head;

    head = newNode;
}

void LinkedList::Insert(int num, int position) {
    if (position < 0) {
        return;
    }

    if (position == 0) {
        InsertBeg(num);
        return;
    }

    Node *newNode = new Node(num);

    Node *current = head;
    for (int i = 1; i < position - 1 && current != nullptr; ++i) {
        current = current->next;
    }

    if (current == nullptr) {
        InsertEnd(num);
    } else {
        newNode->next = current->next;
        current->next = newNode;
    }
}

void LinkedList::InsertEnd(int num) {
    Node *newNode = new Node(num);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
}

void LinkedList::DeleteBeg() {
    if (head == nullptr) {
        return;
    }

    Node *oldHead = head;
    head = head->next;

    delete oldHead;
}

void LinkedList::Delete(int position) {
    if (head == nullptr) {
        return;
    }

    if (position == 0) {
        DeleteBeg();
        return;
    }

    Node *pre = head;
    for (int i = 1; i < position - 1 && pre != nullptr; ++i) {
        pre = pre->next;
    }

    if (pre == nullptr) {
        DeleteEnd();
    } else {
        Node *toDelete = pre->next;
        pre->next = pre->next->next;
        delete toDelete;
    }
}

void LinkedList::DeleteEnd() {
    if (head == nullptr) {
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node *current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
}

void LinkedList::Merge(const LinkedList &other) {
    if (this->head == nullptr || other.head == nullptr) {
        return;
    }

    Node *current = this->head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = other.head;
}

int LinkedList::Search(int element) {
    int position = 0;
    Node *current = head;

    while (current != nullptr) {
        if (current->value == element) {
            return position;
        }

        current = current->next;
        position++;
    }

    return -1;
}

void LinkedList::Output() {

    Node *current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}