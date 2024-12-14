#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
vector<int> adj[MAXN];
vector<int> rev[MAXN];
int inDeg[MAXN];
int longest[MAXN];

void toposort(int n) {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(inDeg[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> order;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        order.push_back(v);
        
        for(int u : adj[v]) {
            inDeg[u]--;
            if(inDeg[u] == 0) {
                q.push(u);
            }
        }
    }

    for(int v : order) {
        for(int u : rev[v]) {
            longest[v] = max(longest[v], longest[u] + 1);
        } 
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev[b].push_back(a);
        inDeg[b]++;
    }

    toposort(n);

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, longest[i]);
    }
    cout << ans << "\n";

    return 0;
}