#include <bits/stdc++.h>
using namespace std;
int get_moves(vector<int> p){
    vector<int> d(p);
    for (int i = 0; i < p.size(); i++){
        if (i==0){
            d[i] = p[i + 1] - p[i];
        }
        d[i] = min(p[i] - p[i-1], p[i + 1] - p[i]);
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    vector<int> p(n);
    for (int i = 0; i < p.size(); i++){
        scanf("%d", &p[i]);
    }


}
