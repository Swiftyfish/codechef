#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> in(k);

    for (pair<int, int>& p : in){
        scanf("%d %d", &p.first, &p.second);
    }

    vector<int> dp(n), pref(n);
    dp[0] = pref[0] = 1;

    for (int i = 1; i < n; i++){
        for (pair<int, int> p : in){
            int L = max(0, i - p.second);
            int R = i - p.first;
            if (L <= R){
                dp[i] += pref[R];
                if (L >= 1) dp[i] -= pref[L-1];
                dp[i] %= mod;
                if(dp[i] < 0) dp[i] += mod;
            }
        }
        pref[i] = (pref[i - 1] + dp[i]) % mod; 
    }

    cout << dp[n-1];


}