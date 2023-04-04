#include <iostream>
using namespace std;

bool is_run(int n)
{
    if ((n % 400 == 0) || (n % 4 == 0 && n % 100 != 0))
    {
        return true;
    }
    else
        return false;
}

int month_day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int month_money[] = {0, 2, 1, 1, 2, 1, 2, 1, 2, 2, 2, 1, 2};

int main()
{
    int b_y, b_m, b_d, e_y, e_m, e_d;
    while (cin >> b_y >> b_m >> b_d >> e_y >> e_m >>
           e_d)
    { // 注意 while 处理多个 case
        int money = 0;
        if (e_y - b_y > 1)
        {
            for (int y = b_y + 1; y < e_y; y++)
            {
                for (int i = 1; i <= 12; i++)
                {
                    money += month_day[i] * month_money[i];
                }
                if (is_run(y))
                    money += 1;
            }
        }

        if (e_y - b_y > 0)
        {
            for (int i = b_m + 1; i <= 12; i++)
            {
                if (is_run(b_y) && i == 2)
                {
                    money += (month_day[i] + 1) * month_money[i];
                }
                else
                    money += month_day[i] * month_money[i];
            }

            for (int i = 1; i <= e_m - 1; i++)
            {
                if (is_run(e_y) && i == 2)
                {
                    money += (month_day[i] + 1) * month_money[i];
                }
                else
                    money += month_day[i] * month_money[i];
            }
        }

        else if (e_y - b_y == 0 && e_m - b_m > 1)
        {
            for (int i = b_m + 1; i <= e_m; i++)
            {
                if (is_run(e_y) && i == 2)
                {
                    money += (month_day[i] + 1) * month_money[i];
                }
                else
                    money += month_day[i] * month_money[i];
            }
        }

        if (e_y > b_y || e_m > b_m)
        {
            if (is_run(b_y) &&
                b_m == 2)
                money += (month_money[b_m] * (month_day[b_m] - b_d + 1) + 1);
            else
                money += (month_money[b_m] * (month_day[b_m] - b_d + 1));
            
            if (is_run(e_y) &&
                e_m == 2)
                money += (month_money[e_m] *  e_d  + 1);
            else
                money += (month_money[e_m] * e_d );

        }
        else
        {
            money += (month_money[b_m] * (e_d - b_d + 1));
        }

        cout << money << endl;
    }
}
// 64 位输出请用 printf("%lld")