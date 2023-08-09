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
    template <class T>
    class AutoPtr
    {
    public:
        AutoPtr(T *ptr = nullptr) : _ptr(ptr)
        {
        }

        ~AutoPtr()
        {
            if (_ptr)
            {
                delete _ptr;
            }
        }

        AutoPtr(AutoPtr<T> &ap)
            : _ptr(ap._ptr)
        {
            ap._ptr = nullptr;
        }

        AutoPtr<T> &operator=(AutoPtr<T> &ap)
        {
            if (this != &ap)
            {
                if (_ptr)
                {
                    delete _ptr;
                }
                _ptr = ap._ptr;
                ap._ptr = nullptr;
            }
            return *this
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

} // namespace bit

int main()
{
}