#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100000;
const int BFN = 1000000000;
int n;
vector<pii> adj[MAXN]; //{idx, weight}
int dist[MAXN];

int bfs01() {
    for(int i = 1; i <= n; i++) {
        dist[i] = BFN;
    }

    deque<int> dq;
    dist[0] = 0;
    dq.push_front(0);
    while(!dq.empty()) {
        int v = dq.front(); dq.pop_front();

        for(pii i : adj[v]) {
            if(i.second == 0 && dist[i.first] > dist[v]) {
                dist[i.first] = dist[v];
                dq.push_front(i.first);
            }
            else if(dist[i.first] > dist[v] + 1) {
                dist[i.first] = dist[v] + 1;
                dq.push_back(i.first);
            }
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);



    return 0;
}