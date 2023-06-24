class Solution {
public:

    string add(const string& num1,const  string& num2)
    {
        
    }


    string multiply(string num1, string num2) {
        int n1s = num1.size();
        int n2s = num2.size();
        vector<int> v;

        for(int i=0;i<num1.size();i++)
        {
            int jin=0;
            int cur=0;
            for(int j=0;j<num2.size();j++)
            {
                // int temp = num1[n1s-1-i];
                int temp = (num1[n1s-1-i] - '0') * (num2[n2s-1-j] - '0') + jin;
                cur = cur + (jin%10)* pow(10,j);
                jin/=10;
            }
            if(jin !=0)
            {

            }
        }
    }
};