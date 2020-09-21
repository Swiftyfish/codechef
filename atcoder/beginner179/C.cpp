#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, target;
    cin >> n;
    int count = 0;
    for (int i = 1; i < n; i++){
        target = n - i;
        vector<bool> seen(n, false);
        for (int j = 1; j*j <= target; j++){
            if (target % j == 0){
                if (!seen[target/j]){
                    if (target/j == j){
                        count += 1;
                    }else{
                        count += 2;
                    }
                    seen[target/j] = true;
                }
            }
        }
    }

    cout << count;
}