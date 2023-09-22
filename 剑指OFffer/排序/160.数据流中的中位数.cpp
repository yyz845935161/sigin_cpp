template<class T>
struct Less
{
    bool operator()(const T& a, const T& b) const
    {
        return a<=b;
    }
};


class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int>> pri_s;
    priority_queue<int, vector<int>, less<int>> pri_l;
    int _size;

    MedianFinder() {
        _size = 0;
    }
    
    void addNum(int num) {
        if(pri_l.size()!= pri_s.size())
        {
            pri_s.push(num);
            pri_l.push(pri_s.top());
            pri_s.pop();

        }
        else
        {
            pri_l.push(num);
            pri_s.push(pri_l.top());
            pri_l.pop();
        }
    }
    
    double findMedian() {
        if(pri_l.size() != pri_s.size())
        {
            return pri_s.top()*1.0;
        }
        else
        {
            return (pri_s.top() + pri_l.top())/2.0 ;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */