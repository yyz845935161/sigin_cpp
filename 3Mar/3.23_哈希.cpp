#include <iostream>

#include <string>
#include <vector>
using namespace std;
enum State
{
    EMPTY,
    EXIST,
    DELETE
};

template <class K, class V>
class HashData
{
public:
    pair<K, V> _kv;
    State _state = EMPTY;
};

template <class K>
struct HashFunc
{
    size_t operator()(const K &key)
    {
        return (size_t)key;
    }
};

template <>
struct HashFunc<string>
{
    size_t operator()(const string &key)
    {
        size_t val = 0;
        for (auto ch : key)
        {
            val += ch;
            /* code */
        }

        return val;
    }
};

template <class K, class V, class Hash = HashFunc<K>>
class HashTable
{
private:
    vector<HashData<K, V>> _tables;
    size_t _size = 0;
    /* data */
public:
    bool Insert(pair<K, V> kv)
    {
        if (Find(kv.first))
            return false;

        // 代价大
        //  if(_table.size()==0 || 10*_size/_table.size()>=7) //扩容
        //  {
        //      size_t newSize = _table.size() ==0?10:_table.size();
        //      vector<HashData<K,V>> newTables;
        //      newTables.resize(newSize);
        //      //旧表的数据映射到新表 移动到信标要重新走一次探测

        // }
        if (_tables.size() == 0 || 10 * _size / _tables.size() >= 7)
        {
            size_t newSize = _tables.size() == 0 ? 10 : _tables.size()*2;
            HashTable<K, V> newHT;
            newHT._tables.resize(newSize);
            for (auto e : _tables)
            {
                if (e._state == EXIST)
                {
                    newHT.Insert(e._kv);
                }
            }
            _tables.swap(newHT._tables);
        }

        Hash hash;
        size_t hashi = hash(kv.first) % _tables.size();
        // 线性探测
        while (_tables[hashi]._state == EXIST)
        {
            hashi++;
            hashi %= _tables.size();
        }
        _tables[hashi]._kv = kv;
        _tables[hashi]._state = EXIST;
        ++_size;
    }

    HashData<K, V> *Find(const K &key)
    {
        if (_tables.size() == 0)
            return nullptr;
        Hash hash;
        size_t hashi = hash(key) % _tables.size();
        while (_tables[hashi]._state != EMPTY)
        {
            if (_tables[hashi]._state != DELETE && _tables[hashi]._kv.first == key)
            {
                return &_tables[hashi];
            }
            hashi++;
            hashi %= _tables.size();
        }
        return nullptr;
    }

    bool Erase(const K &key)
    {
        HashData<K, V> *ret = Find(key);
        if (ret)
        {
            ret->_state = DELETE;
            --_size;
            return true;
        }
        return false;
    }

    void Print()
    {
        for (size_t i = 0; i < _tables.size(); i++)
        {
            /* code */
            if (_tables[i]._state == EXIST)
            {
                cout << _tables[i]._kv.first << ' ';
            }
            else
            {
                cout << -1 << ' ';
            }
        }
        cout << endl;
    }
};

void TestHt1()
{
    int a[] = {1, 11, 4, 15, 26, 7, 44, 9};
    HashTable<int, int, HashFunc<int>> ht;
    for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        /* code */
        ht.Insert(make_pair(a[i], a[i]));
    }
    ht.Print();
    ht.Erase(4);
    cout << ht.Find(44) << endl;
    cout << ht.Find(4) << endl;
    ht.Print();
}

namespace HashBucket
{

    template <class K, class V>
    struct HashNode
    {
        pair<K, V> _kv;
        HashNode<K, V> *_next;
        /* data */
        HashNode(const pair<K,V> &kv)
        :_kv(kv)
        ,_next(nullptr)
        {}
    };

    template <class K, class V, class Hash = HashFunc<K>>
    class HashTable
    {
        typedef HashNode<K, V> Node;

    public:
        ~HashTable()
        {
            for(size_t i=0;i<_tables.size();++i)
            {
                Node* cur = _tables.size();
                while (cur)
                {
                    Node* next = cur->next;
                    free(cur);
                    cur = next;
                    /* code */
                }
                _tables[i] = nullptr;
                
            }
        }


        bool Insert(const pair<K, V> &kv)
        {
            // 去重
            if (Find(kv.first))
            return false;


            // 扩容负载因子到1
            if (_size == _tables.size())
            {
                size_t newSize = _tables.size() == 0 ? 10 : _tables.size()*2;
                vector<Node*> newTables;
                newTables.resize(newSize,nullptr);
                //旧表节点移动映射新表
                for (size_t i=0;i<_tables.size();i++)
                {
                    Node* cur = _tables[i];
                    while (cur)
                    {
                        Node* next = cur->_next;
                        size_t hashi = cur->_kv.first % newTables.size();
                        cur->_next = newTables[hashi];
                        newTables[hashi] = cur;
                        cur = next;
                    }
                    _tables[i] = nullptr;
                    
                }
                _tables.swap(newTables);
            }

            size_t hashi = kv.first % _tables.size();
            // 头插
            Node *newnode = new Node(kv);
            newnode->_next = _tables[hashi];
            _tables[hashi] = newnode;
            ++_size;

            return true;
        }

        Node *Find(const K &key)
        {
            if(_tables.size()==0) return nullptr;

            size_t hashi = key% _tables.size();
            Node *cur = _tables[hashi];

            while (cur)
            {
                if (_tables.size() == 0)
                    return nullptr;

                if (cur->_kv.first == key)
                {
                    return cur;
                }
                else
                    cur = cur->_next;
                /* code */
            }

            return nullptr;
        }

    private:
        vector<Node *> _tables;
        size_t _size=0;
    };

}

void TestHt2()
{
    int a[] = {1, 11, 4, 15, 26, 7, 44, 9,2,3,4,6,8,10,11};
    HashBucket::HashTable<int, int> ht;
    for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        /* code */
        ht.Insert(make_pair(a[i], a[i]));
    }

    cout << ht.Find(44) << endl;
    cout << ht.Find(4) << endl;
    cout << ht.Find(1) << endl;


}


int main()
{
    TestHt2();
}