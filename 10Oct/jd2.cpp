#include <iostream>
#include<vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    long long sum = 0;
    multiset<int> price;
    multimap<int,int,greater<int>> pcut;
    for(int i = 0; i<n;i++)
    {
        int a;
        cin>>a;
        price.insert(a);
        sum += a;
    }
    for(int i = 0;i<m ;i++)
    {
        int b,c;
        cin>>b>>c;
        pcut.insert({c,b});
    }

    for(auto& e:pcut)
    {
        int lowPrice =  e.first;
        int minMoney = e.second;

        auto it = price.lower_bound(minMoney);
        while(it != price.end())
        {
            sum-=lowPrice;
            price.erase(it);
            it = price.lower_bound(minMoney);
        }
    }
    cout<<sum<<endl;


}



/*
3 2
4 8 6
5 1
8 5

3 2
4 8 6
6 7
8 5

*/