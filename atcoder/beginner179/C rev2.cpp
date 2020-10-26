#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int answer = 0;
    cin >> n;
    for  (int a = 1; a <= n; ++a){
        for (int i = 1; i * a < n; ++i){
            answer++;
        }
    }
    cout << answer << endl;
}