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
        cur->_col = RED;
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

        //控制平衡   //若要调整平衡，cur一定是红，paretn一定是红（为黑不用调整），gradeparent一定是黑
        while (parent && parent->_col == RED)
        {
            Node* greaterfather = parent->_parent;
            if(parent == greaterfather ->_left)
            {
                Node* uncle = greaterfather->_right;
                //1叔叔存在 且为红
                if(uncle && uncle->_col == RED)
                {
                    //变色+继续调整
                    parent->_col = uncle->_col = BLACK;
                    greaterfather->_col = RED;
                    cur = greaterfather;
                    parent = cur->_parent;
                }
                else  //叔叔不存在/存在为黑
                {   
                    if(cur==parent->_left)
                    {
                        RotateR(greaterfather);
                        parent ->_col = BLACK;
                        greaterfather->_col = RED;
                    }
                    break;
                }
            }

            else  //parent == greaterfather ->_right
            {

            }
            
        }

        _root->_col = BLACK; 
        
    }

private:
    Node *_root;
};