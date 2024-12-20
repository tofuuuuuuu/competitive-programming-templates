#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 1000006;
struct DSU{
    int p[MAXN];
    int sz[MAXN];

    void init(int n) {
        for(int i = 1; i <= n; i++) {
            p[i] = i;
            sz[i] = 1;
        }
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
};

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    return 0;
}