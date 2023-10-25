#include<iostream>
#include <thread>
#include<mutex>
using namespace std;

namespace bit
{
    template<class T>
    class UniquePtr
    {
    private:
        /* data */
        T* _ptr;
    public:
        UniquePtr(T* ptr = nullptr):
        _ptr(ptr)
        {}

        UniquePtr(const UniquePtr<T>& ptr) = delete;

        UniquePtr<T>& operator=(const UniquePtr<T>& ptr) = delete;

        T& operator*()
        {
            return *_ptr;
        }

        T* operator->()
        {
            return _ptr;
        } 

        ~UniquePtr()
        {
            if(_ptr)
            {
                delete _ptr;
            }
        }
    };


    template<class T>
    class SharePtr
    {
    private:
        /* data */
        T* _ptr = nullptr;
        int* _count = nullptr;
        std::mutex* m = nullptr; 
    public:

    SharePtr(T* ptr):
    _ptr(ptr),
    _count(new int(1)),
    _m(new std::mutex){}

    SharePtr(const SharePtr<T>& sp):
    _ptr(sp._ptr),
    _count(sp._count),
    _m(sp.m)
    {
        m->lock();
            (*_count)++;
        m->unlock();
    }



    T& operator*()
    {
        return *_ptr;
    }

    T* operator->()
    {
        return _ptr;
    }


    ~SharePtr()
    {
        m->lock();
        if(--(*cout) == 0 && _ptr)
        {
            delete ptr;
            delete _count;
            delete _m;
            return;
        }
        m->unlock();
    }


    };
    



};


int main()
{
    int* a = new int(10);
    bit::UniquePtr<int> smart(a);
    cout<<*a<<endl;


    return 0;
}