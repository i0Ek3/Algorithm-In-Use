#include <iostream>

class Solution {
    stack<int> s1, s2;
public:
    void push(int val) {
        s1.push(val);
        if (s2.empty()) s2.push(val);
        else if (val <= s2.top()) s2.push(val);
    }

    void pop() {
        if (s1.top() == s2.top()) s2.pop();
        s1.pop();
    }

    int top() {
        return s1.top();
    }

    int min() {
        return s2.top();
    }       
};
