class Solution {
public:
    int translateNum(int num) {
        if(num <= 9) return 1;
        if(num<= 25) return 2;
        if(num<=99) return 1; 

        string s = to_string(num);
        vector<int> v(s.size());
        v[0] = 1;
        if( s[0] >='3' || (s[0] =='2' && s[1] > '5')  ||s[0] =='0'  )
        {
            v[1] = 1;
        }
        else
        {
            v[1] = 2;
        }

        for(int i=2;i<s.size();i++)
        {
            if( s[i-1] >='3' || (s[i-1] =='2' && s[i] > '5')  || s[i-1] =='0' )
            {
                v[i] = v[i-1];
            }
            else
            {
                v[i] = v[i-1]+v[i-2];
            }

        }

        return v[s.size()-1];



    }
};