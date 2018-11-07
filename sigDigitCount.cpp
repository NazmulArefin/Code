/*
Write a program to count significant digits in a given number.
*/
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string s;
    while(cin >> s){
        int n = s.length();
        char m[n+1];
        strcpy(m, s.c_str());   // converting string to characters and copy to m

        bool afterNumber = true, decimal = false;
        int countSig = 0, zero = 0;

        for(int i = 0; i<n; i++){
            int currentValue = m[i]-'0'; // converting char to int

            if(m[i] == '.' && !decimal)
                decimal = true;

            /* counting zeros in between numbers and trailing zeros after decimal point.
               afterNumber will be false if zero occurs after non zro, e.g 440
               if zro occurs as last like "440" then it will false and last zro wont be significant.
            */
            if(countSig > 0 && currentValue == 0){
                if(afterNumber){
                    afterNumber = false;
                    zero++;
                }else{
                    zero++;
                }
            }

            /* counting non zeros */
            if(currentValue > 0){
                afterNumber = true;
                countSig++;
            }
        }

        if(decimal || afterNumber)
            countSig += zero;

        cout << countSig << endl;
    }
    return 0;
}










