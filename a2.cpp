/*
    A2.cpp

    Lab A2 for Data structures 010, Spring 2026

*/

#include <iostream>
#include <vector>
#include <string>

// Element class to demonstrate destructor calls when elements are removed
struct Element {
    int val;

    // constructor
    Element(int v) : val(v) {}

    // destructor — invoked when element is removed
    ~Element() {
        std::cout << "Destructor called for: " << val << std::endl;
    }
};

class ADT {
public:
    std::vector<Element>* data;
    std::string mode; //stack or queue

    //constructor
    ADT(std::string m) : mode(m) {
        data = new std::vector<Element>();
    }

    //destructor
    ~ADT() {
        delete data;
        data = nullptr;
    }
};


// free functions that return int
int push(ADT& adt, int val){
    adt.data->push_back(Element(val));
    std::cout << "Pushed: " << val << std::endl;
    return 0;
}

int pop(ADT& adt){
    if (adt.data->empty()) {
    std::cout << "Stack underflow!" << std::endl;
    return -1;
    }
    std::cout << "Popped: " << adt.data->back().val << std::endl;
    adt.data->pop_back();
    return 0;
}
int enqueue(ADT& adt, int val){
    adt.data->push_back(Element(val));
    std::cout << "Enqueued: " << val << std::endl;
    return 0;
}

int dequeue(ADT& adt){
        if (adt.data->empty()) {
    std::cout << "Queue underflow!" << std::endl;
    return -1;
    }
    std::cout << "Dequeued: " << adt.data->front().val << std::endl;
    adt.data->erase(adt.data->begin());
    return 0;
}

int status(ADT& adt){
    std::cout << "Mode: " << adt.mode << std::endl;
    std::cout << "Size: " << adt.data->size() << std::endl;
    std::cout << "Vector object ptr: " << static_cast<void*>(adt.data) << std::endl;
    std::cout << "Internal array ptr: " << static_cast<void*>(adt.data->data()) << std::endl;

    if (adt.data->empty()) {
        std::cout << "ADT is empty!" << std::endl;
        return -1;
    }
    std::cout << "Elements:" << std::endl;
    for (auto it = adt.data->begin(); it != adt.data->end(); ++it) {
        std::cout << "  value: " << it->val << "  address: " << static_cast<void*>(&(*it)) << std::endl;
    }

    return 0;
}

int main() {
    std::cout << "Hello, World! from ADT" << std::endl;

    ADT myStack("stack");
    ADT myQueue("queue");

    if (pop(myStack) != 0) std::cout << "Pop failed" << std::endl; // should show underflow
    if (push(myStack, 5) != 0) std::cout << "Push failed" << std::endl; // size should be 1
    std::cout << "Capacity: " << myStack.data->capacity() << std::endl;
    
    // when capacity is exceeded, vector allocates a new block, copies elements over,
    // then destroys the old copies. This is why we see destructor calls for
    //  the old elements when we push more elements than the current capacity.

    if (push(myStack, 10) != 0) std::cout << "Push failed" << std::endl; // size should be 2
    std::cout << "Capacity: " << myStack.data->capacity() << std::endl; //capacity should have increased
    if (pop(myStack) != 0) std::cout << "Pop failed" << std::endl; // size should be 1
    if (push(myStack, 15) != 0) std::cout << "Push failed" << std::endl; // size should be 2
    status(myStack);

    if (dequeue(myQueue) != 0) std::cout << "Dequeue failed" << std::endl;
    
    if (enqueue(myQueue, 15) != 0) std::cout << "Enqueue failed" << std::endl; // size should be 1
    if (enqueue(myQueue, 20) != 0) std::cout << "Enqueue failed" << std::endl; // size should be 2
    if (dequeue(myQueue) != 0) std::cout << "Dequeue failed" << std::endl; // size should be 1
    if (enqueue(myQueue, 25) != 0) std::cout << "Enqueue failed" << std::endl; // size should be 2
    status(myQueue);

    return 0;
}