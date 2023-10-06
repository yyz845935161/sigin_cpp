class Solution {
public:
    bool checkDynasty(vector<int>& place) {

        int min = 0;
        int max = 0;
        set<int> s;
        for(int i=0;i<place.size();i++)
        {
            if(place[i]!=0)
            {
                if(s.find(place[i]) !=s.end() ) return false;
                s.insert(place[i]);
            }
            
        }
        min = *s.begin();
        max = *(--s.end());
        cout<<min<<"::"<<max;
        if(max - min >= 5) return false;
        return true;

    }
};