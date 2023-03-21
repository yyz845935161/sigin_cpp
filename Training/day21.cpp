// // 本题为考试多行输入输出规范示例，无需提交，不计分。
// #include <iostream>
// #include <vector>

// using namespace std;

// int main(){

//     int n;
//     cin>>n;
//     while(n--)
//     {
//     int num,k;
//     cin>>num>>k;
//     vector<int> v;
//     for(int i=0;i<2*num;i++)
//     {
//         int temp;
//         cin>>temp;
//         v.push_back(temp);
//     }

//     for(int i=0;i<k;i++)
//     {
//         vector<int> left(v.begin(),v.begin()+num);
//         vector<int> right(v.begin()+num,v.begin()+2*num);
//         v.clear();
//         for(int i=0;i<num;i++)
//         {
//             v.push_back(left[i]);
//             v.push_back(right[i]);
//         }
//     }

//     for(int i=0;i<v.size();i++)
//     {
//         cout<<v[i]<<' ';
//     }
//         cout<<endl;
//     }

//     return 0;
// }

// 本题为考试多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n;
    string s;
    cin >> n;
    cin >> s;
 
    int cur = 1;
    int left = 1;
    int right = (n < 4 ? n : 4);

    for (auto e : s)
    {
        if (n <= 4)
        {
            if (e == 'U')
            {
                if (cur-1 < 1)
                    cur = n;
                else
                    cur--;
            }
            else
            {
                if (cur+1 > n)
                    cur = 1;
                else
                    cur++;
            }
        }
        else
        {
            if (e == 'U')
            {
                if (cur-1 < 1)
                {
                    cur = n;
                    right = n;
                    left = n - 3;
                }
                else
                {
                    cur--;
                    if (cur < left)
                    {
                        left--;
                        right--;
                    }
                }
            }
            else
            {
                if (cur+1 > n)
                {
                    cur = 1;
                    left = 1;
                    right = 4;
                }
                else
                {
                    cur++;
                    if (cur > right)
                    {
                        left++;
                        right++;
                    }
                }
            }
        }
    }

    for (int i = left; i <= right; i++)
    {
        cout << i << ' ';
    }
    cout << endl;
    cout << cur;

    return 0;
}