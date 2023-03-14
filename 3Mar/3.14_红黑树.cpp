#include <iostream>
using namespace std;
#include <vector>
#include <map>
enum Colour
{
    RED,
    BLACK
};

template <class K, class V>
struct RBTreeNode
{
    RBTreeNode<K, V> *_left;
    RBTreeNode<K, V> *_right;
    RBTreeNode<K, V> *_parent;
    pair<K, V> _kv;
    Colour _col;
};

template <class K, class V>
class RBTree
{
    typedef RBTreeNode<K, V> Node;

public:
    RBTree()
        : root(nullptr)
    {
    }

    bool Insert(const pair<K, V> &kv)
    {
        if (_root == nullptr)
        {
            _root = new Node(kv);
            return true;
        }
        Node *parent = nullptr;
        Node *cur = _root;
        while (cur)
        {
            if (cur->_kv.first < kv.first)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if (cur->_kv.first > kv.first)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
                return false;
        }

        cur = new Node(kv);
        if (parent->_kv.first < kv.first)
        {
            parent->_right = cur;
            cur->_parent = parent;
        }
        else
        {
            parent->_left = cur;
            cur->_parent = parent;
        }

        //控制平衡
    }

private:
    Node *_root;
};