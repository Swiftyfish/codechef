#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int d;
        cin >> d;
        double low = 0, high = d, answer = 0;
        for (int reps = 0; reps < 40; reps++){
            double mid = sqrt(low * high);
            if (mid * (d - mid) > d) high = mid;
            else low = mid;
        }
        cout << low;
    }
}