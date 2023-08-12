#include <iostream>
#include <vector>
using namespace std;

template <class T = int>
struct Less
{
    /* data */
    bool operator()(const T &a, const T &b)
    {
        return a < b;
    }
};

template <class T = int, class Com = Less<T>>
void BubbleSort(vector<T> &v)
{
    Com _com;

    for (int j = 0; j < v.size(); j++)
    {
        int exchange = 0;
        for (int i = 1; i < v.size()-i; i++)
        {
            if (_com(v[i], v[i - 1]))
            {
                swap(v[i - 1], v[i]);
                exchange=1;
            }
        }
        if(exchange==0)
        {
            break;
        }
    }
}

template<class T>
void MyPrint(vector<T> v)
{
    for(auto& e:v)
    {
        cout<<e<<" ";
    }
    cout<<endl;
}

int main()
{
    // vector<int> v = {5,8,2,3,6,7,10,2,2,2};
    // vector<int> v = {2,2,2,2,1,1,1,6,6,6};
    vector<int> v = {7,6,5,4,3,2,1};
    MyPrint(v);
    BubbleSort(v);
    MyPrint(v);
}

