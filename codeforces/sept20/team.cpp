#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int view;
    int problem_count;
    int count = 0;
    for(int i = 0; i < n; i++){
        problem_count = 0;
        for(int j = 0; j < 3; j++){
            cin >> view;
            problem_count += view;
        }
        if(problem_count >= 2){
            count++;
        }
    }
    cout << count;
}
