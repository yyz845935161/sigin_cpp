#include <iostream>
using namespace std;
#include <string>
#include <vector>
enum State
{
    EMPTY,
    EXIST,
    DELETE
};


template<class K, class V>
class HashData
{
    pair<K,V> _kv;
    State _state;
    HashData(kv)
    :_kv(kv),
    _state(EXIST)
    {}
};



template<class K, class V>
class HashTable
{
private:
    vector<HashData<K,V>> _tables;
    size_t _size=0;
    /* data */
public:
    bool Insert(pari<K,V> kv)
    {
        //代价大
        // if(_table.size()==0 || 10*_size/_table.size()>=7) //扩容
        // {
        //     size_t newSize = _table.size() ==0?10:_table.size();
        //     vector<HashData<K,V>> newTables;
        //     newTables.resize(newSize);
        //     //旧表的数据映射到新表 移动到信标要重新走一次探测
            
        // }
        if(_table.size()==0 || 10*_size/_table.size()>=7){
            size_t newSize = _tables.size() ==0?10:_table.size();
            HashTable<K,V> newHT;
            newHT.resize(newSize);
            for(auto e:_tables)
            {
                if(e._state==EXIST)
                {
                    newHT.Insert(e._kv);
                }
                _tables.swap(newHT._tables);
            }
        }



        size_t hashi = kv.first%_tables.size();
        //线性探测
        while(_table[hashi]._state == EXIST)
        {
            hashi++;
            hashi%= _tables.size();
        }
        _tables[hashi]._kv = kv;
        _tables[hashi]._sate = EXIST;
        ++size();


    }


    HashTable(/* args */);
    ~HashTable();
};
