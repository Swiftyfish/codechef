#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>> graph, int node, int target, vector<int>& answer){
    answer.push_back(node);
    if (node == target) return true;
    for (auto child : graph[node]){
        if (dfs(graph, child, target, answer)) return true;
    }
    return false;
}

vector<int> bfs(const vector<vector<int>>& graph, int node, int target){
    vector<int> answer;
    vector<bool> visited;
    stack<int> next;
    for (int i = 0; i < graph.size(); i++){
        visited[i] = false;
    }
    visited[node] = true;
    next.push(node);
    while(!next.empty()){
        node = next.top();
        answer.push_back(node);
        cout << node << ' ';
        next.pop();

        for (auto i : graph[node]){
            if (!visited[i]){
                visited[i] = true;
                next.push(i);
            }
        }
    }

    return answer;
}
void bfs2(vector<vector<int>> adj, int s, int target, vector<int>& answer){
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()){
        s = q.front();
        q.pop();
        answer.push_back(s);
        if (!visited[target]){
        for (auto i : adj[s]){
            if (!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
        }
    }
}

int main(){
    vector<vector<int>> graph = {{1, 2}, {3}, {}, {}};
    for (int i : {0, 1, 2, 3}){
    vector<int> answer = {};
    dfs(graph, 0, i, answer);
    for (auto p : answer) cout << p << ' ';
    cout << endl;
    }

    for (int i : {0, 1, 2, 3}){
    vector<int> answer = {};
    bfs2(graph, 0, i, answer);
    for (auto p : answer) cout << p << ' ';
    cout << endl;
    }

   
    

}
