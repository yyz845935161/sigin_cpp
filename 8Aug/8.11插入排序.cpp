#include <iostream>
#include<vector>
using namespace std;


template<class T=int>
struct Less
{
    /* data */
    bool operator()(const T& a,const T& b)
    {
        return a<b;
    }

};


//一坨大便
// template<class T,class com=Less<T>>
// void InsertSort(vector<T>& v)
// {
//     com _com;
//     for (size_t i = 1; i < v.size(); i++)
//     {
//         for(int j=0;j<i;j++)
//         {
//             if(_com(v[i],v[j]))
//             {
//                 continue;
//             }
//             else
//             {
//                 T temp = v[i];
//                 for(int m=0;m<i-j;m++)
//                 {
//                     v[i-m] = v[i-m-1];
//                 }
//                 v[j] = temp;
//                 break;
//             }
//         }
//     }
// }

//前面是有序的
template<class T,class Com = Less<T>>
void InsertSort(vector<T>& v)
{
    Com _com;
    for (int i = 1; i < v.size(); i++)
    {
        int temp=v[i];
        int j=0;
        for(j=0;j<i;j++)
        {
            if(_com(temp,v[i-j-1]))
            {
                swap(v[i-j],v[i-j-1]);
            }
            else
            {
                
                break;
            }
        }
        v[i-j]=temp;
    }
    
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
    vector<int> v = {7,6,5,4,3,2,1};
    MyPrint(v);
    InsertSort(v);
    MyPrint(v);
}




