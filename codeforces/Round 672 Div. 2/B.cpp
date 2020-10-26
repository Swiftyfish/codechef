#include<bits/stdc++.h>
using namespace std;
int get_pairs(int n, vector<int> a){
    
}

int main() {
    int n, t;
    cin >> t;
    vector<int> a(n);
    for (int i = 0; i < t; i++){
        for (int& p : a){
            cin >> p;
        }
        get_pairs(n, a);
    }
}