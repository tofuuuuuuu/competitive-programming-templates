#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 1000005;
const ll MOD = 1000000007;

struct Segtree {
    ll a[MAXN];
    ll seg[4*MAXN];
    ll lazy[4*MAXN];

    void pushup(int cur) {
        seg[cur] = (seg[2*cur] + seg[2*cur+1]) % MOD;
    }

    void pushdown(int cur, int l, int r){
        if(lazy[cur] == 0) return;

        seg[cur] = (seg[cur] + (r-l+1)*lazy[cur]) % MOD;
        if(l != r){
            lazy[2*cur] = (lazy[2*cur] + lazy[cur]) % MOD;
            lazy[2*cur+1] = (lazy[2*cur+1] + lazy[cur]) % MOD;
        }
        lazy[cur] = 0;
    }

    void construct(int cur, int l, int r) {
        if(l == r) {
            seg[cur] = a[l];
            return;
        }

        int m = (l+r)/2;
        construct(cur*2, l, m);
        construct(cur*2+1, m+1, r);
        pushup(cur);
    } 

    void update(int cur, int l, int r, int ql, int qr, int val) {
        pushdown(cur, l, r);
        if(r < ql || qr < l) return;
        if(ql <= l && r <= qr) {
            lazy[cur] = val;
            pushdown(cur, l, r);
            return;
        }

        int m = (l+r)/2;
        update(2*cur, l, m, ql, qr, val);
        update(2*cur+1, m+1, r, ql, qr, val);
        pushup(cur);
    }

    ll query(int cur, int l, int r, int ql, int qr) {
        pushdown(cur, l, r);
        if(r < ql || qr < l) return 0;
        if(ql <= l && r <= qr) {
            return seg[cur];
        }

        int m = (l+r)/2;
        return (query(2*cur, l, m, ql, qr) + query(2*cur+1, m+1, r, ql, qr)) % MOD;
    }
};

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    return 0;
}