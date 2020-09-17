#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    vector<int> p(n);
    for(int i = 0; i < n; i ++){
        scanf("%d", &p[i]);
    }

    // state is left and right
    vector<vector<int>> dp(n);
    dp[0][n-1] = 0;
    for (int l = n - 1; l >= 0; l--){
        for(int r = l; r < n; r++){
            if (l + r <= n){
                dp[l][r] = max(dp[l + 1][r] + (l + r)*p[l], dp[l][r + 1] + (l + r)*p[r]);
            }
        }
    }

    int max_val = 0;
    for (vector<int> rs : dp){
        for (int rss : rs){
            max_val = max(max_val, rss);
        }
    }
    cout << max_val;
}
