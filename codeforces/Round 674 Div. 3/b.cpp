#include<bits/stdc++.h>
using namespace std;
int main() {
    int t, n, m;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n >> m;
        if (m&1){
            cout << "NO" << "\n";
            continue;
        }
        //need a symmetrical tile
        //and a pair of transpose tiles
        bool symm = false, pairs = false;
        vector<pair<vector<int>, vector<int>>> tiles(n);
        for(auto& p : tiles){
            int a, b, c, d;
            scanf("%d %d", a, b);
            scanf("%d %d", c, d);
            p.first = {a, b};
            p.second = {c, d};
            if (b == c) symm = true;
        }
        for (auto tile : tiles){
            
        }
    } 
}