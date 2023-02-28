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

void BubbleSort(vector<int>& v)
{
    for (size_t j = 0; j < v.size()-1; j++)
    {
        /* code */
   
    
    for (size_t i = 0; i < v.size()-j; i++)
    {
        /* code */
        if(v[i] > v[i+1])
        {
            swap(v[i] ,v[i+1]);
        }
    }
     }
    
}


//hoare版本 错误版本
//这种写法会出错，当 [5 5 5 5 5] 死循环 [5,6,7,8,9] 越界
//[5 5 5 5 5] 死循环 v[right] > v[keyi] 用>=号
void Partion_err(vector<int>& v,int left,int right)
{
    int keyi = left;
    while(left < right)
    {
        //左边做key右边先走
        while (v[right] > v[keyi])
        {
            /* code */
            --right;
        }
        while (v[keyi] > v[left])
        {
            /* code */
            ++left;
        }
        swap(v[right],v[left]);
        
    }
    swap(v[keyi],v[left]);

    return;
}

//hoare正确版本 
int Partion(vector<int>& v,int left,int right)
{
    int keyi = left;
    while(left < right)
    {
        //左边做key右边先走
        while (left < right && v[right] >= v[keyi])
        {
            /* code */
            --right;
        }
        while (left < right && v[keyi] >= v[left])
        {
            /* code */
            ++left;
        }
        swap(v[right],v[left]);
        
    }
    swap(v[keyi],v[left]);

    return left;
}


//挖坑法 
int Partion2(vector<int>& v,int left,int right)
{
    int key = v[left];
    int hole = left;
    while (left<right)
    {
        /* code */
        while (left<right && v[right] >= key)
        {
            /* code */
            right--;
        }
        v[hole] = v[right];
        hole = right;

        while (left<right && v[left] <= key)
        {
            /* code */
            left++;
        }
        v[hole] = v[left];
        hole = left; 
    }
    v[hole] = key;
    

    return hole;
}


//前后指针 选最后一个做key
int Partion3(vector<int>& v,int left,int right)
{
    int cur = left;
    int pre = left-1;
    int key = v[right];
    while(cur  <= right)
    {
        while(cur  <= right && v[cur] >= key)
        {
            ++cur;
        } 

        if(cur  <= right) {
        swap(v[cur++],v[++pre]);
        }
    }
    swap(v[++pre],v[right]);
    return pre;

}

//前后指针 选第一个做key，且优化
int Partion4(vector<int>& v,int left,int right)
{
    int cur = left + 1;
    int pre = left;
    int keyi = left;
    while(cur  <= right)
    {
        if(v[cur] < v[keyi])
        {
            swap(v[cur],v[++pre]);
        }
        ++cur;
        
    }
    swap(v[pre],v[keyi]);
    return pre;

}



void QuickSort(vector<int>& v,int left,int right)
{
    if(left >=right)
    {
        return;
    }

    int keyi = Partion4(v,left,right);
    QuickSort(v,left,keyi-1);
    QuickSort(v,keyi+1,right);
}


//快排的非递归
void QuickSortNoneR(vector<int>& v,int left,int right)
 {
    stack<int> st; 
    st.push(left);
    st.push(right);
    while (!st.empty())
    {
        int end= st.top();
        st.pop();
        int begin = st.top();
        st.pop();
        int keyi =Partion(v,begin,end);


        if(keyi + 1 < end)
        {
            st.push(keyi+1);
            st.push(end);
        } 
        if(begin< keyi - 1 )
        {
            
            st.push(begin);
            st.push(keyi-1);
        }
    }
 }

void _MergeSort(vector<int>& v,int left,int right,vector<int>& temp)
{
    int mid = left + ((right-left)>>1);
    _MergeSort(v,left,mid,temp);
    _MergeSort(v,mid+1,right,temp);
    int begin1 = left,end1 = mid;
    int begin2 = mid+1,end2 = right;


}




void MergeSort(vector<int>& v)
{
    vector<int> temp;
    temp.reserve(v.size());
    _MergeSort(v,0,v.size()-1,temp);
}




void test01()
{
    vector<int> v = {8, 1,2,2, 4, 10,9, 7,7,7};
    printf_vec(v);

    // InserSort(v);
    // BubbleSort(v);
    // QuickSort(v,0,v.size()-1);
    QuickSortNoneR(v,0,v.size()-1);
    printf_vec(v);
}

int main()
{
    test01();
    return 0;
}