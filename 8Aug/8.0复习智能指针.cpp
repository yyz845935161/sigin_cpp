#include<iostream>
using namespace std;

namespace smart
{
    template<class T>
    class unique_ptr
    {
        public:
        unique_ptr(T* ptr = nullptr)
        :_ptr(ptr)
        {}

        unique_ptr(const unique_ptr<T>& sp) =delete;
        unique_ptr<T>& operator=(const unique_ptr<T>& sp)=delete;

        T& operator*()
        {
            return *_ptr;
        }

        T* operator->()
        {
            return _ptr;
        }

        ~unique_ptr()
        {
            if(_ptr)
            {
                delete _ptr;
            }
        }

        private:
            T* _ptr;
    };

    template<class T>
    class share_ptr
    {
        public:
        share_ptr(T* ptr=nullptr)
        :_ptr(ptr),
        :_Count(new int(1))
        {}

        share_ptr(const share_ptr<T>& sp)
        :_ptr(sp._ptr),
        _Count(sp._Count)
        {
            (*_Count)++;
        }

        share_ptr<T>& operator=(const share_ptr<T>& sp)
        {

            if(_ptr == sp._ptr)
            {
                return *this;
            }

            if(--(*sp._Count)==0)
            {
                delete sp._ptr;
                delete sp._Count;
            }

            if(&sp != this)
            {
                _ptr = sp._ptr;
                _Count = sp._Count;
                ++(*_Count);
            }

            return *this;
        }


        T& operator*()
        {
            return *_ptr;
        }

        T* operator->()
        {
            return _ptr;
        }

        share_ptr()
        {
            if(--(*_Count)==0)
            {
                delete _ptr;
                delete _Count;
            }
        }
        private:
            T* _ptr;
            int * _Count;
    };

};




int main()
{
    smart::unique_ptr<int> ptr1(new int(10));
}