#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 10;
vector<int> adj[MAXN];
int vis[MAXN];
int dfsT[MAXN];
int lowLink[MAXN];
int isAP[MAXN];
int isBridge[MAXN][MAXN];

void tarjan_dfs(int v, int prev) {
    vis[v] = true;
    dfsT[v] = dfsT[prev] + 1;
    lowLink[v] = dfsT[v];
    for(auto i : adj[v]) {
        if(i == prev) continue;
        if(!vis[i])  {
            tarjan_dfs(i, v);
            if(dfsT[v] <= lowLink[i]) {
                isAP[v] = 1;
            }
            else if(dfsT[v] < lowLink[i]) {
                isBridge[v][i] = 1;
            }
            lowLink[v] = min(lowLink[v], lowLink[i]);
        }
        else {
            lowLink[v] = min(lowLink[v], dfsT[i]);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        vis[i] = 0;
        dfsT[i] = 0;
        lowLink[i] = 0;
        isAP[i] = 1;
    }
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    tarjan_dfs(1, 1);
    return 0;
}