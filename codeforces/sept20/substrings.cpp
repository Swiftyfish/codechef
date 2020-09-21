#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    vector<int> used(s.length(), 0);
    bool AB, BA = false;
    for (int i = 0; i < s.length(); i++){
        if (AB && BA){
            break;
        }
        if (s[i] == 'A'){
            if(i > 0 && !BA && !used[i - 1]){
                BA = (s[i - 1] == 'B');
                used[i], used[i - 1] = BA;
            }else{
                if(i < s.length() - 1 && !AB && !used[i + 1]){
                    AB = (s[i + 1] == 'B');
                    used[i], used[i + 1] = AB;
                }
            }
        }
    }
    cout << ((AB && BA) ? "YES" : "NO");
}


