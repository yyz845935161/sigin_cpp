#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;


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


void QuickSort(vector<int>& v,int left,int right)
{
    if(left >=right)
    {
        return;
    }

    int keyi = Partion(v,left,right);
    QuickSort(v,left,keyi-1);
    QuickSort(v,keyi+1,right);
}





void test01()
{
    vector<int> v = {6, 5, 1, 3, 4, 9, 8, 10};
    printf_vec(v);

    // InserSort(v);
    // BubbleSort(v);
    QuickSort(v,0,v.size()-1);
    printf_vec(v);
}

int main()
{
    test01();
    return 0;
}