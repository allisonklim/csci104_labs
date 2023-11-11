#include "Queue.h"
#include <iostream>
// empty constructor
Queue::Queue() {

}

// empty destructor
Queue::~Queue() {

}

// do not change
void Queue::enqueue(int x) {
    stack1.push(x);
}

// you implement this!!!
void Queue::dequeue() {
    //if stack2 is not empty, then pop from it. 

    if (!stack2.empty()){
        stack2.pop();
    } 
    else{
        //Otherwise, pop the entire contents of stack1, pushing each one onto stack2. Now pop from stack2
        if(stack1.empty()){
            return;
        }
        while(!stack1.empty()){
            int temp = stack1.top();
            stack1.pop();
            stack2.push(temp);
            
        }
        stack2.pop();
    }
}

// you implement this!!!
int Queue::front() {
    //if stack 2 not empty, top of stack
    if(!stack2.empty()){
        return stack2.top();
    }
    else{
        int temp = 0;
        std::stack<int> tempStack = stack1;
        while(!tempStack.empty()){
            temp = tempStack.top(); // item you want to move
            tempStack.pop();
        }
        return temp; 
        
        /*
        while(!stack1.empty()){
            int temp = stack1.top(); // item you want to move
            stack1.pop();
            stack2.push(temp);
            // tempStack.pop();
        }
        // return temp; 
        return stack2.top();
        */
    }
}

// do not change
bool Queue::empty() {
    return stack1.empty() && stack2.empty();
}