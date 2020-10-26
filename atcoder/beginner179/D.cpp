#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    set<int> S;
    int l, r;
    for (int i = 0; i < k; i++){
        cin >> l >> r;
        for (int j = l; j <= r; j++){
            S.insert(j);
        }
    }

    vector<long long> dp(n+1, 0);
    dp[1] = 1;
    for (int i = 0; i <= n; i++){
        for (int j : S){
            if (i - j > 0){ 
                dp[i] += dp[i - j];
            }
        }
    }

    cout << (dp[n] % 998244353);


}