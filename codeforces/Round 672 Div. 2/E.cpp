#include<bits/stdc++.h>
using namespace std;
int get_protection(int n, vector<int> a){
    vector<int> groups;
    bool skip = true;
    int count = 0;
    for (int i : a){
        while(i == 1 && skip){
            continue; //removes leading 1's
        }
        skip = false;
        if (i == 0){
            count++;
        }else if (count){
            groups.push_back(count);
            count = 0;
        }
    }

    if(count) groups.push_back(count);
    int pre = groups[0], protection = 0;
    for (int i = 1; i < groups.size(); i++){
        protection += pre * groups[i];
        pre += groups[i];
    }
    return protection;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), s, ns;
    for (int& p : a){
        cin >> p;
    }
    for (int i = 0; i < n; i++){
        if (a[i] == 1) s.push_back(i);
        else ns.push_back(i);
    }

    int max_orders = n*(n - 1)/2;
    vector<int> dp(max_orders + 1, 0);
    cout << get_protection(n, a) << endl;

    // want to greedily change state where protection improves
}