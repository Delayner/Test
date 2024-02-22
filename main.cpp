#include <iostream>


class LinkedList {
private:
    struct Node {
        int value{};
        Node *next{};

        Node() = default;
        Node(int num) : value(num), next(nullptr) {}
    };
public:
    LinkedList() = default;

    void InsertAtBeg(int num) {
        Node* newNode = new Node(num);
        newNode->next = head;

        head = newNode;
    }

    void InsertAtPos(int position, int num) {
        if(position < 0) {
            return;
        }

        if(position == 0) {
            InsertAtBeg(num);
            return;
        }

        Node* newNode = new Node(num);

        Node* current = head;
        for(int i = 0; i < position - 1 && current != nullptr; ++i) {
            current = current->next;
        }

        if(current == nullptr) {
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void InsertAtEnd(int num) {
        Node* newNode = new Node(num);

        if(head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while(current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    void DeleteAtBeg() {
        if(head == nullptr) {
            return;
        }

        Node* oldHead = head;
        head = head->next;

        delete oldHead;
    }

    void DeleteAtPos(int position) {
        if(head == nullptr) {
            return;
        }

        if (position == 0) {
            DeleteAtBeg();
            return;
        }

        Node* pre = head;
        for(int i = 0; i < position - 1 && pre != nullptr; ++i) {
            pre = pre->next;
        }

        if (pre == nullptr) {
            return;
        }

        Node* toDelete = pre->next;
        pre->next = pre->next->next;
        delete toDelete;
    }

    void DeleteAtEnd() {
        if(head == nullptr) {
            return;
        }

        if(head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while(current->next->next != nullptr){
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }

    void Merge(const LinkedList& other) {
        if(this->head == nullptr || other.head == nullptr) {
            return;
        }

        Node* current= this->head;
        while(current->next != nullptr)
        {
            current = current->next;
        }

        current->next = other.head;
    }

    int Search(int element) {
        int position = 0;
        Node* current = head;

        while(current != nullptr){
            if(current->value == element){
                return position;
            }

            current = current->next;
            position++;
        }

        return -1;
    }

    void Output() {

        Node* current = head;
        while(current != nullptr){
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
private:
    Node* head{};
};

int main() {
    LinkedList list1;
    LinkedList list2;

    list1.InsertAtEnd(2);
    list1.InsertAtEnd(3);
    list1.InsertAtEnd(4);

    list2.InsertAtEnd(5);
    list2.InsertAtEnd(6);
    list2.InsertAtEnd(7);

//    list1[2] = 999;

    list1.Merge(list2);

    list1.Output();
}








