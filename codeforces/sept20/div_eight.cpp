#include <bits/stdc++.h>
using namespace std;
int main(){
    int num;
    cin >> num;
    string n = to_string(num);

    if (num % 8 == 0){
        cout << "YES" << "\n" << n;
    }

    vector<int> dp;
    dp[num] = num % 8;
    for (int i = 0; i < n.length(); i++){
        
    }
}
