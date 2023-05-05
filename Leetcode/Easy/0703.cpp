#include <vector>
#include <iostream>

#include <set>
using namespace std;



struct Great{
bool operator()(const int& a,const int &b) const
{
    return a>b;
}
};


class KthLargest {
public:
    multiset<int,Great> _s;
    int _k;
    KthLargest(int k, vector<int>& nums) {
        for(auto  e:nums)
        {
            _s.insert(e);
        }
        this->_k = k;
    }
    int add(int val) {
        _s.insert(val);
        multiset<int>::iterator it=_s.begin();
        for(int i=1;i<_k;i++)
        {
            it++;
        }
        return *it;
    }
};
