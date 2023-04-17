#include <iostream>
#include <vector>
using namespace std;

// 只能在堆上创建类
class HeapOnly
{

public:
    static void Delete(HeapOnly *p)
    {
        delete p;
    }

private:
    // 析构函数私有
    ~HeapOnly()
    {
        cout << "HeapOnly已经析构了" << endl;
    }

private:
    int _a;
};

// 只能在堆上创建类
class StackOnly
{
public:
    static StackOnly CreateObj()
    {
        StackOnly st;
        return st;
    }
    void *operator new(size_t i) = delete;

private:
    StackOnly()
        : _a(0)
    {
    }
    int _a;
};

// 单例模式 恶汉模式 --
class Singalton
{
public:
    static Singalton* GetInstanc()
    {
        return _inst;
    }

    void* Alloc(size_t n)
    {
        void* ptr = nullptr;
        return ptr;
    }

    void* Dealloc(void* ptr)
    {

    }
private:
    Singalton()
    {}
    char *_ptr = nullptr;
    static Singalton* _inst; //声明
};

Singalton* Singalton::_inst = new Singalton;



//懒汉模式
class SingaltonE
{
private:
    /* data */
    SingaltonE(/* args */);
    static SingaltonE* _pinst;
public:

    static SingaltonE* GetInstance()
    {
        if(_pinst == nullptr)_pinst = new SingaltonE;
        return _pinst;
    }
};

SingaltonE* SingaltonE::_pinst = nullptr;




int main()
{


    return 0;
}