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

int dfs(int v, int prev) {
    //code

    for(auto i : adj[v]) {
        if(i == prev) continue;

        //code 

        dfs(i, v);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);



    return 0;
}