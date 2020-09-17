#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, l;
    cin >> n >> l;
    vector<int> pos(n);
    for(int i = 0; i < n; i++){
        cin >> pos[i];
    }
    sort(pos.begin(), pos.end());

    //get max spacing between lamps
    int j = 0;
    int diff = 0;
    for(int i = 0; i < n; i++){
        diff = max(diff, pos[i] - pos[j]);
        j = i;
    }
    diff = max(diff, 2*max(pos[0], l - pos[n-1]));
    printf("%.10f\n", diff/2.);
}
