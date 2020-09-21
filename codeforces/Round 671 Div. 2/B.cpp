#include <bits/stdc++.h>
using namespace std;

int bin_search(int x){
    int l = 0;
    int r = x;
    int ans = 0;

    while (l <= r){
        int mid = (l + (r - 1)) / 2;

        if ((mid*(mid + 1)/2) > x){
            ans = mid;
            r = mid - 1;

        }else{
            l = mid + 1;
        }
    }
    return ans ;
}

int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        int max = bin_search(x); //search for last n where sum 1...N does not exceed x
        cout << max;
    }
}