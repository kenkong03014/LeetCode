#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <array>
#include <string>
#include <ctype.h>
#include <cstring>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {

	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}

	ListNode* output = new ListNode();
	ListNode* front = new ListNode();
	ListNode* rear = new ListNode();
	ListNode* tmp = head;
	int count = 0;

	do
	{

		ListNode* newNode = new ListNode(tmp->val);
		newNode->next = nullptr;

		if (tmp->next == nullptr)
		{
			if (count != 1)
				break;
			else
			{
				newNode->next = new ListNode(head->val);
				return newNode;
			}
		}
		if (count == 0)
		{
			front = newNode;
			front->next = rear;
			rear = newNode;
		}
		else
		{
			rear->next = newNode;
			rear = newNode;
		}
		tmp = tmp->next;
		count++;
	} while (tmp != nullptr);
	output = tmp;
	output->next = reverseList(front);
	return output;
}

int main()
{
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(5);
    l1->next->next = new ListNode(6);
    l1->next->next->next = new ListNode(10);

    ListNode* output = reverseList(l1);

    while(output != nullptr)
    {
        cout << output->val << " ";
        output = output->next;
    }
    cout << "\n";
    return 0;
}