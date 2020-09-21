#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int count = 0;
    vector<int> check(n);
    bool bool_check;
    int d1, d2;
    bool_check = false;
    for (int i = 0; i < n; i++){
        scanf("%d %d", &d1, &d2);
        check[i] = (d1 == d2);
    }
    for (int i = 0; i < n; i++){
        if (check[i]){
            count++;
        }else{
            count = 0;
        }
        if (count == 3){
            bool_check = true;
        }
    }

    cout << ((bool_check) ? "Yes" : "No");
}