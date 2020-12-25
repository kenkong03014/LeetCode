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

/** ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if(l1 == nullptr && l2 == nullptr)
        return nullptr;
    if(l1 == nullptr && l2 != nullptr)
        return l2;
    else if(l1 != nullptr && l2 == nullptr)
        return l1;
    
    ListNode* front = new ListNode;
    ListNode* rear = new ListNode;

    int count = 0;
    while(l1 != nullptr || l2 != nullptr)
    {
        if(l1 == nullptr)
        {
            rear->next = l2;
            rear = l2;
            break;
        }
        else if(l2 == nullptr)
        {
            rear->next = l1;
            rear = l1;
            break;
        }

        if(l1->val <= l2->val)
        {
            ListNode* tmp = new ListNode(l1->val);

            if(count == 0)
            {
                front = tmp;
                front->next = rear;
                rear = tmp;
            }
            else
            {
                rear->next = tmp;
                rear = tmp;
            }
            l1 = l1->next;
        }
        else if(l1->val > l2->val)
        {
            ListNode* tmp = new ListNode(l2->val);

            if(count == 0)
            {
                front = tmp;
                front->next = rear;
                rear = tmp;
            }
            else
            {
                rear->next = tmp;
                rear = tmp;
            }
            l2 = l2->next;
        }
        count++;
    }
    return front;
}
*/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if(l1 == nullptr && l2 == nullptr)
        return nullptr;
    if(l1 == nullptr && l2 != nullptr)
        return l2;
    else if(l1 != nullptr && l2 == nullptr)
        return l1;
    else if(l1->val < l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
int main()
{
    // ListNode* l1 = new ListNode(1);
    // l1->next = new ListNode(5);
    // l1->next->next = new ListNode(6);
    // l1->next->next->next = new ListNode(10);

    // ListNode* l2 = new ListNode(5);;
    // l2->next = new ListNode(9);
    // l2->next->next = new ListNode(11);
    // l2->next->next->next = new ListNode(14);

    ListNode* l1 = new ListNode(2);
    ListNode* l2 = new ListNode(1);;


    ListNode* front = mergeTwoLists(l1,l2);
    while(front != nullptr)
    {
        cout << "val: " << front->val << endl;
        front = front->next;
    }
    return 0;
}