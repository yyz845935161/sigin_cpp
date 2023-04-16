// 原理
// template <class T>
// class SmartPtr
// {
// public:
//     SmartPtr(T *ptr = nullptr)
//         : _ptr(ptr)
//     {
//     }
//     ~SmartPtr()
//     {
//         if (_ptr)
//             delete _ptr;
//     }
//     T &operator*() { return *_ptr; }
//     T *operator->() { return _ptr; }

// private:
//     T *_ptr;
// };
#include <iostream>
#include <vector>

#include <memory>
class A
{
private:
    /* data */

public:
    A(/* args */);
    ~A();
    int _a1;
    int _a2;
};

A::A(/* args */)
{
}

A::~A()
{
}

namespace bit
{

    template <class T>
    class unique_ptr
    {
    public:
        unique_ptr(T *ptr = nullptr)
            : _ptr(ptr)
        {
        }

        unique_ptr(const unique_ptr<T> &u) = delete;
        unique_ptr<T> operator=(const unique_ptr<T> &u) = delete;

        ~unique_ptr()
        {
            if (_ptr)
                delete _ptr;
        }

        T *operator->()
        {
            return _ptr;
        }

        T &operator*()
        {
            return *_ptr;
        }

    private:
        T _ptr;
    };

    template <class T>
    class shared_ptr
    {
    public:
        shared_ptr(T *ptr = nullptr)
            : _ptr(ptr), _pCount(new int(1))
        {
        }

        void release()
        {
        
            if (--(*_pCount) == 0)
            {
                std::cout << "Delete: " << _ptr << std::endl;
                delete _pCount;
                delete _ptr;
            }
        }


        ~shared_ptr()
        {
            // if (--_count==0 && _ptr)
            release();
            
        }

        shared_ptr(shared_ptr<T> &sp)
            : _ptr(sp._ptr), _pCount(sp._pCount)
        {
            (*_pCount)++;
        }

        shared_ptr<T>& operator=(const shared_ptr<T>& sp)
        { 
        
            //这种方法会存在内存泄漏
            //因为当前this指针也有内容
            // _pCount=sp._pCount;
            // _ptr = sp._ptr;
            // (*_pCount)++;
            // return *this;

            //防止自己给自己赋值出错
            if(sp._ptr==this->_ptr)
            {
                return *this;
            }
            release();

            _pCount=sp._pCount;
            _ptr = sp._ptr;
            (*_pCount)++;
            return *this;
        }

        T *operator->()
        {
            return _ptr;
        }

        T &operator*()
        {
            return *_ptr;
        }

    private:
        T *_ptr;
        // static int _count; //引用技计数，如果调用了多个类来管理，就会出问题
        int *_pCount;
    };

    // template<class T>//引用技计数，如果调用了多个类来管理，就会出问题
    // int shared_ptr<T>::_count = 0;//引用技计数，如果调用了多个类来管理，就会出问题

}

void test_shared_ptr()
{

    bit::shared_ptr<A> sp1(new A);
    bit::shared_ptr<A> sp2(sp1);
    bit::shared_ptr<A> sp3(sp1);

    sp1->_a1++;
    sp1->_a2++;

    std::cout << sp2->_a1 << "  :  " << sp2->_a2 << std::endl;

    sp2->_a1++;
    sp2->_a2++;

    std::cout << sp1->_a1 << "  :  " << sp1->_a2 << std::endl;
}

struct Node
{
    int _val;
    // std::shared_ptr<Node> _next; //这样写如果是循环引用，就会互相卡着资源 都不释放，因为计数器一直不为0
    // std::shared_ptr<Node> _prev; //
    /* data */

    std::weak_ptr<Node> _next; //这样就可以解决循环引用
    std::weak_ptr<Node> _prev; //
    
    ~Node()
    {
        std::cout<<"~Node"<<std::endl;
    }
};




//循环引用
void test_shared_ptr2()
{
    std::shared_ptr<Node> n1(new Node);
    std::shared_ptr<Node> n2(new Node);
    n1->_next = n2;
    n2->_next = n1;
}

int main()
{
    test_shared_ptr();
    return 0;
}