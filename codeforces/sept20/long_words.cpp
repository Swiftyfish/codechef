#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int len;
    string word;
    vector<string> words(n);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> word;
        len = word.length();
        if(len > 10){
            cout <<  word.front() + to_string(len - 2) + word.back();
        }else{
            cout << word;
        }
        cout << endl;
    }
}
