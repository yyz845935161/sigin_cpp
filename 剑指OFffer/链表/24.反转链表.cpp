/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<vector>
#include<iostream>
using namespace std;
struct ListNode{
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}

};

//头插法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newhead = new ListNode(0);
        while(head)
        {
            ListNode* temp = head->next;
            head->next = newhead->next;
            newhead->next = head;
            head = temp;
        }

        return newhead->next;

    }
};