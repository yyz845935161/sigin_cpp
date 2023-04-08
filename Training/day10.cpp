
// #include<iostream>
// #include <vector>

// class Board {
//   public:

//     bool checkWon(vector<vector<int>> board) {
//         // write code here
//         int row = board.size();

//         int temp=0;
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < row; j++) {
//                 temp+=board[i][j];
//             }
//             if((temp) == row) return true;
//             else temp=0;
//         }

//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < row; j++) {
//                 temp+=board[j][i];
//             }
//             if((temp) == row) return true;
//             else temp=0;
//         }

//         for(int i=0;i<row;i++)
//         {
//             temp+=board[i][i];
//         }
//         if((temp) == row) return true;
//             else temp=0;
        
//         for(int i=0;i<row;i++)
//         {
//             temp+=board[i][row-i];
//         }
//         if((temp) == row) return true;
//             else temp=0;

//         return false;



//     }
// };

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    while (cin >> s) { // 注意 while 处理多个 case
        int scour = 0;
        int is_digital = 0;
        bool is_higharpha = false;
        bool is_lowarpha = false;
        int is_char = 0;

        for (auto& e : s) {
            if (e <= '9' && e >= '0') is_digital++;
            if (e <= 'Z' && e >= 'A') is_higharpha = true;
            if (e <= 'z' && e >= 'a') is_lowarpha = true;
            if ((e <= 0x2F && e >= 0x21) || (e <= 0x40 && e >= 0x3A) || (e <= 0x60 &&
                    e >= 0x5B) || (e <= 0x7E && e >= 0x7B)) is_char++;

        }

        if (s.size() <= 4) scour += 5;
        else if (s.size() >= 8) scour += 25;
        else scour += 10;

        if (is_higharpha && is_lowarpha) scour += 20;
        else if (is_higharpha || is_lowarpha) scour += 10;

        if (is_digital > 1) scour += 20;
        else if (is_digital == 1) scour += 10;

        if (is_char > 1) scour += 25;
        else if (is_char == 1) scour += 10;

        if (is_higharpha && is_lowarpha && is_char && is_digital)scour += 5;
        else if ((is_higharpha || is_lowarpha) && is_char && is_digital)scour += 3;
        else if ((is_higharpha || is_lowarpha) && is_digital) scour += 2;

        if (scour >= 90)cout << "VERY_SECURE" << endl;
        else if (scour >= 80)cout << "SECURE" << endl;
        else if (scour >= 70)cout << "VERY_STRONG" << endl;
        else if (scour >= 60)cout << "STRONG" << endl;
        else if (scour >= 50)cout << "AVERAGE" << endl;
        else if (scour >= 25)cout << "WEAK" << endl;
        else if (scour >= 0)cout << "VERY_WEAK" << endl;

    }
}
// 64 位输出请用 printf("%lld")
// 64 位输出请用 printf("%lld")