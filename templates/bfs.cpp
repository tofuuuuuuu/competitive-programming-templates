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

void bfs(int st) {
    int vis[MAXN];
    memset(vis, 0, sizeof(vis));

    queue<int> q;
    vis[st] = 1;
    q.push(st);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(auto i : adj[v]) {
            if(vis[i]) continue;

            //code

            vis[i] = 1;
            q.push(i);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    return 0;
}