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



template<class T>
void MyPrint(vector<T> v)
{
    for(auto& e:v)
    {
        cout<<e<<" ";
    }
    cout<<endl;
}


template<class T=int,class Com = Less<T>>
void QuickSort(vector<int>& v,int begin,int end)
{
    if(begin>=end)
    {
        return;
    }

    Com _com;
    int left = begin;
    int right = end;
    int keyi = left;

    while (left<right)
    {
        while (left<right &&_com(v[keyi],v[right]))
        {
            /* code */
            right--;
        }
        while (left<right && _com(v[left],v[keyi]))
        {
            left++;
        }
        swap(v[left],v[right]);
    }
    int mid = left;
    swap(v[mid],v[keyi]);

    QuickSort(v,0,mid-1);
    QuickSort(v,mid+1,end);
}


template<class T=int,class Com = Less<T>>
void InsertSort(vector<int>& v)
{
    Com _com;
    for(int i=1;i<v.size();i++)
    {
        int temp = v[i];
        int j=i-1;
        while (j>=0)
        {
            if(_com(temp,v[j]))
            {
                v[j+1] =v[j];
                j--;
            }
            else
            {
                // j--;
                break;
            }
            
        }
        v[j+1] = temp;
    }

}




int main()
{
    // vector<int> v = {2,2,2};
    // vector<int> v = {2,2,2,2,1,1,1,6,6,6};
    // vector<int> v = {7,6,5,4,3,2,1};
    int* a = (int*)malloc(sizeof(int)*10);
    a[0]=0;
    a[1]=1;
    vector<int> v = {6,1,2,5,4,3,9,7,10,8};
    MyPrint(v);
    // QuickSort<int>(v,0,v.size()-1);
    InsertSort(v);
    MyPrint(v);
}

