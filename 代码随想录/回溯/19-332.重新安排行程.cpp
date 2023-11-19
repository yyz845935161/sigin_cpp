
#include <iostream>
using namespace std;
#include <set>
#include <vector>
#include <string>
#include <unistd.h>



//过不了 时间爆了
class Solution {
public:
    vector<string> path;
    vector<string> result; 

    bool comPare(const vector<string>& a,const vector<string>& b)
    {
        for(int i = 0 ; i < a.size(); i++)
        {
            if(a[i] != b[i]) return a[i] < b[i]; 
        }
        return true;
    }

    void traceBack(vector<vector<string>>& tickets,vector<bool>& used , string begin = "")
    {
        if(path.size() == tickets.size()+1)
        {
            if(result.empty() || comPare(path, result)) result = path;
            return ;
        }

        for(int i = 0; i<tickets.size(); i++)
        {
            // string bein = tickets[i];
            if(used[i]) continue;
            if(path.empty() && tickets[i][0] == "JFK")
            {
                used[i] = true;
                begin = tickets[i][1];
                path.push_back(tickets[i][0]);
                path.push_back(tickets[i][1]);
                traceBack(tickets, used, begin);
                path.pop_back();
                path.pop_back();
                used[i] = false;;
            }
            else if( begin == tickets[i][0])
            {
                used[i] = true;
                path.push_back(tickets[i][1]);
                traceBack(tickets, used, tickets[i][1]);
                path.pop_back();   
                used[i] = false;             
            }




        }
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<bool> used(tickets.size(),false);
        traceBack(tickets, used);
        return result;

    }
};


int main()
{
    vector<vector<string>> v = {{"MUC","LHR"},{"LHR","ABC"}};
    Solution a;
    a.findItinerary(v);
    return 0;
}