#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
int n, m;

struct Edge {
    int a, b, w;

    Edge(int a, int b, int weight) {
        this->a = a;
        this->b = b;
        this->w = weight;
    }
};

bool cmp(Edge &a, Edge &b) {
    return a.w < b.w;
}

struct DSU{
    int p[MAXN];
    int sz[MAXN];
    vector<Edge> edges;

    void init(int n) {
        for(int i = 1; i <= n; i++) {
            p[i] = i;
            sz[i] = 1;
        }
    }

    void addEdge(Edge e) {
        edges.push_back(e);
    }

    int find(int v) {
        if(p[v] != v) p[v] = find(p[v]);
        return p[v];
    }

    bool merge(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return false;
        
        if(sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }

    void mst() {
        sort(edges.begin(), edges.end(), cmp);
        for(auto e : edges){
            if(merge(e.a, e.b)) {
                //in mst
            }
        }
    }
};

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    return 0;
}