//    3
//    --------------------
//    Count: 1
//    1
//    12
//    13
//    123
//    Count: 2
//    2
//    23
//    Count: 3
//    3
#include <sstream>
#include<iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(){
    int n;
    std::stringstream ss;
    std::string out_string;
    int position;
    while(cin >> n){
        vector<string> a;
        for(int i = 0; i<n;  i++){
            cout << "Count: " << i+1 << endl;
            a.clear();
            position = 1;
            //---- int to string of (i+1)
            ss.str("");
            out_string = "";
            ss << i+1;
            out_string = ss.str();
            a.push_back(out_string); //--- inserting into vector a
            string last = out_string; //--- positional last value record
            int value = 0;
            int Lint = 0;      //--- to get last digit of "last" Lint used as variable
            bool isPosFirst = true;
            while(position <= n)
            {
                bool isValFirst = true;
                string last2 = "";
                if(isPosFirst){
                    value = i + 2;
                    isPosFirst = false;
                }else{
                    stringstream last1(last);
                    last1 >> Lint; // converting to int
                    Lint = Lint%10; // getting last digit of last
                    value = (Lint) + 1;
                }
                while(value <= n){
                    ss.str("");
                    ss << value;
                    string valueString = ss.str();
                    string new2 = "";
                    if(isValFirst){
                        isValFirst = false;
                        (new2.append(last)).append(valueString);
                        a.push_back(new2);
                        last2 = new2;
                    }else{
                        (new2.append(last)).append(valueString);
                        a.push_back(new2);
                    }
                    value++;
                }
                if(last2 != ""){
                    last = last2;
                    position++;
                }else{
                    break;
                }
            }
            for(int j = 0; j < a.size(); j++)
            {
                cout << a[j] << endl;
            }
        }
    }
    return 0;
}
