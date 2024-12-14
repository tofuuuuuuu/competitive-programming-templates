#include <bits/stdc++.h>
using namespace std;
#define ll long long


const int MAXN = 200005;
const ll MOD = 1000000007;
//const ll BFN = (ll)1e17;
const int BFN = (int)2e9;

int n, st, q, x, a, b;
vector<int> adj[MAXN];

const int LOG = 21;
struct LCA {
    int lift[MAXN][LOG];
    int depth[MAXN];

    void dfs(int v, int prev) {
        for(int i : adj[v]) {
            if(i == prev) continue;
            depth[i] = depth[v] + 1;
            lift[i][0] = v;
            dfs(i, v);
        }
    }

    void precompute() {
        for(int k = 1; k < LOG; k++) {
            for(int i = 1; i <= n; i++) {
                lift[i][k] = lift[lift[i][k-1]][k-1];
            }
        }
    }

    int find(int a, int b) {
        if(depth[a] < depth[b]) swap(a, b);

        for(int k = LOG-1; k >= 0; k--) {
            if(depth[lift[a][k]] >= depth[b]) a = lift[a][k];
        }

        if(a == b) return a;

        for(int k = LOG-1; k >= 0; k--) {
            if(lift[a][k] != lift[b][k]) {
                a = lift[a][k];
                b = lift[b][k];
            }
        }

        return lift[a][0];
    }
} lca;

void sol() {
    st = 1;
    lca.lift[st][0] = 1;
    lca.depth[st] = 1;
    lca.dfs(st, st);
    lca.precompute();

    lca.find(a, b);
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}