#include<vector>
#include<iostream>
using namespace std;
struct ListNode{
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}

};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    三种解法
    1、递归
    2、辅助栈
    3、逆序链表
*/


class Solution {
public:
    vector<int> ans;

    void dfsLink(ListNode* node)
    {
        if(node == nullptr)
        {
            return;
        }

        dfsLink(node->next);
        ans.push_back(node->val);

    }


    vector<int> reversePrint(ListNode* head) {
        dfsLink(head);
        return ans;
    }
};