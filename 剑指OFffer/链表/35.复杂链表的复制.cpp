#include<vector>
#include<iostream>
#include<map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


//哈希表记录  先创建再链接
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<int,Node*> m;
        map<Node*,Node*> bn;
        Node* temp = head;
        int i=0;
        while(temp)
        {
            Node* n = new Node(temp->val);
            m[i++] = n;
            bn[temp] = n;
            temp = temp->next;
        }
        m[i]= nullptr;

        // for(map<int,Node*>::iterator it= m.bedin();it!=m.end();it++)
        // {

        // }
        i=0;
        while(head)
        {   
            m[i]->next = m[i+1];
            
            if(head->random)
                // m[head->val]->random = m[head->random->val];
                bn[head]->random =  bn[head->random];
            else
                bn[head]->random = nullptr;

            head = head->next;
            i++;
        }

        return m[0];

        
    }
};

//方法二：迭代 + 节点拆分
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* nodeNew = new Node(node->val);
            nodeNew->next = node->next;
            node->next = nodeNew;
        }
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* nodeNew = node->next;
            nodeNew->random = (node->random != nullptr) ? node->random->next : nullptr;
        }
        Node* headNew = head->next;
        for (Node* node = head; node != nullptr; node = node->next) {
            Node* nodeNew = node->next;
            node->next = node->next->next;
            nodeNew->next = (nodeNew->next != nullptr) ? nodeNew->next->next : nullptr;
        }
        return headNew;
    }
};
