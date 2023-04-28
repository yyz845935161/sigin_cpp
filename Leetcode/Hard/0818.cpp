#include <queue>
#include <iostream>
using namespace std;


using namespace std;
struct car
{
    int index;
    int step;
    int speed;
    car():
    step(0),
    speed(1){}

    car(int index,int step,int speed):
    index(index),
    step(step),
    speed(speed)
    {}
};

class Solution {
public:
    int racecar(int target) {
        queue<car> q;
        vector<car> v(target+1);
        v[1] = {0,0,1};
        q.push(v[1]);
        while(!q.empty())
        {
            car temp = q.front();
            q.pop();
            if(temp.index == target)return temp.step;

            car A = {temp.index+temp.speed,temp.step+1,temp.speed*2};
            car R = {temp.index,temp.step+1,(temp.speed>0?-1:1)};
            q.push(A);
            q.push(R);
        }
        return 0;
    }
};

int main()
{
    Solution s;
    s.racecar(6);
}