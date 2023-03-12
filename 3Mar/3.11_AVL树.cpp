
#include <iostream>
#include <string>
#include <map>
#include <assert.h>
using namespace std;

template <class K, class V>
struct AVLTreeNode
{
    AVLTreeNode<K, V> *_left;
    AVLTreeNode<K, V> *_right;
    AVLTreeNode<K, V> *_parent;
    pair<K, V> _kv;
    int _bf;
    AVLTreeNode(const pair<K, V> &kv)
        : _left(nullptr), _right(nullptr), _parent(nullptr), _bf(0), _kv(kv)
    {
    }
    /* data */
};

template <class K, class V>
class AVLTree
{
    typedef AVLTreeNode<K, V> Node;

public:
    AVLTree()
        : _root(nullptr)
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

        // 控制平衡
        // 1、更新平衡因子 -- 新增节点的所有祖先
        // 1.1 更新后 ，父亲bf==0 ， 不用更新父亲
        // 1.2 更新后，父亲bf== -+1，要更新父亲
        // 1.3更新后，父亲bf==-+2 ，要旋转了
        // 2、出现异常，就要旋转
        while (parent)
        {
            if (cur == parent->_left)
            {
                parent->_bf--;
            }
            else
                parent->_bf++;

            if (parent->_bf == 0)
            {
                break;
            }

            else if (parent->_bf == 1 || parent->_bf == -1)
            {
                // 继续往上更新
                cur = parent;
                parent = parent->_parent;
            }
            else if (parent->_bf == 2 || parent->_bf == -2)
            {
                // 旋转
                // 右单旋
                if (parent->_bf == -2 && cur->_bf == -1)
                {
                    RotateR(parent);
                }

                // 左单旋
                else if (parent->_bf == 2 && cur->_bf == 1)
                {
                    RotateL(parent);
                }
            }

            else
            {
                // 说明之前的平衡树就有问题
                assert(false);
            }
        }
        return true;
    }

    void RotateR(Node *parent)
    {
        Node *subL = parent->_left;
        Node *subLR = subL->_right;
        parent->_left = subLR;
        if (subLR)
            subLR->_parent = parent;

        Node *parentParent = parent->_parent;
        subL->_right = parent;
        parent->_parent = subL;

        if (parent == _root)
        {
            _root = subL;
            _root->_parent = nullptr;
        }
        else
        {
            if (parentParent->_left = parent)
                parentParent->_left = subL;
            else
                parentParent->_right = subL;
            subL->_parent = parentParent;
        }
        subL->_bf = parent->_bf = 0;
    }

    void RotateL(Node *parent)
    {
        Node *subR = parent->_right;
        Node *subRL = subR->_left;
        Node *parentParent = parent->_parent;

        subR->_left = parent;
        parent->_parent = subR;

        parent->_right = subRL;
        if (subRL)  //如果有又子树有左子树
            subRL->_parent = parent;

        if (parent == _root)
        {
            _root = subR;
            _root->_parent = nullptr;
        }

        else
        {
            if (parentParent->_left == parent)
                parentParent->_left = subR;
            else
                parentParent->_right = subR;
             subR->_parent = parentParent;
        }
        subR->_bf = parent->_bf =0;
       
    }

    void InoderTree(Node *root)
    {
        if (root == nullptr)
            return;

        InoderTree(root->_left);
        cout << root->_kv.first << " ";
        InoderTree(root->_right);
    }

    Node *getRoot()
    {
        return _root;
    }

private:
    Node *_root;
};

void TestAVLTree()
{
    AVLTree<int, int> t;
    // int a[] = {5, 4, 3, 2, 1, 0};
    int a[] = {0,1,2,3,4,5};
    for (auto e : a)
    {
        t.Insert(make_pair(e, e));
        /* code */
    }
    t.InoderTree(t.getRoot());
}

int main()
{
    TestAVLTree();
}