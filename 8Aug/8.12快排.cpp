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


//hoare版本
template <class T = int, class Com = Less<T>>
void QuickSort(vector<T> &v,int begin,int end)
{
    if(begin>=end)
    {
        return;
    }

    Com _com;
    int left=begin;
    int keyi=left;
    int right=end;
    while (left<right)
    {
        while (left<right &&_com(v[keyi],v[right]) )
        {
            right--;
        }
        while (left<right &&_com(v[left],v[keyi]))
        {
            left++;
            /* code */
        }
        swap(v[left],v[right]);
    }
    swap(v[left],v[keyi]);

    QuickSort(v,begin,left-1);
    QuickSort(v,left+1,end);
    // return left;
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
    // vector<int> v = {7,6,5,4,3,2,1};
    vector<int> v = {6,1,2,5,4,3,9,7,10,8};
    MyPrint(v);
    QuickSort(v,0,v.size()-1);
    MyPrint(v);
}

