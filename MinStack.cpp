#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <array>
#include <string>
#include <ctype.h>
using namespace std;
struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/** Linked-list 
 * class MinStack {
public:
    ListNode *front;
    ListNode *smallest;
    ListNode* tmp;
    MinStack()
    {
        front = nullptr;
        smallest = nullptr;
    }
    
    void push(int x) {
        ListNode* tmp2  = new ListNode(x);
        tmp2->next = front;
        front = tmp2;

        if(smallest == nullptr)
        {
            tmp = new ListNode(x);
            tmp->next = smallest;
            smallest = tmp;
        }
        else if(x <= smallest->val)
        {
            tmp = new ListNode(x);
            tmp->next = smallest;
            smallest = tmp;
        }
    }
    
    void pop() {
        if(front->val == smallest->val)
            smallest = smallest->next;
        front = front->next;
    }
    
    int top() {
        return front->val;
    }
    
    int getMin() {
        return smallest->val;
    }
};
*/

/** vector two stacks
class MinStack {
public:
    ListNode *front;
    vector<pair<int,int>> smallest;


    MinStack()
    {
        front = nullptr;
    }
    
    void push(int x) {
        ListNode* tmp2  = new ListNode(x);
        tmp2->next = front;
        front = tmp2;

        if(smallest.size() == 0)
            smallest.emplace_back(x, 1);
        else
        {
            if(smallest.back().first == x)
                smallest.back().second++;
            else if(x < smallest.back().first)
                smallest.emplace_back(x, 1);
        }  
    }
    
    void pop() {
        if(front->val == smallest.back().first)
        {
            if(smallest.back().second == 1)
                smallest.pop_back();
            else
                smallest.back().second--;
        }
        front = front->next;
    }
    
    int top() {
        return front->val;
    }
    
    int getMin() {
        return smallest.back().first;
    }
};
*/

class MinStack {
private:
    vector<tuple<int, int>> stack {};
    int minEl = numeric_limits<int>::max();
    int x_tmp;

public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        if (x<minEl) { minEl = x; }
        stack.push_back(make_tuple(x, minEl));
    }
    
    void pop() {
        stack.pop_back();
        if (stack.size()){
            tie(x_tmp, minEl) = stack[stack.size()-1];
        } else {
            minEl = numeric_limits<int>::max();
        }
    }
    
    int top() {
        tie(x_tmp, minEl) = stack[stack.size()-1];
        return x_tmp;
    }
    
    int getMin() {
        tie(x_tmp, minEl) = stack[stack.size()-1];
        return minEl;
    }
};
int main()
{
    MinStack* obj = new MinStack();

    obj->push(2147483646);
    obj->push(2147483646);
    obj->push(2147483647);
    cout << "top: " << obj->top() << endl;
    obj->pop();
    cout << "min: " << obj->getMin() << endl;
    obj->pop();
    cout << "min2: " << obj->getMin() << endl;
    obj->pop();
    obj->push(2147483647);
    cout << "top: " << obj->top() << endl;
    cout << "min: " << obj->getMin() << endl;
    obj->push(-2147483648);
    cout << "top: " << obj->top() << endl;
    cout << "min: " << obj->getMin() << endl;
    obj->pop();
    cout << "min: " << obj->getMin() << endl;


    return 0;
}