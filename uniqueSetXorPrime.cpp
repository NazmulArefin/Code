/* Problem: unique set er xor prime hote hobe */
#include <bits/stdc++.h>
#include <cmath>
#include<set>
#include <sstream>
using namespace std;


vector<string> m;
bool isUnique(string a){
    vector<string>::iterator it;
    it = find(m.begin(),m.end(),a);
    if (it != m.end()) {
        return false;  //std::cout << "Found " << (*search) << '\n';
    } else {
        return true; //std::cout << "Not found\n";
    }
//return true;
}

bool prime(int a){
    if(a > 1){
        bool prime = true;
        for(int i = 2; i <= a/2; i++){
            if(a%i == 0){
                prime = false;
                break;
            }
        }
        return prime;
    }
    else
        return false;
}

vector<string> multiSetCombination(int n){
    std::stringstream ss;
    std::string out_string;
    int position;
    vector<string> a;
    vector<string> result;
    for(int i = 0; i<n;  i++){
//        cout << "Count: " << i+1 << endl;
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
            result.push_back(a[j]);
        }
    }
    return result;
}

bool findPrimUni(vector<int> a){
    int prev = -1;
    int result = 0;
    std::stringstream ss;
    for(int i = 0; i < a.size(); i++)
    {
        ss << a.at(i);

        if(prev == -1){
            prev = a[i];
        }
        else{
            prev = a[i]^prev;
        }
    }
    cout << ss.str() << " :";
    if(prime(prev)){
            cout << "prime " << prev ;
        if(isUnique(ss.str())){
            result ++;
            m.push_back(ss.str());
            cout << " unique ->" << ss.str() << endl;
        }
        else
            cout << ", not unique"<< endl;
    }else{
        cout << prev << " not" << endl;
    }
    return result;
}



vector<int> digits(string a){
    int b;
    stringstream last1(a);
    last1 >> b;
    vector<int> digit;
    int remainder;
    while(b > 0){
        remainder = b%10;
        digit.push_back(remainder);
        b /= 10;
    }
    return digit;
}

int primeXor(vector<int> a, int n) {
    vector<string> combinations = multiSetCombination(n);
//    cout << combinations.size() << endl;
//    for(int i = 0; i< combinations.size(); i++)
//        cout << combinations.at(i) << endl;
    int valid = 0;

    for(int i = 0; i < combinations.size(); i++){
        vector<int> dig = digits(combinations.at(i));
//        cout << dig.size() << endl;
        vector<int> sendCombElement;
        for(int j = 0; j < dig.size(); j++){
            sendCombElement.push_back(a.at(dig.at(j)-1));
        }
//        for(int k = 0; k < sendCombElement.size(); k++){
//            cout << sendCombElement.at(k) << " ";
//
//        }
//        cout << endl;
        valid += (findPrimUni(sendCombElement));
    }
    long int kaust = (pow(10,9)+7);
    return (valid % kaust);
}

int main(){
    int q,n;
    cin >> q;
    while(q > 0){
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];
        m.clear();
        int result = primeXor(a,n);
//        for (int i = 0; i < m.size(); i++)
//            cout << m.at(i) << endl;
        cout << result << endl;
        q--;
    }
}


