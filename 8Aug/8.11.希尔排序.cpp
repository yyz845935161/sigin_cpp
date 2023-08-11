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
void ShellSort(vector<T> &v)
{
    //
    Com _com;
    int gap = v.size();
    while (gap > 1)
    {
        gap = gap / 3 + 1; //gap>1是预排 =1是直接排
        for (int j = 0; j < gap; ++j)
        {
            for (int i = j; i < v.size() - gap; i += gap)
            {
                int end = i;
                int tmp = v[end + gap];
                while (end >= 0)
                {
                    if (_com(tmp, v[end]))
                    {
                        swap(v[end], v[end + gap]);
                        end -= gap;
                    }
                    else
                    {
                        break;
                    }
                }
                v[end+gap] = tmp;
            }
        }
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
    // vector<int> v = {2,2,2,2,1,1,1,6,6,6};
    vector<int> v = {7, 6, 5, 4, 3, 2, 1};
    MyPrint(v);
    ShellSort(v);
    MyPrint(v);
}
