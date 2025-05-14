/** Implement stack using queues */

/* Approach 1 - make push() costlier and use 2 queues 
Steps:
1. Push new element to q2
2. Copy all elements from q1 into q2
3. swap q1 and q2. All elements would be in q1 now
*/

#include <iostream>
#include <queue>

class Stack {
    std::queue<int> q1; 
    std::queue<int> q2;
    int count;

public:
    Stack() : count{0} {}

    int top() {
        if (!q1.empty()) {
            return q1.front();
        }
        return -1;
    }

    void push(int val) {
        q2.push(val);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        std::swap(q1, q2);
        count++;
    }

    void pop() {
        if (q1.empty()) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        q1.pop();
        count--;
    }

    int size() {
        return count;
    }

    bool isEmpty() { return q1.empty(); }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    std::cout << "Top: " << s.top() << std::endl;  // 20
    s.push(30);
    
    s.pop();
    std::cout << "Top: " << s.top() << std::endl;  // 20
    
    s.pop();
    s.pop();
    s.pop(); // Should print "Stack is empty"

    return 0;
}