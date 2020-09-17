#include <bits/stdc++.h>
using namespace std;
int main() {
    int w;
    cin >> w;
    string out;
    if(w % 2 == 0 && w > 2){
        out = "YES";
    }else{
        out = "NO";
    }
    cout << out;
}
