/** Implement stack using queues */

/* Approach 2 - make pop() costlier and use 1 queue
Steps:
1. Push to queue normally
2. During pop(), remove all elements in queue and push it to itself except one last element
3. That way we preserve the latest element at the front
*/

#include <iostream>
#include <queue>

class Stack {
    std::queue<int> q;

public:
    void push(int val) {
        q.push(val);
    }

    int pop() {
        int size = q.size();
        for (int i=0; i<size-1; i++) {
            q.push(q.front());
            q.pop();
        }
        int top = q.front();
        q.pop();

        return top;
    }

    int top() { 
        return q.back();
    }

    bool isEmpty() {
        return q.empty();
    }
};


int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top: " << stack.top() << std::endl;  // Output: 3
    stack.pop();
    std::cout << "Top after pop: " << stack.top() << std::endl;  // Output: 2
    stack.pop();
    std::cout << "Top after second pop: " << stack.top() << std::endl;  // Output: 1
}
