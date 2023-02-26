#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
// 插入排序
void InserSort(vector<int> &v)
{

    for (int i = 0; i < v.size() - 1; i++)
    {
        int end = i;
        int x = v[end + 1];
        while (end >= 0)
        {
            /* code */
            if (v[end] > x)
            {
                v[end + 1] = v[end];
                --end;
            }
            else
            {
                break;
            }
        }
        v[end + 1] = x;
    }
}

void printf_vec(const vector<int> &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        /* code */
        cout << v[i] << " ";
    }
    cout << endl;
}

// 希尔排序
void ShellSort(vector<int> &v)
{
    // 按gap分组数据进行预排序
    //gap越大，预排越快
    //gap越小，预排越慢
    int gap = 3;
    for(int j =0;j<gap;++j)
    {

    for (int i = 0; i < v.size() - gap; i+=gap)
    {
        int end = i;
        int x = v[end + gap];
        while (end >= 0)
        {
            /* code */
            if (v[end] > x)
            {
                v[end + gap] = v[end];
                end -= gap;
            }
            else
            {
                break;
            }
        }
        v[end + gap] = x;
    }
    }
}

void test01()
{
    vector<int> v = {6, 5, 1, 3, 4, 9, 8, 10};
    printf_vec(v);

    InserSort(v);
    printf_vec(v);
}

int main()
{
    test01();
    return 0;
}