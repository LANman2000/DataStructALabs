#include <iostream>
#include <string>

// Push function: adds an element to the top of the stack
int push(std::string data[], int& top, const std::string& val){
    int status = 0; // default status is success

    if(top >= 5){ // fail if stack is full
        std::cout << "Stack overflow!" << std::endl;
        status =-1; // error code: stack overflow
    }else{
        data[++top] = val;
        std::cout << "Pushed: " << val << std::endl;
    }

    return status; // return error or success code
}

// Pop function: removes the top element from the stack and returns it
int pop(std::string data[], int& top){
    int status = 0; // default status is success

    if(top == -1){ // fail if stack is empty
        std::cout << "Stack underflow!" << std::endl;
        status =-1; // error code: stack underflow
    }else{
        std::cout << "Popped: " << data[top--] << std::endl;
    }

    return status; //return error or success code
}

// isEmpty function: checks if the stack is empty
int isEmpty(int top){
    int status = 0; // default status is not empty
    if(top == -1){
        status =-1; // error code: stack is empty
        std::cout << "Stack is empty!" << std::endl;
    }
    return status;
}

// showstack function: displays the contents of the stack
int showstack(std::string data[], int top){
    int status = 0; // default status is success

    if(top == -1){
        std::cout << "Stack is empty!" << std::endl;
        status =-1; // error code: stack is empty
    }else{
        std::cout << "Stack contents: ";
        for(int i = 0; i <= top; i++){
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    return status; // return error or success code
}

int main(){
    std::cout << "Hello, World! from stack" << std::endl;

    std::string data [6];
    int top = -1;

    pop(data, top); // should show stack underflow
    push(data, top, "R");
    push(data, top, "O");
    push(data, top, "Y");
    push(data, top, "G");
    push(data, top, "B");
    push(data, top, "V");
    push(data, top, "X"); // should show stack overflow
    pop(data, top); // should pop V
    showstack(data, top);

    return 0;
}