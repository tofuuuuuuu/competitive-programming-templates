#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 5005;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n;
ll dist[MAXN];

struct Edge {
    int v;
    ll w;

    Edge(int vertex, ll weight) {
        this->v = vertex;
        this->w = weight;
    }
};

class cmp {
public:
    bool operator() (Edge a, Edge b) {
        if(a.w == b.w) return a.v > b.v;
        return a.w > b.w;
    }
};

vector<Edge> adj[MAXN];
bool vis[MAXN];

void dijkstra(int st) {
    for(int i = 1; i <= n; i++) {
        dist[i] = BFN;
        vis[i] = false;
    }
    dist[st] = 0;
    priority_queue<Edge, vector<Edge>, cmp> q;
    q.emplace(Edge(st, 0));
    while(!q.empty()) {
        Edge e = q.top(); q.pop();
        if(vis[e.v]) continue;
        vis[e.v] = true;
        
        for(Edge i : adj[e.v]) {
            if(dist[i.v] > e.w + i.w) {
                dist[i.v] = e.w + i.w;
                q.emplace(Edge(i.v, dist[i.v]));
            }
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    return 0;
}