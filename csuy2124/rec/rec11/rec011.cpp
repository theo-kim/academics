#include <iostream>
using namespace std;

//class Node {
struct Node {
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};
// GIVEN FUNCTIONS: 

void listDisplay(Node* hp);

// END GIVEN FUNCTION


// ASSIGNMENT CODE:

void spliceInto(Node*& list, Node*& sublist) {
    if (list == nullptr) {
        list = sublist;
    }
    else if (list != sublist) { 
        Node* cursor = sublist;
        while (cursor->next != nullptr) {
            cursor = cursor->next;
        }
        cursor->next = list->next;
        list->next = sublist;
    }
}

Node* recurseSubList(Node*& haystack, Node*& needle, Node*& needleStart) {
    // if there is a match and we've reached the end of needle, YAY!
    if (haystack->data == needle->data && needle->next == nullptr) {
        return haystack;
    }
    // If there is a match, but there is still more needle to go
    else if (haystack->data == needle->data) {
        // End of the haystack, incomplete find, return nullptr
        if (haystack->next == nullptr) {
            return nullptr;
        }
        Node* n = recurseSubList(haystack->next, needle->next, needleStart);
        // If we've found more matches, return current position upwards
        if (n != nullptr) return haystack; 
        // We've found nothing :(, start over search from the next position
        else {
            return recurseSubList(haystack->next, needleStart, needleStart);
        }
    }
    // If we haven't found a match and we've reached the end, just return a nullptr
    else if (haystack->next == nullptr) {
        return nullptr;
    }
    // if we have't found a match, there is more to go, just call the next slot
    else {
        return recurseSubList(haystack->next, needleStart, needleStart);
    }
}

Node* isSubList(Node*& haystack, Node*& needle) {
    return recurseSubList(haystack, needle, needle);
}

int main() {
    Node* myList = nullptr;

    myList = new Node(17);
    myList->next = new Node(28);
    myList->next->next = new Node(1);

    cout << "MyList:" << endl;
    listDisplay(myList);

    Node* anotherList = nullptr;
    anotherList = new Node(5);
    anotherList->next = new Node(40);
    anotherList->next->next = new Node(10);

    cout << "AnotherList:" << endl;
    listDisplay(anotherList);

    spliceInto(myList->next, anotherList);

    cout << "SplicedList:" << endl;
    listDisplay(myList);

    myList = new Node(3, new Node(4, new Node(3, new Node(4, new Node(5, new Node(6))))));
    anotherList = new Node(5, new Node(6, new Node(7)));

    cout << "Searching: " << endl;
    cout << "Needle: ";
    listDisplay(anotherList);
    cout << "Haystack: ";
    listDisplay(myList);

    Node* sublist = isSubList(myList, anotherList);

    if (sublist != nullptr) {
        cout << sublist->data << endl;
    }
    else {
        cout << "not found" << endl;
    }

     myList = new Node(3, new Node(4, new Node(3, new Node(4, new Node(5, new Node(6))))));
    anotherList = new Node(3, new Node(4, new Node(5)));

    cout << "Searching: " << endl;
    cout << "Needle: ";
    listDisplay(anotherList);
    cout << "Haystack: ";
    listDisplay(myList);

    sublist = isSubList(myList, anotherList);

    if (sublist != nullptr) {
        cout << sublist->data << endl;
    }
    else {
        cout << "not found" << endl;
    }
     myList = new Node(3, new Node(4, new Node(3, new Node(4, new Node(5, new Node(6))))));
    anotherList = new Node(5, new Node(7, new Node(7)));

    cout << "Searching: " << endl;
    cout << "Needle: ";
    listDisplay(anotherList);
    cout << "Haystack: ";
    listDisplay(myList);

    sublist = isSubList(myList, anotherList);

    if (sublist != nullptr) {
        cout << sublist->data;
    }
    else {
        cout << "not found" << endl;
    }
}



// GIVEN CODE:

void listDisplay(Node* hp) {
    Node* p = hp;
    while (p != nullptr) {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}