template <class T>
class SmartPtr
{
public:
    SmartPtr(T *ptr = nullptr)
        : _ptr(ptr)
    {
    }
    ~SmartPtr()
    {
        if (_ptr)
            delete _ptr;
    }
    T &operator*() { return *_ptr; }
    T *operator->() { return _ptr; }

private:
    T *_ptr;
};
