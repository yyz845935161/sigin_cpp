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

template <class T = int>
int MergeSort(vector<T> &v,int begin,int end)
{

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
    // QuickSort(v,0,v.size()-1);
    MyPrint(v);
}

