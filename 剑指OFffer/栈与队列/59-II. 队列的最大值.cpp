class MaxQueue {
public:
    queue<int> q;
    deque<int> max;

    MaxQueue() {

    }
    
    int max_value() {
        if(max.empty()) return -1;

        return *max.begin();
    }
    
    void push_back(int value) {
        q.push(value);
        if(max.empty()) 
        {
            max.push_back(value);
            return;
        }

        while(!max.empty() && *(--max.end()) < value)
        {
            max.pop_back();
        }
        max.push_back(value);

    }
    
    int pop_front() {
        if(!q.empty())
        {
            if(*max.begin() == q.front())
            {
                max.pop_front();
            }
            int temp = q.front();
            q.pop();
            return temp;
        }
        return -1;
        
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */