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



//vector<str>
str first(int i, vector<str> v, str s,vector<str> FV)
{
//    loop(i,t)
//    {
//        dbg(v1[i]);
//        str s = v1[i];
        if(s[0] <= 'Z' and s[0] >= 'A')
        {
            str ss = "";
            ss += s[0];
//            dbg(s[0]);
//            dbg(ss);
            if(s[1] == '\'')
                ss += '\'';
//            dbg(ss);
            auto it = find(v.begin(), v.end(), ss);
            if (it != v.end())
            {
                int pos = it - v.begin();
                if(FV.at(pos) != ""){
                    FV[i] += FV[pos];
                }
//                dbg(FV[i]);
//                dbg(pos);
            }
        }
        else
        {
//            dbg(s[0]);
            FV[i] += s[0];
//            dbg(FV[i]);
        }

        str sub = "";
        for(int j = i; j < s.size(); j++)
        {
            if(s[j] == '|')
            {
                sub = s.substr(j+1);
//                dbg(sub);
                break;
            }
        }
        if(sub != "")
            FV[i] = first(i,v,sub,FV);

//    }
//    loop(i,FV.size())
//    {
//        cout << i << ":" << FV.at(i) << endl;
//    }
//    dbg(FV[i]);
    return FV[i];
}

int main()
{
    fin;
    int t;
    cin >> t;

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
            {
                v[i] += s[j];
            }
            else if(s[j] == '-' or s[j] == '>')
            {
                continue;
            }
            else
            {
                v1[i] += s[j];
            }
        }
    }
    reverse(v.begin(),v.end());
    reverse(v1.begin(),v1.end());
    loop(i,t)
    {
        FV[i] = first(i,v,v1[i],FV);
    }
    loop(i,FV.size())
    {
        cout << i << ":" << FV.at(i) << endl;
    }

//    loop(i,t)
//        cout << v[i] << " ";
//    cout << endl;
//    loop(i,t)
//        cout << v1[i] << " ";



    return 0;
}





