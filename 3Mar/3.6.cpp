#include <iostream>
using namespace std;
#include <string>
#include <stdio.h>

template <class K>
struct BSTreeNode
{
    BSTreeNode<K> *_left;
    BSTreeNode<K> *_right;
    K _key;
    /* data */
    BSTreeNode(const K& key)
        :_key(key)
        ,_left(nullptr)
        ,_right(nullptr)
    {}
};

template <class K>
struct BSTree
{
    /* data */
    typedef BSTreeNode<K> Node;

public:
    BSTree()
        : _root(nullptr)
    {}

    

    bool Insert(const K& key){
        if(this->_root == nullptr)
        {
            this->_root = new Node(key);
            return true;
        }
        Node* parent = nullptr;
        Node* cur = _root;
        while (cur) 
        {
            /* code */
            if(cur ->_key <key)
            {
                parent = cur;
                cur=cur->_right;
            }
            else if (cur ->_key > key)
            {
                parent = cur;
                cur=cur->_left;
            }
            else
            {
                return false;
            }
            
    

        }
        Node* temp = new Node(key); 
        if(parent ->_key <key)
        {
            parent->_right = temp;
        }
        else{
            parent->_left = temp;
        }



    }

    void InOrder()
    {
        _InOrder(this->_root);
    }

    void _InOrder(Node* node)
    {
        if(node == nullptr)
        {
            return;
        }
        _InOrder(node->_left);
        cout<<node->_key<<"  ";
        _InOrder(node->_right);
    }
    

    bool* Find(const K& key)
    {
        Node* cur = _root:
        while (cur)
        {
            if(cur->key <key)
            {
                cur = cur->_right;
            }
            if(cur->key > key)
            {
                cur = cur->_left;
            }
            else{
                return true;
            }
        }
        return false;
    }

    bool Erase(const K& key)
    {

    }



private:
    Node *_root;
};





void TestBSTree()
{
    BSTree<int> t;
    int a[] = {5,3,4,1,7,8,2,6,0,9};
    for(auto e:a)
    {
        t.Insert(e);
    }
    t.InOrder();
}

int main()
{
    TestBSTree();
    return 0;
}