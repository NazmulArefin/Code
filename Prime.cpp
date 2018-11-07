#include <bits/stdc++.h>
#include <cmath>
using namespace std;
void main(){
    int a;
    cin >> a;
    bool prime = true;
    for(int i = 2; i <= a/2; i++){
        if(a%i == 0){
            prime = false;
            break;
        }
    }
    if(prime == true)
        cout << "prime" << endl;
    else
        cout << "not prime" << endl;
}
