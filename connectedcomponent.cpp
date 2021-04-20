#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
int n, m, u, v;
vector<int> adj[MAX];
vector<bool> visited(MAX, false);
void dfs(int start) {
    stack<int> S;
    S.push(start);
    visited[start] = true;
    while(!S.empty()) {
        int u = S.top();
        S.pop();
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if(!visited[v]) {
                visited[v] = true;
                S.push(v);
            }
        }
    }
}

int main() {

    int ans = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int k = 1;
    while(k <= n) {
        if(!visited[k]) {
            dfs(k);
            ans++;
        }
        k++;
    }
    cout << ans;
}
