#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include <stack>

void printf_vec(const vector<int> &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        /* code */
        cout << v[i] << " ";
    }
    cout << endl;
}

int _QuickSort(vector<int>& v,int left,int right)
{
    int key = v[right];
    int keyi = right;
    while (left<right)
    {
        while (v[left]<= key && left<right)
        {
            left++;
        }

        while (v[right]>= key && left<right)
        {
            right--;
        }

        swap(v[left],v[right]);
    }
    swap(v[keyi],v[right]);
    return left;
    
}


void QuickSort(vector<int>& v,int left,int right)
{


    if (left>=right)
    {
        return ;
    }
    int mid = _QuickSort(v,left,right);
    QuickSort(v,left,mid-1);
    QuickSort(v,mid+1,right);
}



void test01()
{
    vector<int> v = {8, 1,2,2, 4, 10,9, 7,7,7};
    printf_vec(v);
    QuickSort(v,0,v.size()-1);
    printf_vec(v);
}

int main()
{
    test01();
    return 0;
}