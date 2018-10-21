#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int srv(int n, int m){
    int k = (abs(n) < abs(m)) ? abs(n) : abs(m);
    int a = 0, b = 0;
    while(k>0){
        if(n%k ==0 && m%k==0){
            a = (n/k); b = (m/k);
            break;
        }
        else
            k--;
    }
    cout << "Katakati of " << n << "/"<< m << " = " << a << "/" << b << endl;
}
int main(){
    int a , b;
    cout << "Enter rational values: " << endl;
    while(cin >> a >> b){
        srv(a,b);
    }
    return 0;
}
