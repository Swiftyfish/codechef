#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& p : a){
        cin >> p;
    }
    int l = 0, r = n - 1;
    int ans = 0;
    while (l <= r){
        int mid = (l + r)/2;
        if (a[mid] == k){
            cout << mid;
        }else if (a[mid] > k) r = mid - 1;
        else l = mid + 1;
    }
    return 0;
}