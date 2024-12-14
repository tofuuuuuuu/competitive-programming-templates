#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 200005;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n, m;
vector<int> adj[MAXN];
int sz[MAXN];
bool removed[MAXN];

void find_sz(int v, int prev) {
    sz[v] = 1;
    for(int i : adj[v]) {
        if(i == prev || removed[i]) continue;

        find_sz(i, v);
        sz[v] += sz[i]; 
    }
}

int find_centroid(int v, int prev, int nodeAmt) {
    for(int i : adj[v]) {
        if(i == prev || removed[i]) continue;

        if(2*sz[i] >= nodeAmt) {
            return find_centroid(i, v, nodeAmt);
        }
    }
    return v;
}

void decomp(int v) {
    find_sz(v, v);
    int stSize = sz[v];
    int centroid = find_centroid(v, v, stSize);

    //do stuff on centroid 

    removed[centroid] = true;
    for(int i : adj[centroid]) {
        if(removed[i]) continue;

        decomp(i);
    }
}

void sol() {   

}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    sol();

    return 0;
}