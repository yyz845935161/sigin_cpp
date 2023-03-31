
#include <iostream>
#include <vector>
#include <set>
using namespace std;


class Solution {
public:
	/**
	 *	正数数组中的最小不可组成和
	 *	输入：正数数组arr
	 *	返回：正数数组中的最小不可组成和
	 */
    void dlfind(set<int>& v,const vector<int>& arr,int i,int &temp)
    {
        if(i>=arr.size()) 
        {
            v.insert(temp);
            return;
        }
        

        for (size_t j = i; j < arr.size(); j++)
        {
            temp+= arr[j];
            v.insert(temp);
            dlfind(v,arr,j+1,temp);
            temp-= arr[j];
        }
        
        
    }
    
	int getFirstUnFormedNum(vector<int> arr, int len) {
        set<int> v;
        int temp=0;

        dlfind(v,arr,0,temp);
        set<int>::iterator it = v.end();
        cout<<*v.begin()<<' '<<*(--it)<<endl;
        
        return 0;
    }
};

int main()
{
    vector<int> v ={3,2,5};
    Solution a;
    a.getFirstUnFormedNum(v,3);
    
}