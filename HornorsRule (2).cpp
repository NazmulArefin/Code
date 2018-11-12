/*
Hornor's rule (shortcut)

2
1 -4 1 6
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// returns value of polynomial
int horner(vector<int> co, int x)
{
    int result = co[0];  // Initialize result

    // Evaluate value of polynomial using Horner's method
    for (int i=1; i<co.size(); i++)
        result = result*x + co.at(i);

    return result;
}


int main()
{
    ifstream ifile;
    ifile.open("file.txt");
    vector<int> co;
    vector<int> p;
    int s, x;
    bool isFirst = true;
    while (ifile >> s)
    {
        if(isFirst){
            x = s;
            isFirst = false;
        }
        else{
            co.push_back(s);
        }
    }
    cout << "Value of polynomial is " << horner(co, x);
    return 0;
}





