#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<string> names(2);
    cin >> names[0] >> names[1];
    vector<int> v = {0, 4, 8, 14, 20};
    vector<int> chars(26);
    
    int len;
    if(names[0].length() != names[1].length()){
        cout << "No";

    }else{
        len = names[0].length();
        for(int i = 0; i < 26; i++){
            chars[i] = count(v.begin(), v.end(), i);
        }
        bool same = false;
        vector<int> char_num(2);
        for(int i = 0; i < len; i++){
            for(int j = 0; j < 2; j++){
                char_num[j] = chars[names[j][i] - 'a'];
            }
            if(char_num[0] != char_num[1]){
                same = true;
                cout << "No";
                break;
            }
        }
        if(!same){
            cout << "Yes";
        }
    }
}
