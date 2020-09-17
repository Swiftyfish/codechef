#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, c;
    cin >> n >> c;
    vector<int> coins(c);
    for(int i = 0; i < c; i++){
        scanf("%d", &coins[i]);
    }
    vector<vector<int>> dp(n+1);
    //  current sum then last elem
    dp[0][0] = 0;
    for (int i=1; i <= n; i++){
        for(int j = 0; j < c; j++){
            dp[i][j] = 1;
        }
    }
    int last = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < c; j++){
            if (coins[j] <= i & coins[j] >= last){
                dp[i][last] += dp[i - coins[j]][j];
                last = j;
            }
        }
    }
    int count = 0;
    cout << count;
    for(int i = 0; i < c; i++){
        count += dp[n][i];
    }
    cout << count;
}
