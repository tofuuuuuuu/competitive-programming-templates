#include <bits/stdc++.h>
using namespace std;
#define ll long long

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T>
// using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
// Tree<ll> tr;

// #define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

// #define scanu(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
// char _;

const int MAXN = 200005;
const ll MOD = 1000000007;
const ll BFN = (ll)1e17;
//const int BFN = (int)2e9;
int n, q, a, b, qType; ll val;
vector<int> adj[MAXN];
int inTime[MAXN];
int outTime[MAXN];
int t = 1;

void dfs(int v, int prev) {
    inTime[v] = t;
    t++;
    for(int i : adj[v]) {
        if(i == prev) continue;
        dfs(i, v);
    }
    outTime[v] = t;
    t++;
}

void sol() {
    int rt;
    dfs(rt);
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}