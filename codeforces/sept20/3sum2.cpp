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
        int j = 0;
        int k = n-1;
        string s;
        while (j < k){
            if (a[j] + a[k] > subtarget || k == i){
                k--;
            }
            if (a[j] + a[k] < subtarget || j == i){
                j++;
            }
            else{
                cout << a[i] << "\n" << a[j] << "\n" << a[k];
            }
        }
    }
    cout << -1 << "\n";

}
