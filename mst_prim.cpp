#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100000;
vector<pii> adj[MAXN];

pii new_pair(int a, int b) {
    pii p; p.first = a; p.second = b; return p;
}

void mst_prim(int n, int st) {
    int vis[n];
    memset(vis, 0, sizeof(vis));

    priority_queue<pii> pq;
    vis[st] = 1;
    pq.push(new_pair(0, st));
    for(int i = 1; i <= n; i++) {
        pii v = pq.top();
        pq.pop();

        if(vis[v.second]) {i--; continue;}
        vis[v.second] = 1;

        for(auto e : adj[v.second]) {
            if(vis[e.second]) continue;
            pq.push(e);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    return 0;
}