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

/**bool isPalindrome(ListNode* head) {
    if(head == nullptr || head->next == nullptr)
        return true;
    
    ListNode* prev = nullptr;
    ListNode* curr = head;

    ListNode* newCopy = new ListNode;
    ListNode* rear = new ListNode;
    int count = 0;

    while(curr != nullptr)
    {
        ListNode* tmp = curr->next;
        ListNode* tmp2 = new ListNode(curr->val);
        
        if(count == 0)
        {
            newCopy = tmp2;
            newCopy->next = rear;
            rear = tmp2;
        }
        else
        {
            rear->next = tmp2;
            rear = tmp2;
        }
        curr->next = prev;
        prev = curr;
        curr = tmp;
        count++;
    }

    while(prev != nullptr && newCopy != nullptr)
    {
        if(prev->val != newCopy->val)
            return false;
        
        prev = prev->next;
        newCopy = newCopy->next;
    }


    return true;
}
*/

/** bool isPalindrome(ListNode* head)
{
    vector<int> newCopy;
    ListNode* tmp = head;

    while(tmp != nullptr)
    {
        newCopy.push_back(tmp->val);
        tmp = tmp->next;
    }

    for(unsigned int i = 0; i<newCopy.size()/2; i++)
    {
        if(newCopy[i] != newCopy[newCopy.size()-i-1])
            return false;
    }

    return true;
}*/

ListNode* reverseList(ListNode* head) {

	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}
	
	ListNode* prev = nullptr;
	ListNode* current = head;

	while(current != nullptr)
	{
		ListNode* tmp = current->next;

		current->next = prev;

		prev = current;

		current = tmp;
	}

	return prev;
}

ListNode* findFirstHalf(ListNode* head)
{
    ListNode* firstHalf = head;
    ListNode* secondHalf = head;

    while(secondHalf->next != nullptr && secondHalf->next->next != nullptr)
    {
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next->next;
    }

    return firstHalf;
}

bool isPalindrome(ListNode* head)
{
    if(head == nullptr || head->next == nullptr)
        return true;

    ListNode* firstHalfEnd = findFirstHalf(head);
    ListNode* secondHalf = reverseList(firstHalfEnd->next);

    ListNode* L1 = head;
    ListNode* L2 = secondHalf;

    while(L1 !=nullptr && L2 != nullptr)    
    {
        if(L1->val != L2->val )
            return false;
        
        L1 = L1->next;
        L2 = L2->next;
    }

    return true;
}

int main()
{
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(0);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(0);
    l1->next->next->next->next->next = new ListNode(1);
    if(isPalindrome(l1) == true)
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}