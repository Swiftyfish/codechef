#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> poison_pairs(m);
    for (auto& i : poison_pairs) cin >> i.first; //allergic
    for (auto& i : poison_pairs) cin >> i.second; //poisonous
    vector<pair<int, int>> tree(2*n, {1, n});

    for (int i = 0; i < m; i++){
        int a = poison_pairs[i].first, p = poison_pairs[i].second;
        auto tree_1 = &tree[n + a - 1].first;
        auto tree_2 = &tree[n + a - 1].second;
        if (p < a){
            *tree_1 = ((*tree_1) ? max(*tree_1, p) + 1 : p);
        }else{
            *tree_2 = ((*tree_2) ? min(*tree_2, p) - 1 : p);
        }
    }
    for (int i = n - 1; i >= 0; i--){
        if (tree[i<<1].second >= tree[i<<1 | 1].first || !tree[i<<1].first|| !tree[i<<1 | 1].first){
            tree[i] = {NULL, NULL};
        }else{
            tree[i].first = max(tree[i<<1].first, tree[i<<1 |1].first);
            tree[i].second = min(tree[i<<1].second, tree[i<<1 |1].second);
        }
    }
    //need some way to restrict indices to contain all points.
    int count = 0;
    for (auto p : tree){
        count += (p.first != 0);
    }
    cout << count;
}