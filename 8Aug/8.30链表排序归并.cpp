#include<iostream>
#include<vector>

using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 //自底向上排序
// step=1: (3->4)->(1->7)->(8->9)->(2->11)->(5->6)
// step=2: (1->3->4->7)->(2->8->9->11)->(5->6)
// step=4: (1->2->3->4->7->8->9->11)->(5->6)
// step=8: (1->2->3->4->5->6->7->8->9->11)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int n=0;
        ListNode* temp = head;

        //计算长度
        while(temp)
        {
            n++;
            temp=temp->next;
        }
        //定义一个新的头结点
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        //
        for(int i=1;i<n;i*=2)
        {
            
            ListNode* cur = dummy;

            //一共需要合并 n/2*i次 向上取整
            int cnt = ceil(1.0 * n/(2*i));
            while(cnt--)
            {
                ListNode* tempp = dummy->next;
                while(tempp)
                {
                    cout<<tempp->val<<" ";
                    tempp = tempp->next;
                }
                cout<<endl;


                ListNode* p = dummy->next; //左边结点
                ListNode* q = dummy->next; //右边结点
                for(int j = 0;j<i && q;j++) q= q->next; //右边结点往后走i+n 次

                int l = 0,r=0;
                while(l < i && r<i && p && q)
                {
                    if(p->val <= q->val)
                    {
                        cur->next = p;
                        cur = cur ->next;
                        p = p->next;
                        l++;
                    }
                    else
                    {
                        cur->next = q;
                        cur = cur->next;
                        q=q->next;
                        r++;
                    }
                }
                if(l >=i || p == nullptr)
                {
                    cur->next = q;
                    while(r<i && q) 
                    {
                        cur = cur->next;
                        r++;
                    }
                }
                if(r >=i || p == nullptr)
                {
                    cur->next = p;
                    while(l<i && p) 
                    {
                        cur = cur->next;
                        l++;
                    }
                }
                if(i*2>=n)
                {
                    
                    cur->next = nullptr;
                }
                // cur->next = nullptr;
                // head = cur->next;
            }
        }
        return dummy->next;
    }
};


int  main()
{
    // vector<int> v = {6,1,2,5,4,3,9,7,10,8};
    // vector<int> v = {1,3,5,7,9,2,4,6,8,10};
    vector<int> v = {2,2,2,2,2,1};
    MyPrint(v);
    // QuickSort(v,0,v.size()-1);
    MergeSort(v,0,v.size()-1);
    MyPrint(v);

    return 0;
}