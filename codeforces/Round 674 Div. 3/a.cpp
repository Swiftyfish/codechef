#include<bits/stdc++.h>
using namespace std;
int get_floor(int n, int x){
    if (n < 3){
        return 1;
    }
    int floor = (n - 2 - 1)/x + 2;
    return floor;
}
int main() {
    int t, n, x;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n >> x;
        cout << get_floor(n, x) << "\n";
    }
}