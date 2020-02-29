#include<bits/stdc++.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<sstream>
#include<set>
#include<queue>
#define fin freopen("test.TXT","r",stdin)
#define loop(x, n) for(int x = 0; x < n; ++ x)
#define loopi(x, n) for(auto x = n.begin(); x != n.end(); x++)
#define dbg(x) cerr << #x << ": " << x << endl

using namespace std;
typedef long long ll;
typedef string str;


bool isEpsilon(str s)
{
    loop(i,s.size())
    {
        if(s[i] == '~')
            return true;
    }
    return false;
}

str first(int i, vector<str> v, str s,vector<str> FV)
{

    if(s[0] <= 'Z' and s[0] >= 'A')
    {
        str ss = "";
        ss += s[0];
        if(s[1] == '\'')
            ss += '\'';
        auto it = find(v.begin(), v.end(), ss);
        if (it != v.end())
        {
            int pos = it - v.begin();
            if(FV.at(pos) != "")
            {
                FV[i] += FV[pos];
                if(isEpsilon(FV[pos]))
                {
                    str sub = "";
                    for(int k = 1; k < s.size(); k++)
                    {
                        if(s[k] == '|')
                            break;
                        else
                            sub += s[k];
                    }
                    FV[i] = first(i,v,sub,FV);
                }
            }
        }
    }
    else
        FV[i] += s[0];

    str sub = "";
    for(int j = i; j < s.size(); j++)
    {
        if(s[j] == '|')
        {
            sub = s.substr(j+1);
            break;
        }
    }
    if(sub != "")
        FV[i] = first(i,v,sub,FV);

    return FV[i];
}

string removeSpace(str s)
{
    str s1;
    loop(i,s.size())
    {
        if(!isspace(s[i]))
            s1 += s[i];
    }
    return s1;
}

int main()
{
    fin;
    int t;
    while(cin >> t)
    {

        vector<str> v(t);
        vector<str> v1(t);
        vector<str> FV(t);
        loop(i,t)
        {
            str s;
            cin >> s;
            loop(j,s.size())
            {
                if(j < 2 and s[j] != '-')
                    v[i] += s[j];
                else if(s[j] == '-' or s[j] == '>')
                    continue;
                else
                    v1[i] += s[j];
            }
        }
        reverse(v.begin(),v.end());
        reverse(v1.begin(),v1.end());
        loop(i,t)
        {
            FV[i] = first(i,v,v1[i],FV);
        }
        vector<set<char>> v2;
        loop(i,FV.size())
        {
            set<char> st;
            str st1 = FV[i];

            loop(j,st1.size())
            {
                if(st1[j] != ' ')
                    st.insert(st1[j]);
            }

            v2.push_back(st);
        }
        reverse(v2.begin(), v2.end());
        int c = 0;
        loop(i,v2.size())
        {
            c++;
            cout << c << ". {";
            bool l = 0;
            loopi(j,v2.at(i))
                cout << *j;
            cout << "}" << endl;
        }
        cout  << endl;
    }

    return 0;
}
