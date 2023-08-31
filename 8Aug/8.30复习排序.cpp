#include<iostream>
#include<vector>

using namespace std;



template <class T =int>
struct Less
{
    /* data */
    bool operator()(const T& a,const T& b)
    {
        return a<=b;
    }
};





template <class T =int , class Com = Less<T>>
void QuickSort(vector<int>& v,int begin,int end)
{
    if(begin >= end)
    {
        return ;
    }


    int keyi = begin;
    int left = begin;
    int right = end;
    static Com _com;
    while(left<right)
    {

        
        while (_com(v[keyi],v[right]) && left<right)
        {
            right--;
        }
        
        while (_com(v[left],v[keyi]) && left<right)
        {
            left++;
        }
        swap(v[left],v[right]);
    }

    swap(v[keyi],v[left]);
    int mid = left;
    QuickSort(v,begin,mid-1);
    QuickSort(v,mid+1,end);

}


void MyPrint(const vector<int>& v)
{
    for (auto& e:v)
    {
        /* code */
        cout<<e<<" ";
    }
    cout<<endl;
}



template <class T =int , class Com = Less<T>>
void MergeSort(vector<int>& v,int begin,int end)
{
    if(begin>=end) return;

    static vector<int> temp(v.size());
    Com _com;
    int mid = (begin+end)/2;
    MergeSort(v,begin,mid);
    MergeSort(v,mid+1,end);

    int start1 = begin,end1 = mid;
    int start2 = mid+1, end2 = end;

    int i = begin;
    while(start1<=end1 && start2<=end2 )
    {
        if(_com(v[start1],v[start2]))
        {
            temp[i++] = v[start1++];
        }
        else
        {
            temp[i++] = v[start2++];
        }
    }
    while(start1<=end1)
    {
        temp[i++] = v[start1++];
    }
    while(start2<=end2)
    {
        temp[i++] = v[start2++];
    }

    for(int j=begin;j<=end;j++)
    {
        v[j] = temp[j];
    }

}




int  main()
{
    // vector<int> v = {6,1,2,5,4,3,9,7,10,8};
    // vector<int> v = {1,3,5,7,9,2,4,6,8,10};
    vector<int> v = {2,2,2,2,2,1};
    MyPrint(v);
    // QuickSort(v,0,v.size()-1);
    MergeSort(v,0,v.size()-1);
    MyPrint(v);

    return 0;
}