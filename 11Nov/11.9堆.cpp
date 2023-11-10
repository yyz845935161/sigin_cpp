#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

template<class T = int, class Com = less<T>>
class Heap
{
    Com _com;

public:
    Heap()= default;
    Heap(vector<T>& v):_v(v){};
    vector<T> _v;
    void Push(T val)
    {
        _v.push_back(val);
        AdjustUp(_v.size()-1);
    }

    void Print() const
    {
        for(auto& e:_v)
        {
            cout<<e<<" ";
        }
        cout<<endl;
    }


    void AdjustUp(int child)
    {
        int parent = (child-1)/2;
        while(child > 0)
        {
            if(_com(_v[child], _v[parent]))
            {
                swap(_v[child],_v[parent]);
                child = parent;
                parent = (child-1)/2;
            }
            else
            {
                break;
            }

        }
    }

    void AdjustDonw(int parent, int n)
    {
        int child = parent *2 + 1;
        while(child < n)
        {
            //选出左右孩子中小/大的那个
            if(child+1 < n && _com(_v[child+1],_v[child]))
            {
                ++child;
            }

            if(_com( _v[child], _v[parent]))
            {
                swap(_v[child], _v[parent] );
                parent = child;
                child = parent *2 + 1;
            }
            else
            {
                break;
            }
        }
    }

    void Pop()
    {
        assert(!_v.empty());
        swap(_v[0], _v[_v.size()-1]);
        _v.pop_back();
        AdjustDonw(0);

    }

    T Top()
    {
        assert(!_v.empty());
        // if(_v.empty) return -1;
        return _v[0];
    }
    bool empty()
    {
        return _v.empty();
    }
};

void HeapSort(vector<int>& v)
{
    Heap<int,greater<int>> hp(v);
    int n = v.size()-1;
    //建堆  向上调整
    // for(int i = 1; i < v.size(); i++)
    // {
    //     hp.AdjustUp(i);
    // }

    //建堆  向下调整
    for(int i = (n-1)/2; i >= 0 ; i--)
    {
        hp.AdjustDonw(i,n );
    }



    int end = v.size()-1;
    while(end > 0)  //循环  交换，向下调整
    {
        swap(hp._v[0],hp._v[end]);
        //再调整
        hp.AdjustDonw(0,end);
        --end;
    }



    hp.Print();
}




int main()
{

    // Heap<int,greater<int>> hp;
    // int a[] = {65,100,70,32,50,60};
    // for(int i = 0;i<sizeof(a)/sizeof(a[0]) ;i++)
    // {
    //     hp.Push(a[i]);
    // }
    // hp.Print();
    // while (!hp.empty())
    // {
    //     /* code */
    //     int top = hp.Top();
    //     printf("%d\n",top);
    //     hp.Pop();
    // }
    
    // hp.Print();

    vector<int> v = {65,100,70,32,50,60};
    HeapSort(v);
}