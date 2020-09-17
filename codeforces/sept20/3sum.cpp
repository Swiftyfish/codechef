#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());

    vector<int> ans;
    int subtarget, k;
    for (int i = 0; i < n; i++){
        subtarget = t - a[i];
        k = n-1;
        for (int j = 0; j < n; j++){
            if(j < k){
                if (a[j] + a[k] > subtarget || k == i){k--;}
                if (a[j] + a[k] < subtarget || j == i){j++;}
                if (a[j] + a[k] == subtarget){
                    ans = {a[j], a[k], a[i]};
                }
            }
        }
    }
    if (!ans.empty()){
        for (int i = 0; i < 3; i++){
            cout << ans[i] << "\n";
        }
    }else{
        cout << -1 << "\n";
    }

}
