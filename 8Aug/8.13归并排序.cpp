#include <iostream>
#include <vector>
using namespace std;

template <class T = int>
struct Less
{
    /* data */
    bool operator()(const T &a, const T &b)
    {
        return a <= b;
    }
};

template <class T = int, class Com = Less<T>>
void _MergeSort(vector<int> &v, int begin, int end, vector<int> &temp)
{
    if (begin >= end)
        return;

    int mid = (begin + end) / 2;
    _MergeSort(v, begin, mid, temp);
    _MergeSort(v, mid + 1, end, temp);

    //[begin , mid][mid+1, end]
    int begin1 = begin, end1 = mid;
    int begin2 = mid + 1, end2 = end;
    int j = begin;
    while (begin1 <= end1 && begin2 <= end2)
    {
        if (v[begin1] < v[begin2])
        {
            temp[j] = v[begin1++];
        }
        else
        {
            temp[j] = v[begin2++];
        }
        j++;
    }
    while (begin1 <= end1)
    {
        temp[j++] = v[begin1++];
    }
    while (begin2 <= end2)
    {
        temp[j++] = v[begin2++];
    }
    for (int i = begin; i <= end; i++)
    {
        v[i] = temp[i];
    }
}
vector<int> MergeSort(vector<int>& v) {
    vector<int> temp(v.size());
    _MergeSort(v,0,v.size()-1,temp);        
    return v;
}

vector<int> MergeSortNonR(vector<int>& v) {
    vector<int> temp(v.size());
    // _MergeSort(v,0,v.size()-1,temp);    

    int gap = 1;



    return v;
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
    // vector<int> v = {7,6,5,4,3,2,1};
    vector<int> v = {6, 1, 2, 5, 4, 3, 9, 7, 10, 8};
    MyPrint(v);
    // QuickSort(v,0,v.size()-1);
    MyPrint(v);
}
