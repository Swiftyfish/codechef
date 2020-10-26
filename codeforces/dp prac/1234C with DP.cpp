#include<bits/stdc++.h>
using namespace std;
int main() {
    int q;
    cin >> q;

    //state is current available forms of square
    for (int i = 0; i < q; i++){
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        vector<pair<int, int>> types(n);
        int j = 0;
        for (pair<int, int>& p : types){
            p.first = s1[j] >= '3';
            p.second = s2[j] >= '3';
            j++;
        }

        bool exitted = false;
        int level = 0;
        for (int j = 0; j < n; j++){
            int top = types[j].first;
            int bottom = types[j].second;
            int pipeLevel = (level ? bottom : top);

            if (top && bottom) level ^= 1; //change level;
            else if (!pipeLevel) continue;
            else {
                cout << "NO" << endl;
                exitted = true;
                break;
            }

        }
        if (!exitted){
            cout << (level ? "YES" : "NO") << endl;
        }

    }
}