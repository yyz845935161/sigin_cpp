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

template<class T=int,class Com = Less<T>>
void SelectSort(vector<int>& v)
{
    Com _com;
    for(int i=0;i<v.size()/2;i++)
    {
        int mini = i;
        int maxi = i;
        int j=i;
        while(j<v.size()-i)
        {
            if(_com(v[j],v[mini]))
            {
                mini = j;
            }
            if(_com(v[maxi],v[j]))
            {
                maxi = j;
            }
            j++;

        }

        swap(v[mini],v[i]);
        if(maxi == i )
        {
            maxi = mini;
        }
        swap(v[maxi],v[v.size()-i-1]);
    }
}


template<class T=int,class Com = Less<T>>
void BullSort(vector<int>& v)
{
    Com _com;
    for(int j=0; j<v.size();j++)
    {
        for(int i=1;i<v.size()-j;i++)
    {
        if(_com(v[i],v[i-1]))
        {
            swap(v[i],v[i-1]);
        }
    }
    }
    

}


template<class T=int,class Com = Less<T>>
void _MergeSort(vector<int>& v,int begin,int end,vector<int>& temp)
{
    if(begin>=end)
    {
        return ;
    }

    int mid = (begin+end)/2;
    _MergeSort(v,begin,mid,temp);
    _MergeSort(v,mid+1,end,temp);

    //[begin,mid][mid+1 , end]

    Com _com;
    int start1 = begin, end1 = mid;
    int start2 = mid+1, end2 = end;
    int j = begin;
    while (start1<=end1 && start2 <= end2)
    {
        if(_com(v[start1],v[start2]))
        {
            temp[j++] = v[start1++];
        }
        else
        {
            temp[j++] = v[start2++];
        }
    }

    while (start1<=end1)
    {
        temp[j++] = v[start1++];
    }
    while (start2<=end2)
    {
       temp[j++] = v[start2++];
    }

    for(int i=begin;i<=end;i++)
    {
        v[i] = temp[i];
    }

}


template<class T=int,class Com = Less<T>>
void MergeSort(vector<int>& v)
{
    vector<int> temp(v.size());
    _MergeSort(v,0,v.size()-1,temp);

}
int main()
{
    // vector<int> v = {2,2,2};
    // vector<int> v = {2,2,2,2,1,1,1,6,6,6};
    // vector<int> v = {7,6,5,4,3,2,1};
    vector<int> v = {6,1,2,5,4,3,9,7,10,8,2,2,2};
    MyPrint(v);
    // QuickSort<int>(v,0,v.size()-1);
    // SelectSort(v);
    // BullSort(v);
    // InsertSort(v);
    MergeSort(v);
    MyPrint(v);
}

