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
        bool exitted = false;
        int count = 0;
        //top left and bottom right pipe check
        for (int j = 0; j < n; j++){
            if((s1[j] < '3') != (s2[j] < '3')){
                if ((s1[j] >= '3' && count) || s2[j] >= '3' && !count){
                    continue;
                }
                cout << "NO" << endl;
                exitted = true;
                break;
            }
            if (s1[j] >= '3') count ^= 1;
        }
        if (!exitted) {
             if (count) cout << "YES" << endl;
             else cout << "NO" << endl;
    }
    }
}