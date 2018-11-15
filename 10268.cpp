/*
UVA 10268 using Hornor's rule (shortcut)

2
1 -4 1 6
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
    strToInt function convert a string line to int vector
    e.g. given string: 1 2 -3
         returned vector: 12-3
*/
vector<int> strToInt(string s){
    vector<int> c;
    bool flagMinus = false;
    for(auto x: s){
        if(x == ' ')
            continue;
        else{
            if(x == '-'){
                flagMinus = true;
                continue;
            }
            if(flagMinus){
                int k = x-'0';
                c.push_back(-k);
                flagMinus = false;
            }
            else{
                // char to int conversion and push to c
                c.push_back(x-'0');
            }
        }
    }
    return c;
}

// returns value of polynomial
int horner(vector<int> co, int x)
{
    int result = co[0];  // Initialize result

    // Evaluate value of polynomial using Horner's method
    for (int i=1; i<co.size(); i++)
        result = result*x + co.at(i);

    return result;
}

/*  derivative function convert a polynomial to its derivative
    e.g. given polynomial's coefficients:
        a3 = 2, a2 = 1, a1 = 4, a0 = 3;
    after derivation new polynomial's coefficients:
        a2 = 6, a1 = 2, a0 = 4;
*/
vector<int> derivative(vector<int> c)
{
    int coSize = c.size()-1;
    for(int i = 0; i < c.size(); i++){
        if(i != c.size()-1){
            c.at(i) = c.at(i)*coSize;
            coSize --;
        }else{
            c.pop_back();
        }
    }
    return c;
}

void calculatePoly(vector<string> inputLines){
    vector<int> c;  // Coefficient set
    int x;  // Value of x

    for(int i = 0;  i < inputLines.size(); i++){
        if(i%2 != 0){   // cos, first line contain value of x
            c = strToInt(inputLines.at(i));
            vector<int> co = derivative(c);
            cout << horner(co,x) << endl;
        }
        else{
            x = strToInt(inputLines.at(i)).at(0);
        }
    }
}

int main()
{
    string line;
    vector<string> inputLines;

    //getting multiple lines from user in console
    while(std::getline(cin, line)){
        inputLines.push_back(line);
        if(inputLines.size() %2 == 0){  //only two lines allowed for a test case.
            calculatePoly(inputLines);
            // after getting 2 lines and we send it for
            // calculation & clear the vector for next use.
            inputLines.clear();
        }
    }
    return 0;
}
