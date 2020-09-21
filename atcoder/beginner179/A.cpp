#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    char c = s.back();
    if (c == 's'){
        s += "es";
    }
    else{
        s += "s";
    }
    cout << s;
}