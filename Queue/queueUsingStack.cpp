/*
Implement Queue using stack - need 2 stacks
*/

#include <stack>
#include <iostream>

class Queue {
    std::stack<int> s_in;
    std::stack<int> s_out;

public:
    void push(int val) {
        s_in.push(val);
    }

    void pop() {
        if (s_out.empty()) {
            if (s_in.empty()) {
                std::cout << "No elements in queue to pop!" << std::endl;
                return;
            }
            while (!s_in.empty()) {
                s_out.push(s_in.top());
                s_in.pop();
            }
        }
        std::cout << "Popping value : " << s_out.top() << std::endl;
        s_out.pop();
    }

    bool isEmpty() {
        return s_in.empty() && s_out.empty();
    }

    int peek() {
        if (s_out.empty()) {
            // transfer from s_in to s_out
            if (s_in.empty()) {
                std::cout << "No elements in queue to pop!" << std::endl;
                return -1;
            }
            while(!s_in.empty()) {
                s_out.push(s_in.top());
                s_in.pop();
            }
        }
        return s_out.top();
    }

};