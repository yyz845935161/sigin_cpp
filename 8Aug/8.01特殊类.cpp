#include<iostream>
#include <mutex>
using namespace std;


//单例对象释放问题
//1、一般情况不用释放
//、程序结束会自己释放
//2

//饿汉模式 没有线程安全
class SingletonE
{

    public:
    static SingletonE& GetInstance()
    {
        return s;
    }


    private:
    // 构造函数私有化
    SingletonE(){}
    SingletonE(const SingletonE&)=delete;
    SingletonE& operator=(const SingletonE&)=delete;

    static SingletonE s;
    // static SingletonE* s;

};

SingletonE SingletonE::s;
// SingletonE* SingletonE::s = new SingletonE;


//懒汉模式
//缺点
//1、线程问题
//2、相对复杂
class SingletonL
{
    public:
    SingletonL* GetInstance()
    {
        if(nullptr == s)
        {
            _m.lock();
            if(nullptr == s)
            {
                s = new SingletonL;
            }
            _m.unlock();
        }

        return s;
    }

    private:
    SingletonL(){}
    SingletonL(const SingletonL&)=delete;
    SingletonL& operator=(const SingletonL&)=delete;

    static SingletonL* s;
    static mutex _m;
};

mutex SingletonL::_m;
SingletonL* SingletonL::s=nullptr;

int mian()
{

    SingletonE::GetInstance(); 
}