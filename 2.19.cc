#include<iostream>
#include<queue>
#include<functional>
#include<assert.h>
#include<stdio.h>
#include<unistd.h>
using namespace std;

namespace bit
{
    template<class T>
    struct Less
    {
        /* data */
        bool operator()(const int& x,const int& y)
        {
            return x < y;
        }
    };

    template<class T>
    struct Greater
    {
        /* data */
        bool operator()(const int& x,const int& y)
        {
            return x > y;
        }
    };




    template<class T,class Container = vector<T>, class Compare =Less<T>>
    class priority_queue
    {
        public:
        priority_queue(){}

        template<class InputIterator>
        priority_queue(InputIterator first, InputIterator last)
        :_con(first,last)
        {
            for(int i = (_con.size()-2)/2; i >=0; --i)
            {
                adjust_down(i);
            }

        }
        

        void push(const T& x)
        {
            _con.push_back(x);
            adjustup(_con.size()-1);
        }

        void pop()
        {
            assert(!_con.empty());
            swap(_con[0],_con[_con.size()-1]);
            _con.pop_back();
            adjust_down(0);
        }

        

        const T& top()
        {
            return _con[0];
        }

        bool empty()
        {
            return _con.empty();
        }

        size_t size()
        {
            return _con.size();
        }


        private:
        Container _con;
        Compare com;
        void adjustup(size_t child)
        {
            size_t parent = (child-1)/2;
            while(child > 0)
            {
                if( com(_con[parent], _con[child]))
                {
                    swap(_con[child],_con[parent]);
                    child = parent;
                    parent = (child - 1)/2;
                }

                else
                {
                    break;
                }
            }

        } 
        
        void adjust_down(size_t parent)
        {
            size_t child = parent*2 +1;
            while(child < _con.size())
            {
                if(child+1 <_con.size() &&  com(_con[child],_con[child+1]))
                {
                    ++child;
                }

                if(com(_con[parent],_con[child]))
                {
                    swap(_con[child], _con[parent]);
                    parent = child;
                    child = parent*2 +1 ;
                }
                else break;
            }
        }
        
    };

    
    


}






void test_priority_queue()
{
    bit::priority_queue<int,vector<int>, bit::Greater<int>> pq;
    pq.push(3);
    pq.push(2);
    pq.push(8);
    pq.push(9);
    pq.push(1);
    
    while(!pq.empty())
    {
        cout<<pq.top()<<"  ";
        pq.pop();
    }
    cout<<endl;

}

void test_priority_queue2()
{
    priority_queue<int> pq;
    pq.push(3);
    pq.push(2);
    pq.push(8);
    pq.push(9);
    pq.push(1);
    while(!pq.empty())
    {
        cout<<pq.top()<<"  ";
        pq.pop();
    }
    cout<<endl;

}





template<class Compear = bit::Less<int>>
void maoapo_01(vector<int>& v)
{
    Compear _com;
    for(int i=0;i<v.size();i++)
    {
        for(int j =0; j<v.size()-i-1;j++)
        {
            if(_com(v[j],v[j+1]))
            {
                swap(v[j],v[j+1]);
            }
        }
    }

} 

void test01()
{
    vector<int> v = {5,2,4,9,1,3,18,0,-8,100};
    maoapo_01<bit::Greater<int>>(v);

    vector<int>::iterator it = v.begin();
    while(it!=v.end())
    {
        cout<<*it<<"  ";
        it++;
    }
    cout<<endl;
    
}




int main()
{
    // test_priority_queue2();
    // printf("hellow\n");
    // sleep(5);

    test01();
    return 0;
}