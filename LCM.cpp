#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int LCM(int a, int b){
    int c = 0;
    int m = (a>b)?a:b;
    while(1){
        if(m%a == 0  && m%b == 0)
        {
            c = m;
            break;
        }
        else{
            m++;
        }
    }
    return c;
}
int main(){
    int a , b, c;
    while(cin >> a >> b){
        cout << "LCM of " << a << ","<< b << ": " << LCM(a,b) << endl;
    }
    return 0;
}
