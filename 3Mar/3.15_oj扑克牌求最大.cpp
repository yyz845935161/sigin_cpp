#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<map>

map<string,int> pai ={{"3",1},{"4",2},{"5",3},{"6",4},{"7",5},{"7",6},{"9",7},{"10",8},{"J",9},{"Q",10},{"K",11},{"A",12},{"2",13}};


void printWin(char c,vector<string>& l,vector<string>& r)
{
    if(c=='l')
    {
        for(auto a:l)
        {
            cout<<a<<" ";
        }
    }
    else
    {
        for(auto a:r)
        {
            cout<<a<<" ";
        }
    }
}

bool King_zha(vector<string>& v)
{
    if(v.size()<2) 
        return false;
    if( (v[0]=="joker"&& v[1]=="JOKER") ||(v[1]=="joker"&& v[2]=="JOKER")) 
        return true;
    return false;
}



int main()
{
    string s;
    getline(cin, s);
    vector<string> l;
    vector<string> r;
    string temp;
    bool _l=true;
    for(auto e:s)
    {
        if(e==' ')
        {
            if(_l)l.push_back(temp);
            else r.push_back(temp);
            temp.clear();
        }
        else if(e=='-')
        {
            l.push_back(temp);
            temp.clear();
            _l=false;
        }
        else
        {
            temp+=e;
        }
    }
    r.push_back(temp);
    
    if(l.size()==2 && King_zha(l))
    {
        printWin('l',l,r);
        return 0;
    }
    else if (r.size()==2 && King_zha(r))
    {
        printWin('r',l,r);
        return 0;
    }
    
    if(l.size()==4 && r.size()!=4)
    {
        printWin('l',l,r);
        return 0;
    }
    if (r.size()==4 && l.size()!=4)
    {
        printWin('r',l,r);
        return 0;
    }
    if((r.size()==4 && l.size()==4) ||(r.size()==3 && l.size()==3)||(r.size()==2 && l.size()==2)||(r.size()==1 && l.size()==1)||(r.size()==5 && l.size()==5))
    {
        if( pai[r[0]]>pai[l[0]]) 
           printWin('r',l,r);
        else printWin('l',l,r);
        return 0;
    }
    else
        cout<<"ERROR";
    

    return 0;
}
