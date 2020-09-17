#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<string> names(2);
    cin >> names[0] >> names[1];
    vector<char> v = {'a', 'e', 'i', 'o', 'u'};

    int len;
    if(names[0].length() != names[1].length()){
        cout << "No";

    }else{
        len = names[0].length();
        int state, i = 0;
        while(state == 0 & i < len){
            state ^= count(v.begin(), v.end(), names[0][i]);
            state ^= count(v.begin(), v.end(), names[1][i]);
            i++;
        }
        cout << (state ? "No" : "Yes");
    }
}
