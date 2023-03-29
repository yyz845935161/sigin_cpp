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
    BSTreeNode(const K &key)
        : _key(key), _left(nullptr), _right(nullptr)
    {
    }
};

template <class K>
struct BSTree
{
    /* data */
    typedef BSTreeNode<K> Node;

public:
    BSTree()
        : _root(nullptr)
    {
    }

    bool Insert(const K &key)
    {
        if (this->_root == nullptr)
        {
            this->_root = new Node(key);
            return true;
        }
        Node *parent = nullptr;
        Node *cur = _root;
        while (cur)
        {
            /* code */
            if (cur->_key < key)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if (cur->_key > key)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                return false;
            }
        }
        Node *temp = new Node(key);
        if (parent->_key < key)
        {
            parent->_right = temp;
        }
        else
        {
            parent->_left = temp;
        }
    }

    bool InsertR(const K &key)
    {
        return _InsertR(_root, key);
    }

    Node *FindR(const K &key)
    {
        _FindR(_root, key);
    }
    void InOrder()
    {
        _InOrder(this->_root);
        cout << endl;
    }

    void _InOrder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        _InOrder(node->_left);
        cout << node->_key << "  ";
        _InOrder(node->_right);
    }

    bool Find(const K &key)
    {
        Node *cur = _root;
        while (cur)
        {
            if (cur->key < key)
            {
                cur = cur->_right;
            }
            if (cur->key > key)
            {
                cur = cur->_left;
            }
            else
            {
                return true;
            }
        }
        return false;
    }

    bool Erase(const K &key)
    {
        Node *parent = nullptr;
        Node *cur = this->_root;
        while (cur)
        {
            if (cur->_key < key)
            {
                parent = cur;
                cur = cur->_right;
            }
            if (cur->_key > key)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                // 找到，准备删除
                // 如果左边为空
                if (cur->_left == nullptr)
                {
                    if (parent == nullptr)
                    {
                        _root = cur->_right;
                    }
                    else
                    {
                        if (parent->_left == cur)
                        {
                            parent->_left = cur->_right;
                        }
                        else
                        {
                            parent->_right = cur->_right;
                        }
                    }

                    delete cur;
                    cur = nullptr;
                }
                // 如果左边为空
                else if (cur->_right == nullptr)
                {
                    if (parent == nullptr)
                    {
                        _root = cur->_right;
                    }
                    else
                    {
                        if (parent->_left == cur)
                        {
                            parent->_left = cur->_left;
                        }
                        else
                        {
                            parent->_right = cur->_left;
                        }
                    }
                    if (parent->_left == cur)
                    {
                        parent->_left = cur->_left;
                    }
                    else
                    {
                        parent->_right = cur->_left;
                    }
                    delete cur;
                    cur = nullptr;
                }
                // 如果左右都不为空
                else
                {
                    Node *father = cur;
                    Node *max = cur->_left;
                    while (max->_right)
                    {
                        father = max;
                        max = max->_right;
                    }
                    cur->_key = max->_key;
                    if (father->_left == max)
                    {
                        father->_left = max->_left;
                    }
                    else
                    {
                        father->_right = max->_left;
                    }

                    delete max;
                    // min = nullptr;
                    return true;
                }
            }
        }

        return false;
    }

    bool EraseR(const K& key)
    {
        return _EraseR(_root,key);
    }


private:
    Node *_root;

    bool _InsertR(Node *&root, const K &key)
    {
        if (root == nullptr)
        {
            root = new Node(key);
            return true;
        }
        if (root->_key < key)
        {
            return _InsertR(root->_right, key);
        }
        else if (root->_key > key)
        {
            return _InsertR(root->_left, key);
        }
        else
            return false;
    }

    Node *_FindR(Node *root, const K &key)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->_key < key)
        {
            return _FindR(root->_right, key);
        }
        else if (root->_key > key)
        {
            return _FindR(root->_left, key);
        }
        else
        {
            return root;
        }
    }

    bool _EraseR(Node *&root,const K& key)
    {
        if(root == nullptr)
        {
            return false;
        }
        if(root -> key < key)
        {
            _EraseR(root->_right,key);
        }
        else if(root -> key > key)
        {
            _EraseR(root->_left,key);
        }
        else
        {
            Node* del =root;
            if(root->_left ==nullptr)
            {
                root = root ->_right;
            }
            else if(root->_right == nullptr)
            {
                root = root ->_left;
            }
            else
            {
                Node* min = root->_right;
                while(min -> _left)
                {
                    min = min->_left;
                }
                swap(min->_key,root ->_key);
                return _EraseR(root->_right,_key)
            }
            delete del;
            return true;

        }
    }

};

void TestBSTree()
{
    BSTree<int> t;
    int a[] = {5, 3, 4, 1, 7, 8, 2, 6, 0, 9};
    for (auto e : a)
    {
        t.InsertR(e);
    }
    t.InOrder();

    t.Erase(5);
    t.InOrder();
}

int main()
{
    TestBSTree();
    return 0;
}