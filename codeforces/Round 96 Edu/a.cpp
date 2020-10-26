#include<bits/stdc++.h>
using namespace std;
int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        if (n % 3 == 0) cout << n/5 << " 0 0" << endl;
        else if (n % 5 == 0) cout << "0 " << n/5 << " 0" << endl;
        else if (n % 7 == 0) cout << "0 0 " << n/7 << endl;
        else{
            vector<vector<int>> num(n+1, {-1});
            num[3] = {1, 0, 0};
            num[5] = {0, 1, 0};
            num[7] = {0, 0, 1};
            vector<int>* last3 = &num[5];
            vector<int>* last5 = &num[3];
            vector<int>* last7 = &num[1];
            for (int j = 8; j <= n; j++){
                if ((*last3)[0] != -1){
                    num[j] = *last3;
                    num[j][0]++;
                }else if ((*last5)[0] != -1){
                    num[j] = *last5;
                    num[j][1]++;
                }else if ((*last7)[0] != 1){
                    num[j] = *last7;
                    num[j][2]++;
                }
                last3++;
                last5++;
                last7++;
            }
            if (num[n+1][0] == -1) cout << -1 << endl;
            else{
                for (auto p : num[n+1]) cout << p << " ";
                cout << endl;
            }
            }
    } 
}