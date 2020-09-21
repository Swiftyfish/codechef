#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> l(k);
    vector<int> r(k);

    for (int i = 0; i < k; i++){
        scanf("%d %d", &l[i], &r[i]);
    }

    vector<long long> dp(n+1, 0);
    vector<long long> pre(n+1, 0);
    dp[1] = 1;
    pre[1] = 1;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j < k; j++){
            int l1 = i - l[j], r1 = i - r[j];
            int left = min(l1, r1) - 1, right = max(l1, r1);
            int k = 
            pre[i] = pre[i - 1] + dp[i];
        }
    }

    cout << (dp[n] % 998244353);


}