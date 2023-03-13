
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
                // 左右双旋
                else if (parent->_bf == -2 && cur->_bf == 1)
                {
                    RotateLR(parent);

                }
                // 右左双旋
                else if (parent->_bf == 2 && cur->_bf == -1)
                {
                    RotateRL(parent);

                }
            }

            else
            {
                // 说明之前的平衡树就有问题
                assert(false);
            }
            break;
        }
        return true;
    }

    void InoderTree(Node *root)
    {
        if (root == nullptr)
            return;

        InoderTree(root->_left);
        cout << root->_kv.first << " ";
        InoderTree(root->_right);
    }

    bool IsBalance()
    {
        return _IsBalance(_root);
    }

    int Hight(Node *root)
    {
        if (root == nullptr)
            return 0;
        return max(Hight(root->_left), Hight(root->_right)) + 1;
    }

    Node *getRoot()
    {
        return _root;
    }

private:
    Node *_root;
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
        if (subRL) // 如果有又子树有左子树
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
        subR->_bf = parent->_bf = 0;
    }

    void RotateLR(Node *parent)
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;
        int bf = subLR->_bf;

        RotateL(parent->_left);
        RotateR(parent);

        if(bf == 1) 
        {
            parent ->_bf =0;
            subL->_bf = -1;
            subLR->_bf = 0;
        }
        else if(bf==-1)
        {
            parent ->_bf =1;
            subL->_bf = 0;
            subLR->_bf = 0;
        }
        else if(bf == 0)
        {
            parent ->_bf =0;
            subL->_bf = 0;
            subLR->_bf = 0;
        }
        else
        {
            assert(false);
        }
    }

    void RotateRL(Node *parent)
    {

        Node* subR = parent->_right;
        Node* subRL = subR->_left;
        int bf = subRL->_bf;

        RotateR(parent->_right);
        RotateL(parent);

        if(bf == 1) 
        {
            parent ->_bf =-1;
            subR->_bf = 0;
            subRL->_bf = 0;
        }
        else if(bf==-1)
        {
            parent ->_bf =0;
            subR->_bf = 1;
            subRL->_bf = 0;
        }
        else if(bf == 0)
        {
            parent ->_bf =0;
            subR->_bf = 0;
            subRL->_bf = 0;
        }
        else
        {
            assert(false);
        }


    }
    bool _IsBalance(Node *root)
    {
        if (root == NULL)
            return true;

        int leftHeight = Hight(root->_left);
        int righttHeight = Hight(root->_right);

        if(righttHeight-leftHeight != root->_bf)
        {
            cout<< root->_kv.first<<" :当前平衡节点平衡因子现在是："<<root->_bf<<endl;
            cout<< root->_kv.first<<" :当前平衡节点平衡因子应该是："<<righttHeight-leftHeight<<endl;
        }


        return abs(righttHeight - leftHeight) < 2 && _IsBalance(root->_left) && _IsBalance(root->_right);
    }
};

void TestAVLTree()
{
    AVLTree<int, int> t;
    // int a[] = {5, 4, 3, 2, 1, 0};
    // int a[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
    int a[] = {0,1,2,3,4,5};
    for (auto e : a)
    {
        t.Insert(make_pair(e, e));
        cout<<"插入的"<<e<<"平衡:"<<endl<<t.IsBalance()<<endl;
        /* code */
    } 
    t.InoderTree(t.getRoot());
    cout <<endl <<t.IsBalance() << endl;
}

int main()
{
    TestAVLTree();
}