#include <iostream>
#include <string>

int enqueue(std::string data[], int& count, int& rear, int& front, const std::string& val){
    int status = 0; // default status is success

    if(count == 6){ // fail if queue is full
        std::cout << "Queue overflow!" << std::endl;
        status =-1; // error code: queue overflow
    }else{
        rear = (rear + 1) % 6;
        data[rear] = val;
        count++;
        std::cout << "Added: " << val << std::endl;
    }

    return status; // return error or success code
}

int dequeue(std::string data[], int& count, int& front, int& rear){
    int status = 0; // default status is success

    if(count == 0){ // fail if queue is empty
        std::cout << "Queue underflow!" << std::endl;
        status =-1; // error code: queue underflow
    }else{
        front = (front + 1) % 6;
        count--;
        std::cout << "Removed: " << data[front] << std::endl;
    }

    return status; // return error or success code
}

int isEmpty(int count){
    int status = 0; // default status is not empty
    if(count == 0){
        status =-1; // error code: queue is empty
        std::cout << "Queue is empty!" << std::endl;
    }
    return status;
}

int showqueue(std::string data[], int count, int front, int rear){
    int status = 0; // default status is success

    if(count == 0){
        std::cout << "Queue is empty!" << std::endl;
        status =-1; // error code: queue is empty
    }else{
        std::cout << "Queue contents: ";
        int i = (front + 1) % 6; // start from first valid element
        for(int num = 0; num < count; num++){
            std::cout << data[i] << " ";
            i = (i + 1) % 6;
        }
        std::cout << std::endl;
    }
    return status; // return error or success code
}

int main(){
    std::cout << "Hello World, from queue!" << std::endl;

    std::string data[6];
    int front = 0;
    int rear = 0;
    int count = 0;

    dequeue(data, count, front, rear); // should show queue underflow
    enqueue(data, count, front, rear, "R");
    enqueue(data, count, front, rear, "O");
    enqueue(data, count, front, rear, "Y");
    enqueue(data, count, front, rear, "G");
    enqueue(data, count, front, rear, "B");
    enqueue(data, count, front, rear, "V");
    enqueue(data, count, front, rear, "X"); // should show queue overflow
    showqueue(data, count, front, rear);
    dequeue(data, count, front, rear); // remove R
    dequeue(data, count, front, rear); // remove O
    showqueue(data, count, front, rear);
    dequeue(data, count, front, rear); // remove Y
    dequeue(data, count, front, rear); // remove G
    dequeue(data, count, front, rear); // should show queue underflow
    return 0;
}