#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> c(n);
        for (auto& p : c){
            cin >> p;
        }
        sort(c.begin(), c.end(), greater<int>());
        int a = 0, b = 0;
        int& minList = a;
        for (int j : c){
            if (a > b){
                b += j;
            }else{
                a += j;
            }
        }
        cout << max(a, b) << endl;
    }
}