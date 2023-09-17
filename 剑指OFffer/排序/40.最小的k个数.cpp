template<class T>
struct Less
{
    bool operator()(const T& a,const T& b)
    {
        return a<=b;
    }
};



class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int>  ans;
        if(k==0) return ans;
        priority_queue<int,vector<int>,Less<int>> pq;
        
        for(int i = 0;i<k;i++)
        {
            pq.push(arr[i]);
        }
        
        for(int i=k;i<arr.size();i++)
        {
            if(pq.top() > arr[i])
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;


    }
};