#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, c;
    cin >> n >> c;
    vector<int> coins(c);
    for(int i = 0; i < c; i++){
        scanf("%d", &coins[i]);
    }
    vector<int> dp(n+1);
    dp[0] = 0;
    for (int i=1; i <= n; i++){
        dp[i] = 1e6;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < c; j++){
            if (coins[j] <= i){
                dp[i] = min(dp[i], dp[i  - coins[j]] + 1);
            }
        }
    }

    cout << dp[n];
}
