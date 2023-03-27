#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include <stack>

// #include <cmath>
// #include <complex>
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {

//     vector<int> v;
    


//     int a;
//     while (cin >> a) { // 注意 while 处理多个 case
//         v.push_back(0);
//         v.push_back(1);
//         for (int i=2; i<a+2; i++) {
//             v.push_back(v[i-1]+v[i-2]);
//             if(a <=v[i])
//             {
//                 cout<<min(abs(v[i-1] -a),abs(v[i]-a) );
//                 return 0;
//             }
//         }
//         v.clear();
//     }


//      return 0;   
//     }
// 64 位输出请用 printf("%lld")



void printf_vec(const vector<int> &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        /* code */
        cout << v[i] << " ";
    }
    cout << endl;
}

int _QuickSort(vector<int>& v,int left,int right)
{
    int key = v[right];
    int keyi = right;
    while (left<right)
    {
        while (v[left]<= key && left<right)
        {
            left++;
        }

        while (v[right]>= key && left<right)
        {
            right--;
        }

        swap(v[left],v[right]);
    }
    swap(v[keyi],v[right]);
    return left;
    
}


void QuickSort(vector<int>& v,int left,int right)
{


    if (left>=right)
    {
        return ;
    }
    int mid = _QuickSort(v,left,right);
    QuickSort(v,left,mid-1);
    QuickSort(v,mid+1,right);
}


class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        // write code here
        stack<char> st;

        for (auto e:A) {
        
            if(e == ')')
            {
                while (!st.empty() && st.top()!='(') {
                    st.pop();
                
                }
                if(st.empty()) return  false;
                else st.pop();
            }
            else st.push(e);
        }
        while (!st.empty()) {
            if(st.top()=='(') return false;
            st.pop();
        
        }
        return  true;
    }
};

void test01()
{
    vector<int> v = {8, 1,2,2, 4, 10,9, 7,7,7};
    printf_vec(v);
    QuickSort(v,0,v.size()-1);
    printf_vec(v);
}

int main()
{
    test01();
    return 0;
}