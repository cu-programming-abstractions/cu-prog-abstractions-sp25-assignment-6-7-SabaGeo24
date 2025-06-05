#include "list_utils.h"
#include "list.h"



int length(const LinkedList& list) {
    int length = 0;

    LinkedList::Node* Head = list.getHead();

    while(Head)
    {
        length++;
        Head = Head->next;
    }

    return length;
}



int sum(const LinkedList& list) {

    int sum = 0;

    LinkedList::Node* Head = list.getHead();

    while(Head)
    {
        sum += Head->data;
        Head = Head->next;
    }

    return sum;


}


bool contains(const LinkedList& list, int k) {

    LinkedList::Node* Head = list.getHead();

    while(Head)
    {
        if(Head->data == k)
        {
            return true;
        }

        Head = Head->next;
    }

    return false;
}


void reverse(LinkedList& list) {

    LinkedList::Node* prev = nullptr;
    LinkedList::Node* curr = list.getHead();

    while (curr) {
        LinkedList::Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    list.setHead(prev);
}


int nthFromEnd(const LinkedList& list, int n) {

    if (n <= 0) throw out_of_range("Invalid n: n must be positive");

    LinkedList temp1 = list;
    LinkedList temp2 = list;


    for (int i = 0; i < n; ++i) {
        if (temp1.isEmpty()) {
            throw out_of_range("Invalid n: n is larger than list length");
        }
        temp1.removeFront();
    }


    while (!temp1.isEmpty()) {
        temp1.removeFront();
        temp2.removeFront();
    }

    if (temp2.isEmpty()) throw out_of_range("Invalid n");

    return temp2.removeFront();

}
