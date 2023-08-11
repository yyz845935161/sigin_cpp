#include <iostream>

using namespace std;

// 1、 RAII
// 2、像指针一样
// 3、拷贝问题 --》很多解决方案
template <class T>
class SmartPtr
{
public:
    SmartPtr(T *ptr = nullptr) : _ptr(ptr)
    {
    }

    ~SmartPtr()
    {
        if (_ptr)
        {
            delete _ptr;
        }
    }

    T &operator*()
    {
        return *_ptr;
    }

    T *operator->()
    {
        return _ptr;
    }

private:
    T *_ptr;
};



namespace bit
{
    template<class T>
    class shared_ptr
    {
        shared_ptr(T* ptr=nullptr)
        :_ptr(ptr);
        _pCount(new int(1))
        {}

        ~shared_ptr()
        {
            Release();
        }

        void Release()
        {
            if(--(*_pCount)==0)
            {
                cout<<"Delete:"<<_ptr<<endl;
                delete _ptr;
                delete _pCount;
            }
        }

        shared_ptr(const shared_ptr<T>& sp)
        :_ptr(sp._ptr),
        _pCount(sp._pCount)
        {
            (*_pCount)++;
        }

        // 非常容易出错 原本sp的资源要考虑
        shared_ptr<T>& operator=(const shared_ptr<T>& sp)
        {
            //如果管理的是同一块资源
            if(_ptr == sp._ptr)
            {
                return *this;
            }

            //减减被赋值对象的计数，如果是最后一个，要释放资源
            // if(--(*_pCount) == 0)
            // {
            //     delete _ptr;
            //     delete _pCount;
            // }
            Release();
     
            _ptr = sp._ptr;
            _pCount = sp._pCount;
            (*_pCount)++;
            
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

        T* _ptr;
        int* _pCount;

        private:
            
    };


} // namespace bit

int main()
{
}