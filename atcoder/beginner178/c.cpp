#include<bits/stdc++.h>
using namespace std;
int main() {
    int mod = 1e9 + 7;
    int n;
    cin >> n;
    if (n == 1){
        cout << 0;
        return 0;
    }
    n -= 2; //since we always need 0 and 9;
    int answer = 1;
    int x = 10;
    while (n > 0){
        if (n & 1) answer = (answer*x) % mod;
        n = n>>1;
        x = (x*x) % mod;
    }
    if (answer < 0){
        answer += mod;
    }
    cout << answer;
}