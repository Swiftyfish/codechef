#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> coord(n);
    for (auto& p : coord){
        scanf("%d %d", p.first, p.second);
    }
    // end trees can be cut to left and right respectively, starting count is 2
    vector<vector<int>> dp(n+1, {-1, -1, -1}); //state is given by direction last tree was cut 0=left, 1=not, 2=right
    dp[0][0] = 1;
    for (int i = 1; i < n; i++){

    }


}