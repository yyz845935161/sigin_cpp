class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        _v.push_back(x);
        if(x<mymin )
        {
            _min.push_back(x);
            mymin = x;
        }
        else
        {
            _min.push_back(mymin);
        }
        
        
    }
    
    void pop() {
        
        if(_v.size()>0)
        {
            _v.pop_back();
            _min.pop_back();
            if(_min.size()==0) mymin=INT_MAX;
            else
                mymin = min();
        }
        
    }
    
    int top() {
        return _v[_v.size()-1];

    }
    
    int min() {
        return _min[_min.size()-1];;
    }
    private:
    vector<int> _v;
    vector<int> _min;
    int mymin=INT_MAX;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */