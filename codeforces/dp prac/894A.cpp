#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    vector<int> q, a;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == 'Q') q.push_back(i);
        else if (s[i] == 'A') a.push_back(i);
    }

    //For every Q, count the number of Qs on the right with an A inbetween.
    int count = 0, left, right;
    for (int i : a){
        left = 0;
        right = 0;
        for (int j : q){
            if (j < i) left++;
            else break;
        }
        right = q.size() - left;
        count += left*right;
    }

    cout << count;
}