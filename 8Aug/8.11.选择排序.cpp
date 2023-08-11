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

//希尔
// 1预排序
// 2直接插入排序
template <class T, class Com = Less<T>>
void SelectSort(vector<T> &v)
{
    Com _com;
    for (int i = 0; i < v.size(); i++)
    {
        int temp = i;
        for(int j=i+1;j<v.size();j++)
        {
            if(_com(v[j],v[temp]))
            {
                temp=j;
            }
        }
        swap(v[temp],v[i]);
    }
    
}

template <class T>
void MyPrint(vector<T> v)
{
    for (auto &e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}

int main()
{
    // vector<int> v = {5,8,2,3,6,7,10,2,2,2};
    vector<int> v = {9,1,2,5,7,4,8,6,3,5};
    // vector<int> v = {7, 6, 5, 4, 3, 2, 1};
    // vector<int> v={1,2,3,4,5,6};
    MyPrint(v);
    SelectSort(v);
    MyPrint(v);
}
