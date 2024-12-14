#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100000;
vector<int> adj[MAXN];
int c[MAXN];

bool check_dfs(int v, int prev) {
    bool res = true;
    for(auto i : adj[v]) {
        if(i == prev) continue; 
        if(c[i] == -1) {
            c[i] = c[v] ^ 1;
            if(!check_dfs(i, v)) return false;
        }
        else {
            if(!(c[i] ^ c[v])) return false;
        }
    }
    return res;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) c[i] = -1;
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << check_dfs(1, 1) << "\n";

    return 0;
}