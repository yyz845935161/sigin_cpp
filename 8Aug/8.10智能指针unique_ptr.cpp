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
    class unique_Ptr
    {
    public:
        unique_Ptr(T *ptr = nullptr) : _ptr(ptr)
        {
        }

        ~unique_Ptr()
        {
            if (_ptr)
            {
                cout<<"~unique_Ptr delete"<<endl;
                delete _ptr;
            }
        }
        
        //防拷贝
        unique_Ptr(unique_Ptr<T> &ap) = delete;
        unique_Ptr<T> &operator=(unique_Ptr<T> &ap) = delete;


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