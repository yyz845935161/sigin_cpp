#include <set>
#include <iostream>
#include <string>
#include <map>
using namespace std;
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>
void test01()
{
    set<int> s;
    s.insert(3);
    s.insert(1);
    s.insert(5);
    s.insert(2);
    s.insert(8);

    set<int>::iterator it = s.begin();
    while (/* condition */ it != s.end())
    {
        cout << *it << " ";
        ++it;
        /* code */
    }
    cout << endl;

    for (auto e : s)
    {
        cout << e << " ";
        /* code */
    }
    cout << endl;
}

void tese02()
{
    pair<string, int> a("苹果", 10);
    map<string, int> dict;
    dict.insert(a);
    dict.insert(pair<string, int>("香蕉", 7));
    dict.insert(make_pair("菠萝", 4));
    auto it = dict.begin();
    while (it != dict.end())
    {
        cout << (*it).first << ":" << (*it).second << endl;
        it++;
        /* code */
    }
    cout << endl;

    for (auto &a : dict)
    {
        cout << a.first << ":" << a.second << endl;
    }
}

class Solution
{
public:
    struct Greater
    {
        bool operator()(const pair<string, int> &a, const pair<string, int> &b)
        {
            return a.second > b.second;
        }
    };
    vector<string> topKFrequent(vector<string> &words, int k)
    {

        vector<string> ans;
        map<string, int> count;
        for (auto i : words)
        {
            count[i]++;
        }
        priority_queue<pair<string, int>, vector<pair<string, int>>, Greater> pq;

        for (auto i : count)
        {
            pq.push(i);
        }

        while (--k)
        {
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};

void tese03()
{
    vector<int> v = {5, 9, 7, 4, 6, 3, 2, 1};
    for (auto &i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    sort(v.begin(), v.end(), greater<int>());
    for (auto &i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

void test04()
{
    vector<string> v = {"i", "love", "leetcode", "i", "love", "coding"};
    Solution a;
    a.topKFrequent(v,2);
}

int main()
{
    // test01();
    // tese02();
    // tese03();
    test04();
    return 0;
}