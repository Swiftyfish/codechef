#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& i: a){
        cin >> i;
    }
    
    if (n == 1){
        cout << 1;
        return 0;
    }
    int count = 1, max_val = a[0], max_count = 0;
    for (int i = 1; i < n; i++){
        if (a[i] > max_val){
            count += 1;
        }else{
            count = 1;
        }
        max_val = a[i];
        max_count = max(count, max_count);
    }

    cout << max_count;

}