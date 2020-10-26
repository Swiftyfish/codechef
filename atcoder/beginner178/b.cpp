#include<bits/stdc++.h>
using namespace std;
int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long max_out = -1e18;
    max_out = max(max_out, a*c);
    max_out = max(max_out, b*c);
    max_out = max(max_out, b*d);
    max_out = max(max_out, a*d);
    cout << max_out;

}