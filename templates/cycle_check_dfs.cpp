#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 1005;
vector<int> adj[MAXN];
int onStack[MAXN];
int vis[MAXN];

int dfs(int v, int prev) {
    if(onStack[v]) return 1;
    if(vis[v]) return 0;

    onStack[v] = 1;
    vis[v] = 1;
    for(int i : adj[v]) {
        if(i == prev) continue;
        if(dfs(i, v)) return 1;
    }
    onStack[v] = 0;
    return 0;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(vis, 0, sizeof(vis));
    memset(onStack, 0, sizeof(onStack));
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        if(dfs(i, i)) {
            ans = 1; break;
        }
    }

    if(ans) cout << "CYCLE" << "\n";
    else cout << "NO CYCLE" << "\n";

    return 0;
}