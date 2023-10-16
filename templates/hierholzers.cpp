#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

struct Edge {
    int v;
    int idx;

    Edge(int vertex, int idx) {
        this->v = vertex;
        this->idx = idx;
    }
};

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<Edge> adj[n+1];
    int deg[n+1];
    bool removed[m+1];
    memset(deg, 0, sizeof(deg));
    memset(removed, 0, sizeof(removed));
    for(int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        deg[a]++; deg[b]++;
        adj[a].push_back(Edge(b, i)); adj[b].push_back(Edge(a, i));
    }
    
    vector<int> ans;
    int st = 1;
    stack<int> s;
    s.emplace(st);
    while(!s.empty()) {
        int v = s.top(); 
        if(deg[v] == 0) {
            ans.push_back(v);
            s.pop();
        }
        else {
            for(Edge e : adj[v]) {
                if(removed[e.idx]) continue;
                removed[e.idx] = true;
                deg[v]--; deg[e.v]--;
                s.emplace(e.v);
            }
        }
    }   

    return 0;
}