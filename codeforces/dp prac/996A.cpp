#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> coins = {100, 20, 10, 5, 1};
    int count = 0;

    while (n > 0){
        for (int j : coins){
            if (j <= n){
                n -= j;
                count += 1;
                break;
            }
        }
    }

    cout << count;

}