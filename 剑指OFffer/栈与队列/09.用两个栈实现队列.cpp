
//s1为入
//s2为出
//s1一直放就行，出列，s2为空就把s1中所有元素放进s2中
class CQueue {
public:
    stack<int> s1;
    stack<int> s2;
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if(s2.empty())
        {
            return -1;
        }
        int temp = s2.top();
        s2.pop();
        return temp;


    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */