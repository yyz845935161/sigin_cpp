#include <iostream>
#include <vector>
using namespace std;
#include<set>
#include<unordered_set>
#include<bitset>

int main()
{
    int a = 10;
    int && r = 11;
    r = 99;
    int c = 11;
    cout<<c<<endl;
    return 0;
}