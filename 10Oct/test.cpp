#include <iostream>
#include<vector>
#include<queue>

using namespace std;


struct Task
{
    int id;
    int t,p;
};


struct Less
{
    bool operator()(const Task& a, const Task& b)
    {
        return a.p <= b.p;
    }
};




vector<vector<int>> ProcessTime(vector<Task> tasks)
{

}



int main()
{

}

