#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n, b, sets = 0;
        cin >> n;
        vector<int> ans(n);
        unordered_map<int, vector<int>> seen;
        for (int i = 1; i <= n; i++){
            cin >> b;
            if (seen.count(b)){
                seen[b].push_back(i);
                sets += 1;
            }else{
                seen[b] = {i};
            }
        }
    }
}