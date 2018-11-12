/*
Hornor's rule (by the system of book)

2
1 -4 1 6
*/
#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

int main()
{
    ifstream ifile;
    ifile.open("file.txt");
    vector<int> a;
    vector<int> p;
    int s, n;
    bool isFirst = true;
    while (ifile >> s)
    {
        if(isFirst){
            n = s;
            isFirst = false;
        }
        else{
            a.push_back(s);
        }
    }


    for(int k = 0; k < a.size(); k++){
        if(k == 0){
            p.push_back(a.at(k));
        }
        else{
//                cout << p.at(k-1) << "*" << n <<"+" << a.at(k) << endl;
            p.push_back((p.at(k-1))*n + a.at(k));
        }

    }

    int pSize = p.size()-1;
    for(int k = 0; k< p.size(); k++){
        cout  << "p " << pSize << ": " << p[k] << endl;
        pSize--;
    }

//    stringstream ss;
//    string str;
//    getline(cin, str);
//    replace( str.begin(), str.end(), ',', ' ');
//    ss << str;
//
//    vector<int> newC;
//    int x = 0;
//    while (ss >> x)
//    {
//        newC.push_back(x);
////        cout << x << endl;
//    }
//
//    for(int i = 0; i < newC.size(); i++){
//        cout << newC.at(i);
//    }
}
