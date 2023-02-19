#include<iostream>
#include<queue>
#include<functional>
using namespace std;








void test_priority_queue()
{
    priority_queue<int> pq;
    pq.push(3);
    pq.push(2);
    pq.push(8);
    pq.push(9);
    pq.push(1);
    while(!pq.empty())
    {
        cout<<pq.top()<<"  ";
        pq.pop();
    }
    cout<<endl;

}

int main()
{
    test_priority_queue();
    return 0;
}