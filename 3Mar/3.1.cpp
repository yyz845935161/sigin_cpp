#include <assert.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

template<class T = int>
struct Less{
    bool operator()(const T& a,const T& b){
        return a<=b;
    }
};

template<class T = int>
struct Greater{
    bool operator()(const T& a,const T& b){
        return a>=b;
    }
};



template<class Com = Less<int>>
int Partion(vector<int>& v,int left,int right)
{
    Com  _com;
    int keyi = right;
    while(left < right)
    {
        while (left < right && _com(v[left],v[keyi]))
        {
            /* code */
            left++;
        }
        while (left < right &&_com(v[keyi],v[right]))
        {
            /* code */
            right--;
        }
        swap(v[left],v[right]);
    }
    swap(v[left],v[keyi]);
    return left;


}

template<class Com = Less<int>>
void quickSort(vector<int>& v,int left,int right)
{
  if(left >= right)
  {
    return;
  }

    int mid = Partion<Com>(v,left,right);
    quickSort<Com>(v,left,mid-1);
    quickSort<Com>(v,mid+1,right);

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

void test01()
{
    vector<int> v = {8, 1,2,2, 4, 10,9, 7,7,7};
    printf_vec(v);

    // InserSort(v);
    // BubbleSort(v);
    // QuickSort(v,0,v.size()-1);
    quickSort<Greater<int>>(v,0,v.size()-1);
    // quickSort(v,0,v.size()-1);
    printf_vec(v);
}

int main()
{
    test01();
    return 0;
}