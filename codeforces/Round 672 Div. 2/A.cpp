#include<bits/stdc++.h>
using namespace std;

int get_swaps(int n, vector<int> a){
        long long threshold = n*(n - 1)/2 - 1;
        int swaps = 0;
        pair<int, int> positions[n];
        for (int i = 0; i < n; i++){
            positions[i].first = a[i];
            positions[i].second = i;
        }

        sort(positions, positions + n);
        for (int i = 0; i < n; i++){
            if (positions[i].first != a[i]){
                cout << "YES" << endl;
                return 0;
            }
        }
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++){
            if (visited[i] || positions[i].second == i){
                continue;
            }
            int cycles = 0;
            int j = 0;
            while (!visited[j]){
                visited[j] = 1;
                j = positions[j].second;
                cycles++;
            }

            if (cycles > 0){
                swaps += (cycles - 1);
                if (swaps > threshold){
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
        if (swaps <= threshold){
            cout << "YES" << endl;
        }
        return 0;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& p : a){
            cin >> p;
        }
        get_swaps(n, a);
    }
    return 0;
}
